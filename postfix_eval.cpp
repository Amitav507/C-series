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
	bool readingNumber = false;
	printf("\nenter expression: ");
	scanf("%s",exp);
	e=exp;
	while(*e!='\0'){
		if(isalnum(*e)){
			if (readingNumber){
				temp= pop();
				temp*=10;
				temp+=*e-'0';
			}
			else{
				temp=*e-'0';
			}
			readingNumber = true;
			push(temp);
		}
		else{
			switch(*e){
				case '+':
					readingNumber=false;
					op2=pop();
					op1=pop();
					temp=op1+op2;
					push(temp);
					break;
				case '-':
					readingNumber=false;
					op2=pop();
					op1=pop();
					temp=op1-op2;
					push(temp);
					break;
				case '*':
					readingNumber=false;
					op2=pop();
					op1=pop();
					temp=op1*op2;
					push(temp);
					break;
				case '/':
					readingNumber=false;
					op2=pop();
					if(op2==0){
						printf("Divided by zero\n");
						return 0;
					}	
					op1=pop();
					temp=op1/op2;
					push(temp);
					break;
				case ',':
					readingNumber=false;	
				default:
				    break;			
			}
		}
		e++;
	}
	printf("\n result is = %d",pop());
}
