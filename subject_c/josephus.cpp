#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//使用顺序存储结构
void method1(int n, int m)
{
    //分配一个数组，存储序号
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    //依次报数
    int size = n;
    int index = 0;
    while (size > 0)
    {
        index = (index + m - 1) % size; //注意这里是size不是n
        printf("%d\n", arr[index]);
        for (int j = index; j < size - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        size--;
    }
}

//链式结构存储
typedef struct LNode
{
    int data;
    LNode *next;
} LNode;

void method2(int n, int m)
{
    //建立循环链表
    LNode *head = (LNode *)malloc(sizeof(LNode));
    LNode *cursor = head;
    for (int i = 0; i < n; i++)
    {
        LNode *current = (LNode *)malloc(sizeof(LNode));
        current->data = i + 1;
        cursor->next = current;
        cursor = current;
    }
    cursor->next = head;
    cursor = head;
    //一次报数
    while (cursor->next != cursor)
    {
        LNode *p = cursor;
        for (int i = 0; i < m; i++)
        {
            cursor = p;
            p = p->next;
            if (p == head)
            {
                cursor = p;
                p = p->next;
            }
        }
        printf("%d\n", p->data);
        cursor->next = p->next;
    }
}

int main()
{
    method1(10, 7);
    method2(10, 7);
    getchar();
    return 0;
}