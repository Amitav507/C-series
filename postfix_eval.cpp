#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int top=-1;
int stack[20];
int push(int val)
{
	stack[++top]=val;
}
int pop()
{
	if(top<0)
	return 0;
	else
	return stack[top--];
}
int main()
{
	char exp[20],*e,x;
	int temp,op1,op2;
	printf("\nenter expression: ");
	scanf("%s",exp);
	e=exp;
	while(*e!='\0'){
		if(isalnum(*e)){
			temp=*e-'0';
			push(temp);
		}
		else{
			switch(*e){
				case '+':
					op2=pop();
					op1=pop();
					temp=op1+op2;
					push(temp);
					break;
				case '-':
					op2=pop();
					op1=pop();
					temp=op1-op2;
					push(temp);
					break;
				case '*':
					op2=pop();
					op1=pop();
					temp=op1*op2;
					push(temp);
					break;
				case '/':
					op2=pop();
					op1=pop();
					temp=op1/op2;
					push(temp);
					break;	
				default:
				    break;			
			}
		}
		e++;
	}
	printf("\n result is = %d",pop());
}
