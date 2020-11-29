#include <stdio.h>

//从n个数选择r个数
//从n-1个数选择r-1个数
//r为0时候输出
void combine(int cur, int n, int r, int temp[], int depth)
{
    if (depth == r)
    {
        for (int i = 0; i < r; i++)
        {
            printf("%d", temp[i]);
        }
        printf("\n");
        return;
    }
    for (int i = cur; i <= n - r + depth; i++)
    {
        temp[depth] = i + 1;
        combine(i + 1, n, r, temp, depth + 1);
    }
}

void permute(int depth, int n, int r, int a[], int used[])
{
    if (depth == r)
    {
        for (int i = 0; i < r; i++)
        {
            printf("%d", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 1)
            continue;
        a[depth] = i + 1;
        used[i] = 1;
        permute(depth + 1, n, r, a, used); //递归
        used[i] = 0;                       //回溯
    }
}

int main()
{
    int a[5];
    int used[5];
    permute(0, 5, 3, a, used);
    return 1;
}