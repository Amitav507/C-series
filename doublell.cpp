#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
	struct node *prev;
} Node;
Node *start=NULL;
Node *end=NULL;
int c=0;
int displayFromBegin()
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
				curr=curr->next;
			}
		}
	}
	printf("\n");
	return 0;
}
int displayFromEnd()
{
	Node *curr=end;
	if(c==0)
	printf("\n nothing to show");
	else
	{

		{
			while(curr!=NULL)
			{
				printf("\t %d",curr->info);
				curr=curr->prev;
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
	temp->next=NULL;
	temp->prev=NULL;
	if(pos>c+1)
	{
		printf("\n position outside list \n");
		return 0;
	}
    if(pos==1)
    {
    	temp->next= start; 
    	if(c==0)
    		temp->prev = end;
    	else
    	{
    		temp->prev=start->prev;
    		start->prev = temp;
    	}
    	start=temp;
    	if(c==0)
    	{
    		end = temp;
    	}
    	c++;
    	printf("\n item inserted successfully \n");

	}
	else
	{
		pos--;
		while(pos>1)
		{
			curr=curr->next;
			pos--;
		}
		temp->next=curr->next;
		curr->next=temp;
		temp->prev = curr;
		end = temp;
		c++;
		printf("\n item inserted successfully \n");
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
		start->next->prev = start->prev;
		start=start->next;
		printf("\n value = %d deleted\n",temp->info);
		free(temp);
				c--;
		
	}
	else if(c == pos)
	{
		Node *temp=start;
		pos--;
		while(pos>1)
		{
			curr=curr->next;
			pos--;
		}
		temp=curr->next;
		curr->next = temp->next;
		curr = end;
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
			curr=curr->next;
			pos--;
		}
		temp=curr->next;
		curr = end;
		curr->next=temp->next;
		temp->next->prev = curr;
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
int main()
{
	int t,d,pos;
	while (1)
	{
	 printf("\n enter \n 1 to insert \n 2 to display from begining \n 3 to display from end \n 4 to delete \n 5 to exit \n");
     scanf("%d",&t);
     switch(t)
     {
     	case 1:
     		printf("\n enter data and position: ");
     		scanf("%d %d",&d,&pos);
     		insert(d,pos);
     		break;
     	case 2:
		    printf("\n current list :");
			displayFromBegin();
			break;
		case 3:
		    printf("\n current list :");
			displayFromEnd();
			break;
		case 4:
		    printf("\n enter position to delete: ");
			scanf("%d",&pos);
			lldelete(pos);
			break;	
		case 5:
		    return 0; 		
	 }
    }
}
