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
void insertAtSortedPosition(int val)
{
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	struct node *current=head,*temp;
	if(val<head->data)
	{
		newNode->next=head;
		head=newNode;
		return;
	}
	while(current && val>current->data)
	{
		temp=current;
		current=current->next;
	}
	newNode->next=current;
	temp->next=newNode;
}
void printList()
{
	if(!head)
	{
		printf("List is empty\n");
		return;
	}
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	createList();
	printList();
	insertAtSortedPosition(1);
	printList();
	return 0;
}
