#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *head=NULL;
void createDLL()
{
	int val;
	printf("Enter elements of double linkedlist end by -1: ");
	while(1)
	{
		scanf("%d",&val);
		if(val==-1)
			break;
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data=val;
		if(head==NULL)
		{
			newNode->prev=NULL;
			newNode->next=NULL;
			head=newNode;
		}
		else
		{
			struct node *temp=head;
			while(temp->next)
			{
				temp=temp->next;
			}
			newNode->prev=temp;
			temp->next=newNode;
			newNode->next=NULL;
		}
	}
}
void insertAtFirstDLL(int val)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=head;
	newNode->prev=NULL;
	head->prev=newNode;
	head=newNode;
}
void insertAtLastDLL(int val)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	struct node *temp=head;
	while(temp->next)
	{
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->prev=temp;
	newNode->next=NULL;
}
void insertAtPositionDLL(int val, int position)
{
	if(position==1)
	{
		insertAtFirstDLL(val);
		return;
	}
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	int count=1;
	struct node *temp=head;
	while(count<position-1 && temp->next)
	{
		temp=temp->next;
		count++;
	}
	if(count<position-1 && temp->next==NULL)
	{
		printf("Position is invalid\n");
		return;
	}
	if(temp->next==NULL)
	{
		insertAtLastDLL(val);
		return;
	}
	newNode->prev=temp;
	newNode->next=temp->next;
	temp->next->prev=newNode;
	temp->next=newNode;
}
void deleteFirstDLL()
{
	struct node *temp=head;
	if(head->next==NULL)
	{
		free(temp);
		head=NULL;
		return;
	}
	head=head->next;
	temp->next->prev=NULL;
	free(temp);
}
void deleteLastDLL()
{
	struct node *temp=head;
	while(temp->next)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}
void deleteAtPositionDLL(int position)
{
	if(position==1)
	{
		deleteFirstDLL();
		return;
	}
	struct node *temp=head;
	int count=1;
	while(count!=position && temp->next)
	{
		temp=temp->next;
		count++;
	}
	if(count<position&&temp->next==NULL)
	{
		printf("Position is invalid\n");
		return;
	}
	if(temp->next==NULL)
	{
		deleteLastDLL();
		return;
	}
	temp->next->prev=temp->prev;
	temp->prev->next=temp->next;
	free(temp);
}
void deleteDLL()
{
	struct node *temp=head;
	while(temp)
	{
		deleteFirstDLL();
		temp=head;
	}
}
void displayDLL()
{
	struct node *temp=head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	createDLL();
	displayDLL();
	insertAtFirstDLL(111);
	displayDLL();
	insertAtLastDLL(222);
	displayDLL();
	insertAtPositionDLL(000,3);
	displayDLL();
	deleteFirstDLL();
	displayDLL();
	deleteLastDLL();
	displayDLL();
	deleteAtPositionDLL(4);
	displayDLL();
	deleteDLL();
	displayDLL();
	return 0;
}
