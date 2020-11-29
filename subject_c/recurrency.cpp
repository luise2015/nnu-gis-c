#include <stdio.h>

//阶乘
//f(n)=n*f(n-1)
long multi(int n)
{
    if (n == 1)
        return 1;
    return n * multi(n - 1);
}

//求和
//f(n)=n+f(n-1)
long sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

//斐波那契
//f(n)=f(n-1)+f(n-2)
long fib(int n)
{
    if (n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void transform(int n)
{
    char a[100];
    int i = 0;
    while (n != 0)
    {
        a[i++] = n % 10;
        n = n / 10;
    }
    a[i] = '\0';
}

void transform(int n, char a[], int k)
{
    if (n == 0)
    {
        a[k] = '\0';
        for (int i = 0; i < k / 2; i++)
        {
            int tem = a[i];
            a[i] = a[k - 1 - i];
            a[k - 1 - i] = tem;
        }
        return;
    }
    a[k++] = n % 10;
    transform(n / 10, a, k);
}

//只有1个盘子，从a移动到c
//将n-1个盘子，借助c移动到b
//将a移动到c
//将b盘子，借助a移动到c;
void hannota(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("move %d from %c to %c", n, a, c);
    }
    else
    {
        hannota(n - 1, a, c, b);
        printf("move %d from %c to %c", n, a, c);
        hannota(n - 1, b, a, c);
    }
}

int main()
{
    getchar();
    char a[100];
    transform(13345, a, 0);
    printf("%s", a);
    return 0;
}