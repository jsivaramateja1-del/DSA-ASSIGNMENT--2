#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = ch;
} 

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    char ch = stack[top];
    top--;
    return ch;
}

void reverseString(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        str[i] = pop();
    }

}

int main()
{
    int n;
    printf("Enter the length of the string: ");
    scanf("%d ", &n);

    char str[n + 1];
    printf("Enter a string: ");
    fgets(str, n + 1, stdin);
    str[strcspn(str, "\n")] = '\0';
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}   