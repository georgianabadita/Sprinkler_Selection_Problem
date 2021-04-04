#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define maxim 10000
#define limit  100

// Function to generate a number that is >= min and <= max
double random_number(double min, double max)
{
  return ( (double)rand() * ( max - min ) ) / (double)RAND_MAX + min;
}
int main()
{
    srand(time(NULL));
    FILE *O;
    O = fopen("data_out.txt", "w");
    if(!O)
      {
       return -1;
      }

    double length, width;
    int noAspen;

    length = random_number(1 , maxim); // Value for length
     fprintf(O,"%.2f ", length);

    width = random_number(1, length/2); // Value for width
     fprintf(O,"%.2f ", width);

    noAspen = random_number(1, limit); // Value for number of aspensors
     fprintf(O, "%d\n", noAspen);

    for( int iter = 0; iter < noAspen; iter++)
       {
         fprintf(O," %.0f ", random_number(1, length)); // Generate and display the position
         fprintf(O," %.2f \n",random_number(1, length)); // Generate and display the radius
       }

    fclose(O);
    return 0;
}
