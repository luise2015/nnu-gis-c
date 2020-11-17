#include <stdio.h>
#include <math.h>
typedef struct{
    double x;
    double y;
}Point;

double calArea(Point points[])
{
    double x1=points[1].x-points[0].x;
    double y1=points[1].y-points[0].y;
    double x2=points[1].x-points[2].x;
    double y2=points[1].y-points[2].y;
    return abs(x1*y2-x2*y1)/2;
}

int main()
{
    Point points[3];
    points[0].x=0;
    points[0].y=0;
    points[1].x=0;
    points[1].y=10;
    points[2].x=10;
    points[2].y=0;
    double area=calArea(points);
    printf("%f",area);
    return 1;
}