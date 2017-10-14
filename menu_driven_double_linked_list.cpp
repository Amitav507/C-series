#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
}NODE;
void insert_front(NODE**,int);
void insert_end(NODE**,int);
void delete_node(NODE**,int);
void delete_pos(NODE**,int);
void insert_pos(NODE**,int, int);
void display(NODE*);

main()
{
  int ch,x,pos;
  NODE *first;//pointer to the list
  first=NULL;
  while(1)
  {
    display(first);
    printf("\n1.insert front\n");
    printf("\n2. insert end\n");
    printf("\n3. delete a node\n");
    printf("\n4. delete at a position\n");
    printf("\n5. Insert at a given position\n");
    printf("\n6.exit");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("Enter the element..");
            scanf("%d",&x);
            insert_front(&first, x);
            break;
    case 2:printf("Enter the element..");
            scanf("%d",&x);
            insert_end(&first, x);
            break;
    case 3:printf("Enter the element to be deleted..");
            scanf("%d",&x);
            delete_node(&first, x);
            break;
     case 4:printf("Enter the position");
            scanf("%d",&pos);
            delete_pos(&first,pos);
            break;
     case 5:printf("Enter the position and the element");
            scanf("%d%d",&pos, &x);
            insert_pos(&first,pos,x);
            break;
    
     case 6:exit(0);
     }
   }
 }


   
void insert_front(NODE **p, int x)
{
     
    NODE *temp;
    temp=(NODE*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=temp->next=NULL;

    if(*p==NULL)//empty list
      *p=temp;
    else
      {
         temp->next=*p;
         (*p)->prev=temp;
         *p=temp;
      }
} 
      
void insert_end(NODE **p, int x)
{
     
    NODE *temp,*q;
    temp=(NODE*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=temp->next=NULL;

    if(*p==NULL)//empty list
      *p=temp;
    else
      {
        q=*p;
         //go to the end of list
        while(q->next!=NULL)
           q=q->next;
        q->next=temp;//link new node to last node
        temp->prev=q;        
      }
} 

void insert_pos(NODE**p,int pos, int x)
{
    int i; 
    NODE *temp,*q;
     q=*p;

    if(pos==1)
      insert_front(p,x);
    else
      {
         temp=(NODE*)malloc(sizeof(struct node));
         temp->data=x;
         temp->prev=temp->next=NULL;
         for(i=1;(q->next!=NULL)&&(i<pos);i++)
            q=q->next;

         if(i==pos)//insert in middle before q;
           {
             q->prev->next=temp;
             temp->prev=q->prev;
             temp->next=q;
              q->prev=temp;
            }
           else if(i==pos-1)//insert end
           {
             q->next=temp;
             temp->prev=q;
           }
           else
             printf("Invalid position");
        }
}
             
void delete_pos(NODE**p,int pos)
{
     int i;
     NODE *q=*p;
    
     if(pos==1)
      {
        if(q->next==NULL)//only one node         
           *p=NULL;
        else
          {
            *p=q->next;//make first point to second node
            (*p)->prev=NULL;
          }
         free(q);
      }
      else
       {
         //go to the desired position         
        for(i=1;((q->next!=NULL)&&(i<pos));i++)
           q=q->next;

        if(i==pos)
        {
          if(q->next==NULL)//delete last node
              q->prev->next=NULL;
           else
            {
               q->prev->next=q->next;
               q->next->prev=q->prev;
             }
           free(q);
        }
       else
        printf("Invalid postion");
       }
      
}                
 
void delete_node(NODE**p,int x)
{
     NODE *q;

     q=*p;
     while((q!=NULL) && (q->data!=x))
           q=q->next;

     if(q!=NULL)
     {
        // if only one node in the list
       if((q->prev==NULL)&&(q->next==NULL))
            *p=NULL;//make first NULL
       else if(q->prev==NULL)//first node
           {
              *p=q->next;
              (*p)->prev=NULL;
            }           
        else if(q->next==NULL)//last node
           q->prev->next=NULL;
        else//middle
           {
             q->prev->next=q->next;
             q->next->prev=q->prev;
           }
      free(q);
     }
  else
     printf("NODE not found\n");
} 
            

void display(NODE *p)
{
	printf("\n");
	while(p!=NULL)
   {
      printf("%d<->",p->data);
      p=p->next;
	}
}
   
       

  



   
