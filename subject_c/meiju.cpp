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
                printf("%c %c %c", a, b, c);
            }
        }
    }
}

int main()
{
    getRange();
    return 1;
}