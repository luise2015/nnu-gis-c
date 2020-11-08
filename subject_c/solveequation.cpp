#include <stdio.h>
#include <math.h>
double function(double x)
{
    return (2 * x * x * x - 4 * x * x + 3 * x - 6);
}

void solve(double min, double max)
{
    double x1 = min, x2 = max, x0;
    while (fabs(x1 - x2) >= 1e-6)
    {
        x0 = (x1 + x2) / 2;
        if (function(x0) * function(x1) < 0)
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
        }
    }
}

void solve()
{
    double x = 2, x0;
    while (fabs(x - x0) > 1e-5)
    {
        /* code */
        x0 = x;
        double f = function(x0);
        double f1 = 6 * x0 * x0 - 8 * x0 + 3;
        x = x0 - f / f1;
    }
    printf("%f", x);
}