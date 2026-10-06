#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 100

char stack[N];
int top = -1;

void push(char val)
{
    top = top + 1;
    stack[top] = val;
}

char pop()
{
    char val = stack[top];
    top = top - 1;
    return val;
}

char peek()
{
    char val = stack[top];
    return val;
}

int precedence(char op) 
{
    if (op == '^') 
        return 3;
    if (op == '*' || op == '/') 
        return 2;
    if (op == '+' || op == '-') 
        return 1;
    return 0;
}

void infex_to_postfix(char *con)
{
    int len = strlen(con);
    char rev[100];
    for (int i = 0; i < len; i++) 
    {
        rev[i] = con[len - 1 - i];
    }
    rev[len] = '\0';

    for (int i = 0; i < len; i++) 
    {
        if (rev[i] == '(')
            rev[i] = ')';
        else if (rev[i] == ')')
            rev[i] = '(';
    }

    char postfix[100];
    int p = 0;

    for (int i = 0; i < len; i++) 
    {
        char ch = rev[i];

        if (isalnum(ch)) 
        {
            postfix[p] = ch;
            p++;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')') 
        {
            while (top != -1 && peek() != '(') 
            {
                postfix[p] = pop();
                p++;
            }
            if (top != -1) 
            {
                pop(); // remove '('
            }
        }
        else if (ch == '^' || ch == '+' || ch == '-' || ch == '/' || ch == '*') 
        {
            while (top != -1 && peek() != '(' && (precedence(peek()) > precedence(ch) || 
                  (precedence(peek()) == precedence(ch) && ch == '^'))) 
            {
                postfix[p] = pop();
                p++;
            }
            push(ch);
        }
    }

    while (top != -1) 
    {
        postfix[p] = pop();
        p++;
    }
    postfix[p] = '\0';


    char prefix[100];
    int plen = strlen(postfix);
    for (int i = 0; i < plen; i++) 
    {
        prefix[i] = postfix[plen - 1 - i];
    }
    prefix[plen] = '\0';

    printf("Prefix Expression: %s\n", prefix);
}

char str_stack[N];
int str_top = -1;

void postfix_to_infix(char *con)
{
    int len = strlen(con);   
}

int main() 
{
    char input[100];

    printf("Enter infix expression: ");
    scanf("%99s", input);

    infex_to_postfix(input);

    return 0;
}