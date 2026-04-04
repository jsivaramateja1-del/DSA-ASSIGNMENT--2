#include<stdio.h>
#include<string.h>

#define max 100
char stack[max];

int top = -1;

void push(char ch)
{
    if (top == max - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}


char pop()
{
    if (top == max - 1)
    {
        printf("Stack is Empty\n");
    }
    char ch;
    ch = stack[top];
    top--;
    return ch;
}


int is_valid(char left, char right)
{
    if (left == '(' && right == ')')
        return 1;

    else if (left == '{' && right == '}')
        return 1;

    else if (left == '[' && right == ']')
        return 1;

    else
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
            push(exp[i]);
        }

        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == -1)
            {
                printf("Invalid Expression (Stack is empty)\n");
                return 0;
            }
            else
            {
                char popped = pop();

                if(!is_valid(popped, exp[i]))
                {
                    printf("Invalid Expression (Brackets not matching)\n");
                    return 0;
                }
            }
        }
    }

    if (top == -1)
    {
        printf("Valid Expression\n");
    }
    else
    {
        printf("Invalid Expression (Unclosed brackets)\n");
    }

    return 0;
}