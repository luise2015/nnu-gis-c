#include <stdio.h>
#include <malloc.h>

//题1，给定集合S={a,b,c,d,e}，请编写一段程序枚举出其中任意三元素构成的所有排列组合，如a,b,c,d,e等
void getRange()
{
    char array[] = "abcde";
    char a, b, c;
    for (int i = 0; i < 5; i++)
    {
        a = array[i];
        for (int j = 0; j < 5; j++)
        {
            if (j == i)
                continue;
            b = array[j];
            for (int k = 0; k < 5; k++)
            {
                if (i == k || j == k)
                    continue;
                c = array[k];
                printf("%c%c%c \n", a, b, c);
            }
        }
    }
}

//题二，爱因斯坦问题，每步跨2阶，最后剩1阶；每步跨3阶，最后剩2阶；每步跨5阶，最后剩4结；每步跨6，最后剩5；每步跨7，最后剩0；
void ainsitan(int n)
{
    int sum = 0;
    for (int i = 7; i <= n; i++)
    {
        if (i % 2 == 1 && i % 3 == 2 && i % 5 == 4 && i % 6 == 5 && i % 7 == 0)
        {
            sum++;
            printf("%d \n", i);
        }
    }
}

void buyChicken()
{
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            for (int k = 0; k <= 100; k++)
            {
                if (5 * i + 3 * j + k / 3 == 100 && k % 3 == 0 && i + j + k == 100)
                {
                    printf("%d,%d,%d \n", i, j, k);
                }
            }
        }
    }
}

void match()
{
    for (char i = 'x'; i <= 'z'; i++)
    {
        if (i == 'x')
            continue;
        for (char j = 'x'; j <= 'z'; j++)
        {
            if (j == i)
                continue;
            char k = 'y';
            if (k == i || k == j)
                continue;
            printf("A->%c;", i);
            printf("B->%c;", j);
            printf("C->%c; \n", k);
        }
    }
}

int main()
{
    match();
    return 1;
}