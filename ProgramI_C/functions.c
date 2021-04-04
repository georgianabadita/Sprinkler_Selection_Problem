#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"


// If we want to desplay the width, length and no. of aspersors
void init (double lengthAux, double widthAux, int aspenTotalAux)
{
    length = lengthAux;
    width = widthAux;
    aspenTotal = aspenTotalAux;

    fprintf(file_out, "\n Rectagle: lengh = %.2f | width = %.2f \n Number of aspensors = %d \n", length, width, aspenTotal);

}


// Convert Aspen circle position and radius into Start and End Position on the middle axes of the rectangle
//   __________
//  |          |
//  |__S__P__E_|
//  |          |
//  |__________|
struct aspenPosition aspenToAspenPosition (struct aspen request)
{
    struct aspenPosition response;

    // Calculate half of the fully distance covered by the aspen in rectangle
    double halfDistanceStartEnd = sqrt( request.radius * request.radius - (width / 2) * (width / 2) );

    // We want the start to be positive
    response.start = request.position - halfDistanceStartEnd < 0 ? 0 : request.position - halfDistanceStartEnd;
    response.end = request.position + halfDistanceStartEnd;

    return response;
}

// Covert each element of aspenArray into aspenPosition and store it into aspenPositionArray
void arrayAspenToArrayAspenPosition ()
{
    for ( int index = 0; index < aspenTotal; index++ )
        {
        aspenPositionArray[index] = aspenToAspenPosition(aspenArray[index]);
    }
}

// If we want to display the position, the radius, the start or the end of each aspensors
void printAspenArrayAndAspenPositionArray ()
{
    for ( int index = 0; index < aspenTotal; index++ )
        {
       fprintf(file_out, " Aspen[%d]: position = %d | radius = %.2f | start = %.2f | end = %.2f\n", index, aspenArray[index].position, aspenArray[index].radius, aspenPositionArray[index].start, aspenPositionArray[index].end);
        }
}

// Sort aspenPositionArray by start property
void sortAspenPositionArrayByStart ()
{
    // Helpable variables for sorting
    double tmp;
    int tmpInt;

    for ( int index = 0; index < aspenTotal - 1; index++ )
        {
        for ( int index2 = index + 1; index2 < aspenTotal; index2++ )
        {
            if ( aspenPositionArray[index].start > aspenPositionArray[index2].start )
             {
                // Swap start values between elements
                tmp = aspenPositionArray[index].start;
                aspenPositionArray[index].start = aspenPositionArray[index2].start;
                aspenPositionArray[index2].start = tmp;

                // Swap end values between elements
                tmp = aspenPositionArray[index].end;
                aspenPositionArray[index].end = aspenPositionArray[index2].end;
                aspenPositionArray[index2].end = tmp;

                // Sort also aspenArray for displaying porpuses
                // Radius
                tmp = aspenArray[index].radius;
                aspenArray[index].radius = aspenArray[index2].radius;
                aspenArray[index2].radius = tmp;

                // Position
                tmpInt = aspenArray[index].position;
                aspenArray[index].position = aspenArray[index2].position;
                aspenArray[index2].position = tmpInt;
            }
        }
    }
}

// Find min number of aspens required to cover the entire rectangle
int minAspensNumber ()
{
    int minAspens = 1;
    int startIndex = 0;
    int index = 1;

    // Find aspenPosition to start by getting the aspenPosition that has the highest end value and start value 0
    while ( index < aspenTotal && aspenPositionArray[index].start == 0 )
        {
        // If next aspen has start 0 and end value higher than startIndex aspen end value
        if ( aspenPositionArray[index].start == 0 && aspenPositionArray[startIndex].end < aspenPositionArray[index].end )
            {
            startIndex = index;
            }

        index++;
       }

    int currentIndex = startIndex;

   //printf(" Aspen[%d]: position = %d | radius = %.2f | start = %.2f | end = %.2f\n", currentIndex, aspenArray[currentIndex].position, aspenArray[currentIndex].radius, aspenPositionArray[currentIndex].start, aspenPositionArray[currentIndex].end);

    // Go throw aspenPosition array until reach the end of the rectangle current aspend end value >= lengh or run out of aspenPosition elements
    while ( aspenPositionArray[currentIndex].end < length && currentIndex < aspenTotal )
        {
        // nextIndex is the next aspen used to cover the rectangle
        int nextIndex = currentIndex;
        int index = currentIndex + 1;

        while ( aspenPositionArray[index].start < aspenPositionArray[currentIndex].end  && index < aspenTotal )
            {
            if ( aspenPositionArray[index].start < aspenPositionArray[currentIndex].end && aspenPositionArray[nextIndex].end < aspenPositionArray[index].end )
             {
                nextIndex = index;
            }

            index++;
        }

        if ( currentIndex != nextIndex)
            {
            currentIndex = nextIndex;
            minAspens++;
     // printf(" Aspen[%d]: position = %d | radius = %.2f | start = %.2f | end = %.2f\n", currentIndex, aspenArray[currentIndex].position, aspenArray[currentIndex].radius, aspenPositionArray[currentIndex].start, aspenPositionArray[currentIndex].end);
        } else
         {
            break;
        }
    }

    // If not enough aspensors to cover the length, than return -1
    if ( aspenPositionArray[currentIndex].end < length )
        {
        minAspens = -1;
        }

    return minAspens;
}



