#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = val;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    int val = stack[top];
    top--;
    return val;
}

void nextGreater(int a[], int n)
{
    int i, j;
    int result[MAX];

    for (i = 0; i < n; i++)
        result[i] = -1;

    for (i = 0; i < n; i++)
    {
        while (!isEmpty() && stack[top] < a[i])
        {
            int val = pop();
            for (j = 0; j < n; j++)
            {
                if (a[j] == val && result[j] == -1)
                {
                    result[j] = a[i];
                    break;
                }
            }
        }
        push(a[i]);
    }

    for (i = 0; i < n; i++)
        printf("%d -> %d\n", a[i], result[i]);
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    nextGreater(a, n);

    return 0;
}