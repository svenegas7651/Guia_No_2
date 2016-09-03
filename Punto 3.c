
 
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
 
#define MAX 50
 
typedef struct pila
{
    int data[MAX];
    int top;
}pila;
 
int precedencia(char);
void init(pila *);
int vacio(pila *);
int lleno(pila *);
int pop(pila *);
void push(pila *,int);
int top(pila *);   //value of the top element
void infix_a_postfix(char infix[],char postfix[]);
 
void main()
{
    char infix[30],postfix[30];
    printf("Escriba una expresion en infix(ej: 5+2*4): ");
    gets(infix);
    infix_a_postfix(infix,postfix);
    printf("\nExpresion a postfix: %s",postfix);
}
 
void infix_a_postfix(char infix[],char postfix[])
{
    pila s;
    char x,token;
    int i,j;    //i-index of infix,j-index of postfix
    init(&s);
    j=0;
 
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))
            postfix[j++]=token;
        else
            if(token=='(')
               push(&s,'(');
        else
            if(token==')')
                while((x=pop(&s))!='(')
                      postfix[j++]=x;
                else
                {
                    while(precedencia(token)<=precedencia(top(&s))&&!vacio(&s))
                    {
                        x=pop(&s);
                        postfix[j++]=x;
                    }
                    push(&s,token);
                }
    }
 
    while(!vacio(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }
 
    postfix[j]='\0';
}
 
int precedencia(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/'||x=='%')
        return(2);
 
    return(3);
}
 
void init(pila *s)
{
    s->top=-1;
}
 
int vacio(pila *s)
{
    if(s->top==-1)
        return(1);
 
    return(0);
}
 
int lleno(pila *s)
{
    if(s->top==MAX-1)
        return(1);
 
    return(0);
}
 
void push(pila *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}
 
int pop(pila *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}
 
int top(pila *p)
{
    return (p->data[p->top]);
}
