#ifndef CODE_F_H
#define CODE_F_H

// Declaration of structures
struct aspensor
{
    int position;
    double radius;
};

struct intervalAspen
{
    double prim;
    double final;
};

FILE *out;
// Declaration of the number of aspensors, width and lengh of the rectangle
int noAspensors;
double width, length;

void sorting (struct intervalAspen *coord, struct aspensor *properties);
void starting (struct aspensor *properties, struct intervalAspen *coord);
void greedy (struct intervalAspen *coord);
void elim (struct intervalAspen *coord, double position);
void duplicate(struct aspensor *properties, struct intervalAspen *coord);

#endif // CODE_F_H

