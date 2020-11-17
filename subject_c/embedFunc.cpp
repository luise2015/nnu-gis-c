#include <stdio.h>
#include <string.h>
int atoi(char *s)
{
    int i = 0, n = 0, sign = 0;

    while (s[i] == 32)
    {
        i++;
    }
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (s[i] >= '0' && s[i] <= '9')
    {
        n = n * 10 + s[i] - '0';
        i++;
    }
    return n * sign;
}

void itoa(int n)
{
    char s[100];
    int i = 0, sign = 1;
    if (n < 0)
    {
        n = -n;
        sign = -1;
    }
    do
    {
        s[i++] = n % 10 + '0';
        n = n / 10;
    } while (n != 0);
    if (sign == -1)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    for (int j = 0; j < i; j++)
    {
        printf("%c", s[i - 1 - j]);
    }
}

char *myconcat(char *des, const char *src)
{
    char *address = des;
    int i = 0;
    while ((*des++) != '\0')
    {
        i++;
    }
    while ((*des++ = *src++) != '\0')
    {
        /* code */
    }

    return address;
}

char *myconcat2(char *des, const char *src, int n)
{
    char *address = des;
    while (*des != '\0')
    {
        des++;
    }
    while (n-- && *src != '\0')
    {
        *des++ = *src++;
    }
    *des = '\0';
    return address;
}

char *cpy(char *des, const char *src)
{
    char *address = des;
    while ((*des++ = *src++) != '\0')
        ;
    return address;
}

char *cpy2(char *des, const char *src, int n)
{
    char *address = des;
    while (n-- && (*des++ = *src++) != '\0')
    {
        /* code */
    }
    *des = '\0';
    return address;
}

int cmp(char *s, char *t)
{
    while (*s && *t && (*s++ == *t++))
    {
        /* code */
    }
    return *s - *t;
}

int cmp(char *s, char *t, int n)
{
    while (n-- && *s && *t && (*s++ == *t++))
    {
        /* code */
    }
    return *s - *t;
}

int main()
{
    int result = cmp("abc", "abc");
    printf("%d", result);
    return 0;
}