#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node* right;
	struct node* left;
} Root;
Root* newnode(int val)
{
	Root* r=(Root *)malloc(sizeof(Root));
	r->data=val;
	r->left=NULL;
	r->right=NULL;
	return(r);
}

void inorder(Root* r)
{
	if(r == NULL)
	return;
	inorder(r->left);
	printf("\t %d",r->data);
	inorder(r->right);
	
}
void preorder(Root* r)
{
	if(r == NULL)
	return;
	printf("\t %d",r->data);
	preorder(r->left);
	preorder(r->right);
	
}
void postorder(Root* r)
{
	if(r == NULL)
	return;
	postorder(r->left);
	postorder(r->right);
	printf("\t %d",r->data);
	
	
}
int main()
{
	Root* r=newnode(1);
	r->left=newnode(2);
	r->right=newnode(3);
	r->left->left=newnode(4);
	r->left->right=newnode(5);
	int t;
		while (1)
	{
	 printf("\n enter \n 1 INorder \n 2 PREorder \n 3 POSTorder \n 4 to exit \n");
     scanf("%d",&t);
     switch(t)
     {
     	case 1:
     		inorder(r);
     		break;
     	case 2:
		    preorder(r);
			break;
		case 3:
		    postorder(r);
			break;	
		case 4:
		    return 0; 		
	 }
    }
}

