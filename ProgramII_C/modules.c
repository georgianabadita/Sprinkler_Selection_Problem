#include<stdio.h>
#include<stdlib.h>
#include "modules.h"

// Determine the interval on which the aspensors wet the grass, an interval located horizontally on the middle of the rectangle
//   ________________________
//  |                        |
//  |__Prim__Position__Final_|
//  |                        |
//  |________________________|
void starting(struct aspensor *properties, struct intervalAspen *coord)
{
    int index1, index2;
    for ( index1 = 0; index1 < noAspensors; index1++)
    {
        coord[index1].prim = properties[index1].position - properties[index1].radius;
        coord[index1].final = properties[index1].position + properties[index1].radius;
    }

}

// Eliminate the aspensors which have the same position, but the other has the radius bigger
// Auxiliary function for function <<duplicate>>
void eliminate(struct intervalAspen *coord, double position)
{
    int index;
    for(index = position; index < noAspensors - 1; index++)
    {
        coord[index].final = coord[index+1].final;
        coord[index].prim = coord[index+1].prim;
    }
}

// Eliminate the aspensor which are inside of other aspensor, and its radius is smaller then the other one
// The aspensors have the same position, but the different radius
void duplicate(struct aspensor *properties, struct intervalAspen *coord)
{
    double position;
    int index2;
    for( int index1 = 0; index1 < noAspensors - 1; index1++)
    {
        for(index2 = index1 + 1; index2 < noAspensors; index2++)
            // If have the same position
           {
            if(properties[index1].position == properties[index2].position)

                // Check which which have a longer operating range
            {
                if(coord[index1].final > coord[index2].final)
                {
                    eliminate(coord,index2);
                    noAspensors--;
                }

                else if(coord[index1].final < coord[index2].final)
                {
                    eliminate(coord,index1);
                    noAspensors--;

                }
            }
        }
    }

}

// Sort the aspensor by prim property
void sorting (struct intervalAspen *coord, struct aspensor *properties)
{
    int index1, index2;
    double tmp;
    double tmp2;
    for (index1 = 0; index1 < noAspensors - 1; index1++)
    {
        for (index2 = index1 + 1; index2 < noAspensors; index2++)
        {
            if(coord[index1].prim > coord[index2].prim)
            {
                // Swap prim and final values between elements
                tmp = coord[index1].prim;
                tmp2 = coord[index1].final;
                coord[index1].prim = coord[index2].prim;
                coord[index1].final = coord[index2].final;
                coord[index2].prim = tmp;
                coord[index2].final = tmp2;
            }

       }
    }
}

// Find the minimum number of aspens required to cover the entire rectangle using a Greedy Method
void minAspenGreedy (struct intervalAspen * coord)
{
    int index1;
    int minAspensors = 0;
    // Check if the aspensor has a range which is in the length of the rectangle
    if(coord[noAspensors - 1].final < length || coord[0].prim > 0)
    {
        fprintf(out, "No aspensors can be placed...");
        return ;
    }

    minAspensors++;

    for (index1 = 1; index1 < noAspensors;)
    {
        if(coord[index1].prim > coord[index1 - 1].final)
        {
            fprintf(out, "No aspensors can be placed...");
            return;
        }
        else
        {
            int index2 = index1 - 1;
            while(coord[index1].prim <= coord[index2].final )
            {

                index1++;
            }
            minAspensors++;

        }

    }
    fprintf(out, "You will need a min of  %d aspensors. ",minAspensors);

}

