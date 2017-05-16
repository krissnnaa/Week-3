#include<stdio.h>
#include<stdlib.h>
struct node
{
	long int num;
	struct node *left;
	struct node *right;
};
struct node *tree=NULL;
void preorder(struct node *tree);
void inorder(struct node *tree);
void postorder(struct node *tree);
struct node *insert(struct node *tree,long int num);
int count=1;
void main()
{
int choice;
long int digit;
do
{
	choice=select();
	switch(choice)
	{
	case 1: puts("Enter Integer or To quit enter Zero");
			scanf("%ld",&digit);
			while(digit!=0)
			{
				tree=insert(tree,digit);
				scanf("%ld",&digit);
			}
			continue;
	case 2: puts("\n Preorder traversing TREE");
			preorder(tree);
			continue;
	case 3: puts("\n Inorder traversing TREE");
			inorder(tree);
			continue;
	case 4: puts("\n Postorder traversing TREE");
			postorder(tree);
			continue;
	case 5: puts("\n END OF THE PROGRAM.");
			exit(0);
	}
}while(choice!=5);
}
int select()
{
	int selection;
	do
	{
		printf("\nEnter 1: To insert a node in the Binary Tree.");
		printf("\nEnter 2: To Display Preorder of the Binary Tree.");
		printf("\nEnter 3: To Display Inorder of the Binary Tree.");
		printf("\nEnter 4: To Display Postorder of the Binary Tree.");
		printf("\nEnter 5: To END Program\n");
		scanf("%d",&selection);
		if((selection<1)|| (selection>5))
		{
			printf("Wrong choice.");
		}
	}while((selection<1)|| (selection>5));
	return(selection);
}
struct node *insert(struct node *tree,long int digit)
{
	if(tree==NULL)
	{
		tree=(struct node *) malloc(sizeof(struct node));
		tree->left=tree->right=NULL;
		tree->num=digit;
		count++;
	}
	else
	{
		if(count%2==0)
			tree->left=insert(tree->left,digit);
		else
			tree->right=insert(tree->right,digit);

	}
	return tree;
}

void preorder(struct node *tree)
{
		if(tree!=NULL)
		{
			printf("%ld\n",tree->num);
			preorder(tree->left);
			preorder(tree->right);
		}
}

void inorder(struct node *tree)
{
		if(tree!=NULL)
		{
			inorder(tree->left);
			printf("%ld\n",tree->num);
			inorder(tree->right);
		}
}

void postorder(struct node *tree)
{
		if(tree!=NULL)
		{
			postorder(tree->left);
			postorder(tree->right);
			printf("%ld\n",tree->num);
		}
}



