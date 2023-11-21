#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    int *stack;
    int top;
    int max;
};

void push(struct Stack *s, int elem)
{
    if (s->top == s->max - 1)
    {
        printf("stack Overflow! \n");
    }
    else
    {
        s->top = s->top + 1;
        s->stack[s->top] = elem;
    }
}

int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("stack is empty! \n");
        return -1;
    }
    else
    {
        int x = s->stack[s->top];
        s->top = s->top - 1;
        return x;
    }
}

void display(struct Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d\t", s->stack[i]);
    }
    printf("\n");
}

int toint(char str)
{
    int num = (int)str - (int)'0';
    return num;
}

int postfix_eval(struct Stack *s, char exp[])
{
    int op1, op2;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(s, toint(exp[i]));
        }
        else
        {
            char op = exp[i];
            int op1 = pop(s);
            int op2 = pop(s);
            switch (op)
            {
            case '+':
            {
                push(s, op2 + op1);
                break;
            }
            case '-':
            {
                push(s, op2 - op1);
                break;
            }
            case '*':
            {
                push(s, op2 * op1);
                break;
            }
            case '/':
            {
                push(s, op2 / op1);
                break;
            }
            case '^':
            {
                push(s, op2 ^ op1);
                break;
            }
            case '%':
            {
                push(s, op2 % op1);
                break;
            }
            }
        }
        display(s);
        i++;
    }
    return pop(s);
}

int main()
{
    struct Stack *s;
    s->top = -1;
    s->max = 50;
    s->stack = (int *)malloc(s->max * sizeof(int));
    int x = postfix_eval(s, "235-*93-3/+");
    printf("%d", x);

    return 0;
}