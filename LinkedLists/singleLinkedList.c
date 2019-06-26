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
void insertAtFirst(int val)
{
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=head;
	head=newNode;
}
void insertAtLast(int val)
{
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=NULL;
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newNode;
}

void insertAtPosition(int position, int val)
{
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	int counter=1;
	struct node *temp=head;
	while(temp->next!=NULL && counter<position-1)
	{
		temp=temp->next;
		counter++;
	}
	newNode->next=temp->next;
	temp->next=newNode;
}
void deleteFirst()
{
	struct node *temp=head;
	head=head->next;
	free(temp);
}
void deleteLast()
{
	struct node *temp1=head;
	if(temp1->next==NULL)
	{
		free(temp1);
		head=0;
		return;
	}
	struct node *temp2=head->next;
	while(temp2->next!=NULL)
	{
		temp1=temp2;
		temp2=temp2->next;
	}
	temp1->next=NULL;
	free(temp2);	
}
void deleteAtPosition(int position)
{
	if(position==1)
	{
		deleteFirst();
		return;
	}
	int current=0;
	struct node *temp1=head;
	struct node *temp2=head->next;
	while(current<position-2 && temp1->next!=NULL)
	{
		temp1=temp2;
		temp2=temp2->next;
		current++;
	}
	temp1->next=temp2->next;
	free(temp2);
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
		printf("Few nodes in the list");
		return ;
	}
	temp=head;
	int i;
	for(i=0;i<(count-n);i++)
	{
		temp=temp->next;
	}
	printf("Nth data from the end of the list is : %d",temp->data);
}
void deleteList()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		head=head->next;
		free(temp);
		temp=head;
	}
}
int main()
{
	createList();
	printList();
	insertAtFirst(111);
	printList();
	insertAtLast(222);
	printList();
	insertAtPosition(5,0);
	printList();
	deleteFirst();
	printList();
	deleteLast();
	printList();
	deleteAtPosition(4);
	printList();
	//deleteList();
	//printList();
	NthNodeFromEnd(4);
	return 0;
}
