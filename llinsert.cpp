#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *link;
} Node;
Node *start=NULL;
int c=0;
int display()
{
	Node *curr=start;
	if(c==0)
	printf("\n nothing to show");
	else
	{

		{
			while(curr!=NULL)
			{
				printf("\t %d",curr->info);
				curr=curr->link;
			}
		}
	}
	printf("\n");
	return 0;
}
int insert(int d,int pos)
{
	int i;
	Node *curr=start,*temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->info=d;
	temp->link=NULL;
	if(pos>c+1)
	{
		printf("\n position outside list \n");
		return 0;
	}
    if(pos==1)
    {
    	temp->link=start;
    	start=temp;
    	c++;
	}
	else
	{
		pos--;
		while(pos>1)
		{
			curr=curr->link;
			pos--;
		}
		temp->link=curr->link;
		curr->link=temp;
		c++;
	}
	return 0;
}
void lldelete(int pos)
{
	Node *curr=start;
	if(pos>c)
	{
		printf("\n node already empty\n");
		return;
	}
	if(pos==1)
	{
		Node *temp=start;
		start=start->link;
		printf("\n value = %d deleted\n",temp->info);
		free(temp);
				c--;
		
	}
	else
	{
		Node *temp=start;
		pos--;
		while(pos>1)
		{
			curr=curr->link;
			pos--;
		}
		temp=curr->link;
		curr->link=temp->link;
		printf("\n value = %d deleted\n",temp->info);
		free(temp);
		c--;
	}
    printf("\n");
    if(c==0)
    {
    	printf("\n list is clear\n ");
    	Node *start = NULL;
	}
	return;
}
int reverse(Node *k){             //new addition on 25th Oct begins
	Node *temp=k;
	if(temp->link!=NULL)
	reverse(temp->link);
	printf(" %d",temp->info);
	return 0;
}                                  //ends

int main()
{
	int t,d,pos;
	while (1)
	{
	 printf("\n enter \n 1 to insert \n 2 to display \n 3 to delete \n 4 to exit \n");
     scanf("%d",&t);
     switch(t)
     {
     	case 1:
     		printf("\n enter data and position");
     		scanf("%d %d",&d,&pos);
     		insert(d,pos);
     		break;
     	case 2:
		    printf("\n current list :");
			display();
			break;
		case 3:
		    printf("\n enter position to delete");
:			scanf("%d",&pos);
			lldelete(pos);
			break;
				case 4:                                  //new addition on 25th oct begins
		    printf("\n list in reverse: ");
			reverse(start);
			break;	 		                     //ends
		
	//	case 4:
	case 5
		    return 0; 		
	 }
    }
}
