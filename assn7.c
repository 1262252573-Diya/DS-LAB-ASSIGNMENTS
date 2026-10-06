#include<stdio.h>
#include<ctype.h>

int stack[100],top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int main(){
    char exp[100];
    int i,a,b;

    printf("Enter postfix expression: ");
    scanf("%s",exp);

    for(i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }
        else{
            b=pop();
            a=pop();

            if(exp[i]=='+')
                push(a+b);
            else if(exp[i]=='-')
                push(a-b);
            else if(exp[i]=='*')
                push(a*b);
            else if(exp[i]=='/')
                push(a/b);
        }
    }

    printf("Result = %d",pop());

    return 0;
}