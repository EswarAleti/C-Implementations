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
	int count=0;
	struct node *temp=head;
	while(temp)
	{
		count++;
		temp=temp->next;
	}
	if(count<n)
	{
		printf("Few nodes in the list\n");
		return ;
	}
	temp=head;
	int i;
	for(i=0;i<(count-n);i++)
	{
		temp=temp->next;
	}
	printf("Nth data from the end of the list is : %d\n",temp->data);
}
int main()
{
	createList();
	printList();
	NthNodeFromEnd(4);
	NthNodeFromEnd(3);
	NthNodeFromEnd(2);
	NthNodeFromEnd(1);
	return 0;
}
