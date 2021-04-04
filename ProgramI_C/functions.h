#ifndef CODE_FUNCTIONS_H
#define CODE_FUNCTIONS_H
#define MAXN 10000000
FILE *file_out;

// Declaration of width, lengh of rectangle and the number of aspensors
int aspenTotal;
double width, length;

// Declaration of structures
struct aspen
{
   int position;
   double radius;
};

struct aspenPosition
{
   double start;
   double end;
};
// Declaration of the arrays which are of the  aspen type and aspenPosition type
struct aspen aspenArray[MAXN] ;
struct aspenPosition aspenPositionArray[MAXN];

void init (double length, double width,int aspenTotal);
struct aspenPosition aspenToAspenPosition (struct aspen request);
void arrayAspenToArrayAspenPosition ();
void printAspenArrayAndAspenPositionArray ();
void sortAspenPositionArrayByStart ();
int minAspensNumber ();


#endif // CODE_FUNCTIONS_H


