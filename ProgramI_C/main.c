#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "functions.h"
#define TESTS_NO 10
#define FILENAME_SIZE 40

int main()
{
    // Used for computing running time of a code block
    clock_t start, finish;
    double  duration;
    // Read all Problem 1 input files and put the result in the output files
    for (int tests_iterator = 1; tests_iterator <= TESTS_NO; tests_iterator++)
    {
        char tmp_name_in[FILENAME_SIZE];
        char tmp_name_out[FILENAME_SIZE];


        sprintf(tmp_name_in, "Data/data%din.txt", tests_iterator);
        sprintf(tmp_name_out, "Data/data%dout.txt", tests_iterator);

        FILE* file_in = fopen(tmp_name_in, "r");
        FILE * file_out = fopen(tmp_name_out, "w");

            if(!file_in || !file_out)
                {
              return -1;
               }


        fscanf(file_in, "%lf %lf %d",&length, &width, &aspenTotal); // We read from file the width, lengh and number of aspensors

        for(int index = 0; index < aspenTotal; index++)
        {
            // We read from input file the position and the radius for each aspensor
            fscanf(file_in, "%d %lf",&aspenArray[index].position, &aspenArray[index].radius);
        }
        // init(lengh, width, aspenTotal); // If we want to desplay the width, lengh and no. of aspersors
        arrayAspenToArrayAspenPosition();
        // printAspenArrayAndAspenPositionArray();
        //printf("\n Lets sort the aspens by start value. Shall we? \n");
        sortAspenPositionArrayByStart();
        // printAspenArrayAndAspenPositionArray();

        // Store time before running
        start = clock();

        // This for is only for execution time demonstration
        for (int x = 0; x < 50000000; x++);
             minAspensNumber();

        // Store time after measured block ends
        finish = clock();

        // Time of the algorithm which is displayed at the screen
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("Test %d duration: %.3fs \n", tests_iterator, duration);

        int minAspensRequired = minAspensNumber();

        if ( minAspensRequired != -1 )
        {
            fprintf(file_out, "\n You will need a min of  %d aspensors.\n", minAspensRequired);
        }
        else
        {
            fprintf(file_out, "\n There aren't enough aspensors to cover the entire length. Sorry :) \n");
        }

        fclose (file_in);
        fclose (file_out);


    }
    return 0;
}
