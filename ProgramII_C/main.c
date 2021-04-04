#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modules.h"
#define TESTS_NO 10
#define FILENAME_SIZE 40
int main()
{
    // Used for computing running time of a code block
    clock_t start, finish;
    double  duration;

    for (int tests_iterator = 1; tests_iterator <= TESTS_NO; tests_iterator++)
    {
        char tmp_name_in[FILENAME_SIZE];
        char tmp_name_out[FILENAME_SIZE];


        sprintf(tmp_name_in, "Date/date%din.txt", tests_iterator);
        sprintf(tmp_name_out, "Date/date%dout.txt", tests_iterator);

        FILE *in = fopen(tmp_name_in, "r");
       // FILE *
        out = fopen(tmp_name_out, "w");

            if(!in || !out)
                {
              return -1;
               }
   // FILE *in;
   // in = fopen("date_in.txt","r");
 //   out = fopen("date_out.txt", "w");

    // Read the witch, lengh and number of aspensors from file
    fscanf (in,"%lf %lf %d",  &length, &width, &noAspensors);

    // Declaration the type of properties and coordinates for the aspensors
    struct aspensor *properties;
    struct intervalAspen *coord;

    // Dynamic allocation of the necessary memory
    properties = (struct aspensor *)calloc (noAspensors, sizeof(struct aspensor));
    coord = (struct intervalAspen *)calloc(noAspensors, sizeof(struct intervalAspen));

    // Read the position and radius for each aspensor from file
    for (int index=0; index < noAspensors; index++)
        {
           fscanf(in,"%d %lf", &properties[index].position, &properties[index].radius);
        }
    // Calling functions
    starting (properties,coord);
    duplicate (properties,coord);
    sorting (coord,properties);

    // Display the beginning and end of the interval on which a aspensor operates
    for ( int index = 0 ; index < noAspensors; index++)
    {
        fprintf(out,"Prim: %.2lf si final: %.2lf\n\n", coord[index].prim, coord[index].final);

      }

    // Store time before running
    start = clock();

    // This for is only for execution time demonstration
    for (int x = 0; x < 50000000; x++);
         minAspenGreedy (coord);

    // Store time after measured block ends
    finish = clock();

    // Time of the algorithm which is displayed at the screen
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("Test %d duration: %.3fs \n", tests_iterator, duration);


    fclose(in);
    fclose(out);
    }
     return 0;
}



