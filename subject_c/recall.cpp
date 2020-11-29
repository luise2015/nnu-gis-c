#include <stdio.h>
typedef struct
{
    int x;
    int y;
} Location;

int checkQueen(Location a[], Location b)
{
    for (int i = 0; i < b.x; i++)
    {
        if (a[i].x == b.x || a[i].y == b.y || a[i].y == b.x || a[i].x == b.y)
        {
            return 0;
        }
    }
    return 1;
}

void findQueen(int i, int n, Location a[])
{
    if (i == n)
    {
        return;
    }
    for (int j = 0; j < n; j++)
    {
        Location b;
        b.x = i;
        b.y = j;
        if (checkQueen(a, b))
        {
            a[i] = b;
            findQueen(i + 1, n, a);
        }
    }
}

int checkMigong(int graph[][5], int N, int i, int j)
{
    return i < N && j < N && graph[i][j] == 0;
}

void migong(int graph[][5], int N, int ci, int cj)
{
    if (ci == N - 1)
    {
        graph[ci][cj] = 6;
        for (int m = 0; m < N; m++)
        {
            for (int n = 0; n < N; n++)
            {
                printf("%d", graph[m][n]);
            }
            printf("\n");
        }
        graph[ci][cj] = 0;
        return;
    }
    int xs[] = {0, 1, 0, -1};
    int ys[] = {1, 0, -1, 0};
    for (int m = 0; m < 4; m++)
    {
        if (checkMigong(graph, N, ci + xs[m], cj + ys[m]))
        {
            graph[ci][cj] = 6;
            migong(graph, N, ci + xs[m], cj + ys[m]);
            graph[ci][cj] = 0;
        }
    }
}

int main()
{
    int graph[5][5] = {{0, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 0, 0, 1, 1}};
    migong(graph, 5, 0, 0);
    return 1;
}
