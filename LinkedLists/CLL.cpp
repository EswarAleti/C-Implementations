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
void insertAtFirstCLL(int val)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	if(head==NULL)
	{
		head=newNode;
		newNode->next=head;
		return;
	}
	struct node *temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	newNode->next=head;
	head=newNode;
	temp->next=head;
}
void insertAtLastCLL(int val)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	if(head==NULL)
	{
		head=newNode;
		newNode->next=head;
		return;
	}
	struct node *temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	newNode->next=head;
	temp->next=newNode;
}
void insertAtPositionCLL(int val,int position)
{
	if(position==1)
	{
		insertAtFirstCLL(val);
		return;
	}
	int count=1;
	struct node *temp=head;
	while(count<position-1 && temp->next!=head)
	{
		temp=temp->next;
		count++;
	}
	if(count<position-1 && temp->next==head)
	{
		printf("Invalid position\n");
		return;
	}
	if(temp->next==head)
	{
		insertAtLastCLL(val);
		return;
	}
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=temp->next;
	temp->next=newNode;
}
void deleteFirstCLL()
{
	struct node *temp=head;
	if(temp->next==head)
	{
		free(temp);
		head=NULL;
		return;
	}
	struct node *temp2=head->next;
	while(temp2->next!=head)
	{
		temp2=temp2->next;
	}
	temp2->next=head->next;
	head=head->next;
	free(temp);
}
void deleteLastCLL()
{
	struct node *temp=head;
	if(temp->next==head)
	{
		free(temp);
		head=NULL;
		return;
	}
	struct node *temp1=NULL,*temp2=head;
	while(temp2->next!=head)
	{
		temp1=temp2;
		temp2=temp2->next;
	}
	temp1->next=head;
	free(temp2);
}
void deletePositionCLL(int position)
{
	if(position==1)
	{
		deleteFirstCLL();
		return;
	}
	struct node *temp1=NULL,*temp2=head;
	int count=1;
	while(count<position && temp2->next!=head)
	{
		temp1=temp2;
		temp2=temp2->next;
		count++;
	}
	if(count==position && temp2->next==head)
	{
		deleteLastCLL();
		return;
	}
	if(count<position && temp2->next==head)
	{
		printf("Invalid position\n");
		return;
	}
	temp1->next=temp2->next;
	free(temp2);	
}
void deleteCLL()
{
	while(head->next!=head)
	{
		deleteFirstCLL();
	}
	deleteFirstCLL();
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
	insertAtFirstCLL(111);
	displayCLL();
	insertAtLastCLL(222);
	displayCLL();
	insertAtPositionCLL(0,5);
	displayCLL();
	deleteFirstCLL();
	displayCLL();
	deleteLastCLL();
	displayCLL();
	deletePositionCLL(5);
	displayCLL();
	deleteCLL();
	displayCLL();
	return 0;
}
