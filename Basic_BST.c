#include<stdio.h>
#include<stdlib.h>
struct node
{
	long int num;
	struct node *left;
	struct node *right;
};
struct node *tree=NULL;
void inorder(struct node *tree);
struct node *insert(struct node *tree,long int num);
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
	case 2: puts("\n Inorder traversing tree");
			inorder(tree);
			continue;
	case 3: puts("\n END OF THE PROGRAM.");
			exit(0);

	}
}while(choice!=3);
}
int select()
{
	int selection;
	do
	{
		printf("\nEnter 1: To insert a node in the Binary Search Tree.");
		printf("\nEnter 2: To Display Inorder of the Binary Tree.");
		printf("\nEnter 3: To END Program\n");
		scanf("%d",&selection);
		if((selection<1)|| (selection>3))
		{
			printf("Wrong choice.");
		}
	}while((selection<1)|| (selection>3));
	return(selection);
}
struct node *insert(struct node *tree,long int digit)
{
	if(tree==NULL)
	{
		tree=(struct node *) malloc(sizeof(struct node));
		tree->left=tree->right=NULL;
		tree->num=digit;
	}
	else
	{
		if(digit<tree->num)
			tree->left=insert(tree->left,digit);
		else
			tree->right=insert(tree->right,digit);
	}
	return tree;
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




