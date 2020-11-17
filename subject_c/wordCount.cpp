#include <stdio.h>
#include <string.h>
//输入一段文字，统计单词数量
void test1()
{
    int flag = 0, num = 0;
    char ch;
    printf("please input words \n");
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
        {
            flag = 0;
        }
        else
        {
            if (flag == 0)
            {
                flag = 1;
                num++;
            }
        }
    }
    printf("the num of word is %d", num);
}

//从键盘或txt输入一段文字，输出单词词频
int check(char a)
{
    return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
}

void test2(char a[])
{
    int flag = 0;
    char temp[100];
    int tempsize = 0;
    for (int i = 0; i <= strlen(a); i++)
    {
        if (check(a[i]))
        {
            temp[tempsize++] = a[i];
            flag = 1;
        }
        else
        {
            if (flag == 1)
            {
                temp[tempsize] = '\0';
                printf("%s \n", temp);
                tempsize = 0;
            }
            flag = 0;
        }
    }
}

int main()
{
    test2("you are a stupid, i am a loser");
    return 1;
}