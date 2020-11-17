#include <stdio.h>
#include <malloc.h>

//大数相乘，把一个数用数组存储，从头开始乘以另外一个数，余数为值，商作为下次累积
void multiply(int n, int m)
{
    int a[100], length = 0;
    while (m)
    {
        a[length++] = m % 10;
        m = m / 10;
    }
    for (int i = 0; i < length; i++)
    {
        m = a[i] * n + m;
        a[i] = m % 10;
        m = m / 10;
    }
    while (m)
    {
        a[length++] = m % 10;
        m = m / 10;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d", a[length - 1 - i]);
    }
}

void stepMultiply(int k)
{
    int a[100], digit = 1, temp = 0;
    a[0] = 1;
    for (int n = 2; n <= k; n++)
    {
        for (int i = 0; i < digit; i++)
        {
            temp = a[i] * n + temp;
            a[i] = temp % 10;
            temp = temp / 10;
        }
        while (temp)
        {
            a[digit++] = temp % 10;
            temp = temp / 10;
        }
    }
    for (int i = 0; i < digit; i++)
    {
        printf("%d", a[digit - 1 - i]);
    }
}

int main()
{
    stepMultiply(10);
    return 1;
}