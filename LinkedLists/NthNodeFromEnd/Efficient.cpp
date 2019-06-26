#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=0;
void createList()
{
	int val;
	struct node *temp;
	printf("Enter numbers consecutively ends with -1: ");
	while(1)
	{
		scanf("%d",&val);
		if(val==-1)
			return;
			
		struct node *newNode=(struct node *)malloc(sizeof(struct node));
		newNode->data=val;
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head=newNode;
			temp=head;
		}
		else
		{
			temp->next=newNode;
			temp=newNode;
		}
	}
}
void printList()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void NthNodeFromEnd(int n)
{
	struct node *temp1=head,*temp2=head;
	int i;
	for(i=0;i<n-1 && temp2;i++)
	{
		temp2=temp2->next;
	}
	if(i<n && temp2==NULL)
	{
		printf("Few nodes in the list\n");
		return;
	}
	while(temp2)
	{
		if(temp2->next==NULL)
		{
			printf("%d node from the end of the list is : %d\n",n,temp1->data);
			break;	
		}
		if(temp1)		
			temp1=temp1->next;
		else
			temp1=head;
		temp2=temp2->next;
	}
}
int main()
{
	createList();
	printList();
	NthNodeFromEnd(3);
	NthNodeFromEnd(2);
	NthNodeFromEnd(1);
	return 0;
}
