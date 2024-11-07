#include<stdio.h>
#include<stdlib.h>
#define max 100
char stack [max];
int top = -1;
void push(char data)
{
    if (top==max-1)
    {
        printf("overflow");
        return;
    }
    stack[++top]=data;
}
char pop()
{
    if (top==-1)
    {
        printf("underflow");
        return '\0';
    }
    char x = stack[top--];
    return x;
}
int is_Matching(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
    {
        return 1;
    }
    else
    {
    return 0;
    }
}
int is_balanced(char *ch)
{
    char poped;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i]=='(' || ch[i]=='{' || ch[i]=='[')
        {
            push(ch[i]);
        }
        else if (ch[i]==')' || ch[i]=='}' || ch[i]==']')
        {
            poped = pop();
            if (! is_Matching(poped,ch[i]))
            {
                return 0;
            }
        }
    }
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char expression[max];
    printf("Enter an expression with parentheses: ");
    scanf("%s", expression);
    if (is_balanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }
    return 0;
}