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

void main()
{
    test3();
}