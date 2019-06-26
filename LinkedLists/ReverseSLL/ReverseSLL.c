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
void reverseSLL()
{
	if(!head || !head->next)
		return;
	struct node *first=NULL,*next=NULL;
	while(head)
	{
		next=head->next;
		head->next=first;
		first=head;
		head=next;
	}
	head=first;
}
void reverseRecursive(struct node *prev,struct node *current)
{
	if(current)
	{
		reverseRecursive(current,current->next);
		current->next=prev;
	}
	else
		head=prev;
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
	reverseRecursive(NULL,head);
	printList();
	return 0;
}
