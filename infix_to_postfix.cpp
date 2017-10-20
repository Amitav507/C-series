#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int top=-1;
char stack[20]={'0'};
int push(char val)
{
	stack[++top]=val;
}
char pop()
{
	if(top<0)
	return -1;
	else
	return stack[top--];
}
int priority(char x)
{
	if(x=='(')
	return 0;
	if(x=='+'||x=='-')
	return 1;
	if(x=='%'||x=='*')
	return 2;		
}
int main()
{
	char exp[20],*e,x;
	printf("\nenter expression: ");
	scanf("%s",exp);
	e=exp;
	while(*e!='\0')
	{
		if(isalnum(*e))
		printf("%c",*e);
		else{
			if(*e=='(')
			push(*e);
			else
			{
				if(*e==')'){
				x=pop();
				while(x!='('){
					printf("%c",x);
					x=pop();
				}
			}
			else{while(priority(stack[top])>=priority(*e)){
				printf("%c",pop());
			}
				push(*e);
			}
			}
			
		}
		e++;
	}
	while(top!=-1){
		printf("%c",pop());
	}
}
