#include<stdio.h>
#include<stdlib.h>
#define max 100
char stack[max];
int top=-1;
void push(char data)
{
    if (top==max-1)
    {
        printf("stack is full");
        return;
    }
    stack[++top]=data;
}
char pop()
{
    if (top==-1)
    {
        printf("stack is empty");
        return '\0';
    }
    return stack[top--];
}
int precedence(char data)
{
    if(data=='^')
    return 3;
    else if(data=='/' || data =='*')
    return 2;
    else if(data=='+' || data == '-')
    return 1;
    else
    return -1;
}
int isoperand(char data)
{
    if( (data >= 'a' && data <= 'z') || ( data >= 'A' && data <= 'Z'))
    return 1;
    return 0;
}
int strlen(char * exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++);
    return i;
}
char* infix_postfix(char * exp)
{
    int i = 0, j = -1;
    int len=strlen(exp);
    char* result=(char*)malloc((len+1)*(sizeof ( char)));
    char c;
    for (i = 0; i < len; i++)
    {
        c = exp[i];
        if(isoperand(c)) 
        result[++j]=c;
        else if(c == '(')
        push('(');
        else if(c == ')')
        {
            for(;top != -1 && stack[top] != '(';)
            result[++j] = pop();
            pop();
        }
        else
        {
            for(;top != -1 && (precedence(c) < precedence(stack[top]) || (precedence(c) == precedence(stack[top]) && c != '^'));)
            result[++j] = pop();
            push(c);
        }
    }
    for(;top!=-1;)
    result[++j]=pop();
    result[++j] = '\0';
    printf("%s\n", result);
    return result;
}
int main()
{
    char str[] = "shanu";
    printf("%s  %d \n ",str ,strlen(str));
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Infix expression: %s\n", exp);
    printf("Postfix expression: ");
    infix_postfix(exp);
    return 0;
}