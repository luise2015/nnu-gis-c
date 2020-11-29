#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char data[100];
    int top;
} SqStack;

int isEmpty(SqStack &stack)
{
    return stack.top == -1;
}

void push(SqStack &stack, int data)
{
    stack.data[++stack.top] = data;
}

int pop(SqStack &stack)
{
    if (isEmpty(stack))
        return -1;
    int x = stack.data[stack.top];
    stack.top--;
    return x;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int depth, int n, char *a)
{
    if (depth == n)
    {
        int flag = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (a[i] > a[j] && a[i] > a[k] && a[j] < a[k])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (!flag)
        {
            printf("%s", a);
            printf("\n");
        }
    }
    else
    {
        for (int i = depth; i < n; i++)
        {
            swap(&a[i], &a[depth]);
            permute(depth + 1, n, a);
            swap(&a[i], &a[depth]);
        }
    }
}

int match(char a[], int n)
{
    SqStack stack;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '(')
        {
            push(stack, a[i]);
        }
        if (a[i] == ')')
        {
            if (isEmpty(stack))
            {
                return -1;
            }
            pop(stack);
        }
    }
    return isEmpty(stack);
}

float operation(int a, int b, char c)
{
    if ('+' == c)
        return a + b;
    if ('-' == c)
        return a - b;
    if ('*' == c)
        return a * b;
    if ('/' == c)
        return 1.0 * a / b;
    return 0;
}

int priority(char a, char b)
{
    if ('+' == a || '-' == a)
        return '+' == b || '-' == b;
    if ('*' == a || '/' == a)
        return '+' == b || '-' == b || '*' == b || '/' == b;
    return 0;
}

//1、中序表达式计算
//2、前序表达式计算
//3、后序表达式计算
//4、中序转前序
//5、中序转后序
float calMiddle(char *express)
{
    float stack1[100];
    char stack2[100];
    int top1 = -1, top2 = -1;
    int i = 0;
    while (express[i] != '\0')
    {
        char value = express[i];
        if (value >= '0' && value <= '9')
        {
            stack1[++top1] = value - '0';
        }
        else if (value == '+' || value == '-' || value == '*' || value == '/')
        {
            while (top2 >= 0 && priority(stack2[top2], value))
            {
                int a = stack1[top1--];
                int b = stack1[top1--];
                char c = stack2[top2--];
                stack1[++top1] = operation(b, a, c);
            }
            stack2[++top2] = value;
        }
        else if (value == '(')
        {
            stack2[++top2] = value;
        }
        else if (value == ')')
        {
            while (stack2[top2] != '(')
            {
                int a = stack1[top1--];
                int b = stack1[top1--];
                char c = stack2[top2--];
                stack1[++top1] = operation(b, a, c);
            }
            top2--;
        }
        i++;
    }
    while (top2 >= 0)
    {
        int a = stack1[top1--];
        int b = stack1[top1--];
        char c = stack2[top2--];
        stack1[++top1] = operation(b, a, c);
    }
    return stack1[top1];
}

char *middleToPost(char *expression)
{
    char stack1[100];
    char stack2[100];
    int top1 = -1;
    int top2 = -1;
    int i = 0;
    while (expression[i] != '\0')
    {
        char value = expression[i];
        if (value >= '0' && value <= '9')
        {
            stack1[++top1] = value;
        }
        else if (value == '(')
        {
            stack2[++top2] = value;
        }
        else if (value == ')')
        {
            while (stack2[top2] != '(')
            {
                stack1[++top1] = stack2[top2--];
            }
            top2--;
        }
        else
        {
            while (top2 >= 0 && priority(stack2[top2], value))
            {
                stack1[++top1] = stack2[top2--];
            }
            stack2[++top2] = value;
        }
        i++;
    }
    while (top2 >= 0)
    {
        stack1[++top1] = stack2[top2--];
    }
    stack1[++top1] = '\0';
    char *result = (char *)malloc(sizeof(char) * 100);
    result = strcpy(result, stack1);
    return result;
}

char *middleToPre(char *expression)
{
    int length = 0;
    while (expression[length] != '\0')
    {
        length++;
    }
    //准备2个栈，结果栈、运算符栈
    char stack1[100];
    char stack2[100];
    int top1 = -1, top2 = -1;
    //从右向左遍历表达式
    for (int i = length - 1; i >= 0; i--)
    {
        char value = expression[i];
        //数字直接入结果栈
        if (value >= '0' && value <= '9')
        {
            stack1[++top1] = value;
        }
        //)直接入结果栈
        else if (value == ')')
        {
            stack2[++top2] = value;
        }
        //(，把运算符栈中到）中的内容移动到结果栈
        else if (value == '(')
        {
            while (stack2[top2] != ')')
            {
                stack1[++top1] = stack2[top2--];
            }
            top2--;
        }
        else
        {
            //栈非空，并且当前运算符大于栈顶运算符，放入结果栈
            while (top2 >= 0 && priority(stack2[top2], value))
            {
                stack1[++top1] = stack2[top2--];
            }
            stack2[++top2] = value;
        }
    }
    while (top2 != -1)
    {
        stack1[++top1] = stack2[top2--];
    }
    char *result = (char *)(malloc(sizeof(char) * 100));
    int i = 0;
    while (top1 >= 0)
    {
        result[i++] = stack1[top1--];
    }
    result[i] = '\0';
    return result;
}

float calPre(char *expression)
{
    int length = 0;
    while (*(expression + length) != '\0')
    {
        length++;
    }
    int stack1[100];
    int top1 = -1;
    for (int i = length - 1; i >= 0; i--)
    {
        char value = *(expression + i);
        if (value >= '0' && value <= '9')
        {
            stack1[++top1] = value - '0';
        }
        else
        {
            int a = stack1[top1--];
            int b = stack1[top1--];
            stack1[++top1] = operation(a, b, value);
        }
    }
    return stack1[top1];
}

int calPost(char *expression)
{
    int stack1[100];
    int top1 = -1;
    while (*expression != '\0')
    {
        char value = *(expression);
        if (value >= '0' && value <= '9')
        {
            stack1[++top1] = value - '0';
        }
        else
        {
            int a = stack1[top1--];
            int b = stack1[top1--];
            stack1[++top1] = operation(b, a, value);
        }
        expression++;
    }
    return stack1[top1];
}

int main()
{
    char a[] = "3+(5-3)*4";
    char *result = middleToPost(a);
    int value = calPost(result);
    return 1;
}