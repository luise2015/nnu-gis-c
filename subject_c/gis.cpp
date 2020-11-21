#include <stdio.h>
#include <math.h>
typedef struct
{
    double x;
    double y;
} Point;

//计算三角形面积
//叉积a*b=0*i+0*j+(x1*y2-x2*y1)*k=c;
//|c|=|a|*|b|*sin(a,b)
//s=|c|/2;
double calTriangleArea(Point points[])
{
    double x1 = points[1].x - points[0].x;
    double y1 = points[1].y - points[0].y;
    double x2 = points[2].x - points[0].x;
    double y2 = points[2].y - points[0].y;
    return (x1 * y2 - x2 * y1) / 2;
}

//计算多边形面积
//顺时针围成的梯形面积之和
double calPolygonArea(Point points[], int size)
{
    double sum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        double height = points[i].y - points[i + 1].y;
        double x1 = points[i].x;
        double x2 = points[i + 1].x;
        sum += (x1 + x2) * height / 2;
    }
    return sum;
}

//两线段是否相交,先排除，后面判断是否在两侧
bool intersection(Point l1From, Point l1To, Point l2From, Point l2To)
{
    if (max(l1From.x, l1To.x) < min(l2From.x, l2To.x) || max(l1From.y, l1To.y) < min(l2From.y, l2To.y) || min(l1From.x, l1To.x) > max(l2From.x, l2To.x) || min(l1From.y, l1To.y) < max(l2From.y, l2To.y))
    {
        return false;
    }
    if (crossMultiplication(l1From, l2From, l2From, l2To) * crossMultiplication(l1To, l2From, l2From, l2To) > 0)
    {
        return false;
    }
    return true;
}

//点是否在多边形内，射线法
bool isInPolygon(Point point, Point points[], int n)
{
    int crossCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double y1 = points[i].y, y2 = points[i + 1].y;
        if (y1 > y2)
        {
            y1 = points[i + 1].y;
            y2 = points[i].y;
        }
        if (point.y >= y1 && point.y <= y2)
        {
            crossCount++;
        }
    }
    return crossCount % 2 == 0;
}

//计算多边形的重心，多边形顺时针
Point calCenter(Point points[], int n)
{
    double sumArea = 0, centerX = 0, centerY = 0;
    for (int i = 1; i < n - 1; i++)
    {
        Point trainPoints[3] = {points[0], points[i + 1], points[i]};
        double area = calTriangleArea(trainPoints);
        sumArea += area;
        centerX += (trainPoints[0].x + trainPoints[1].x + trainPoints[2].x) / 3 * area;
        centerY += (trainPoints[0].y + trainPoints[1].y + trainPoints[2].y) / 3 * area;
    }
    Point result;
    result.x = centerX / sumArea;
    result.y = centerY / sumArea;
    return result;
}

double max(double value1, double value2)
{
    return value1 > value2 ? value1 : value2;
}

double min(double value1, double value2)
{
    return value1 < value2 ? value1 : value2;
}

double crossMultiplication(Point point1, Point point2, Point point3, Point point4)
{
    double x1 = point2.x - point1.x;
    double y1 = point2.y - point1.y;
    double x2 = point4.x - point3.x;
    double y2 = point4.y - point3.y;
    return x1 * y2 - x2 * y1;
}

int main()
{
    return 1;
}