#include<stdio.h>
#include<string.h>

#define max 100
char stack[max];

int top = -1;

void push(char ch)
{
    if (top == max - 1)
    {
        printf("Stack is full\n"); // overflow check
    }
    else
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is Empty\n"); // underflow check
        return '\0';
    }
    return stack[top--];
}

int is_valid(char left, char right)
{
    // check matching pairs
    if (left == '(' && right == ')') return 1;
    if (left == '{' && right == '}') return 1;
    if (left == '[' && right == ']') return 1;
    return 0;
}

int main()
{
    char exp[100];

    printf("Please enter the expression: ");
    scanf("%s", exp);

    for(int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]); // push opening bracket
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == -1)
            {
                printf("Invalid Expression (Stack is empty)\n");
                return 0;
            }
            char popped = pop();

            if(!is_valid(popped, exp[i]))
            {
                printf("Invalid Expression (Brackets not matching)\n");
                return 0;
            }
        }
    }

    // final check
    if (top == -1)
        printf("Valid Expression\n");
    else
        printf("Invalid Expression (Unclosed brackets)\n");

    return 0;
}