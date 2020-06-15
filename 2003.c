#include <stdio.h>
#include <math.h>

//三、程序设计题
//1.从键盘输入10个数，输出其中的最大数和最小数
void test1()
{
    int min, max;
    for (int i = 0; i < 10; i++)
    {
        int value;
        printf("please input a number:");
        scanf("%d", &value);
        if (i == 0)
        {
            min = value;
            max = value;
        }
        else
        {
            if (value < min)
            {
                min = value;
            }
            if (value > max)
            {
                max = value;
            }
        }
    }
    printf("the min number is:%d \n", min);
    printf("the max number is:%d", max);
}

//2.求300以内的双素数
int isPrime(int value)
{
    if (value <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(value); i++)
    {
        if (value % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void test2()
{
    for (int i = 1; i <= 300; i++)
    {
        if (isPrime(i) && isPrime(i + 2))
        {
            printf("%d", i);
            printf("\n");
        }
    }
}

//3.编一个子程序能够对数组进行从小到大的排序，
//再编写一个二分查找子程序，判定主函数传过来的待查数是否在已排序的数组中
//若查找到返回它在数组中的位置（可以在多个位置出现），否则返回-1
void sort(int array[], int length)
{
    int flag, tmp;
    //n-1次冒泡
    for (int i = 1; i < length; i++)
    {
        flag = 0;
        //前n-i个数进行交换
        for (int j = 0; j < length - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int search(int array[], int start, int end, int value)
{
    if (start > end)
        return -1;
    int i = (start + end) / 2;
    if (array[i] == value)
        return i;
    else if (array[i] < value)
    {
        return search(array, i + 1, end, value);
    }
    else
    {
        return search(array, start, i - 1, value);
    }
}

void test3()
{
    const int size = 10;
    int array[10] = {4, 5, 6, 3, 9, 19, 7, 4, 15, 13};
    sort(array, size);
    int index = search(array, 0, size - 1, 6);
    printf("%d", index);
}

//4.利用递归法找出自然数1,2,n中任取r个数的所有组合
const int R = 4;
void combine(int start, int n, int r, int bIndex, int b[])
{
    if (r == 0)
    {
        for (int k = 0; k < R; k++)
        {
            printf("%d ", b[k]);
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i <= n + 1 - r; i++)
        {
            b[bIndex] = i;
            combine(i + 1, n, r - 1, bIndex + 1, b);
        }
    }
}

void test4()
{
    int b[4];
    combine(1, 5, R, 0, b);
    // 1 2 3 4 5
    //step1 1 从2 3 4 5中选取2个数
    //step1-1 2 从 3 4 5中选取1个数
    //step1-2 3 从 4 5中选取一个数
    //step1-3 4 从5中选取一个数
    //step2 2 从3 4 5中选取2个数
    //step3 3 从 4 5中选取两个数
}

//5.单向循环链表和顺序存储结构设计一个算法解决约瑟夫环问题
//设有N个人围坐一圈。现从某个人开始报数，数到M的人出列，直到所有人都出列为止
//试求他们的出列次序
void joseph(int arr[], int n, int m)
{
    int size = n;
    int index = 0;
    while (size > 0)
    {
        index = (index + m - 1) % size;
        printf("%d\n", arr[index]);
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

void test5()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    joseph(arr, 7, 3);
}

void main()
{
    test5();
}