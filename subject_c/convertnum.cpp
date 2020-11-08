#include <stdio.h>
#include <malloc.h>
#include <string.h>

void convertDec2Any(int a, int n)
{
    int result[100], count = 0;
    char map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (a)
    {
        result[count++] = a % n;
        a = a / n;
    }
    count--;
    for (int i = count; i >= 0; i--)
    {
        printf("%c", map[result[i]]);
    }
}

void convertAny2Dec(char *a, int n)
{
    int result = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        int value = a[i] > '9' ? (a[i] - 'A' + 10) : a[i] - '0';
        result = result * n + value;
    }
    printf("%d", result);
}

int main()
{
    char a[] = "11001";
    convertAny2Dec(a, 2);
    return 0;
}