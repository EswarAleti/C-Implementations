#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void createCLL()
{
	int val;
	printf("Enter elements of double linkedlist end by -1: ");
	struct node *temp;
	while(1)
	{
		scanf("%d",&val);
		if(val==-1)
			break;
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data=val;
		if(head==NULL)
		{
			head=newNode;
			newNode->next=head;
			temp=head;
		}
		else
		{
			newNode->next=head;
			temp->next=newNode;
			temp=temp->next;
		}
	}
}
struct node *JosephusCircle()
{
	int i,j,M=7,N=2;
	struct node *temp=head;
	for(i=M;i>1;i--)
	{
		for(j=N;j>1;j--)
			head=head->next;
		printf("%d\n",head->next->data);
		head->next=head->next->next;
	}
	return head;
}
void displayCLL()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	struct node *temp=head;
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}
int main()
{
	createCLL();
	displayCLL();
	struct node *temp=JosephusCircle();
	printf("Winner is: %d",temp->data);
	return 0;
}
