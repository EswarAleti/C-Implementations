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
void swapPairs()
{
	struct node *temp=NULL,*current=head;
	int flag=0;
	while(current && current->next)
	{
		if(temp)
		{
			temp->next->next=current->next;
		}
		temp=current->next;
		current->next=current->next->next;
		temp->next=current;
		current=current->next;
		if(flag==0)
		{
			head=temp;
			flag=1;
		}
	}
}
struct node *swapPairsRecursive(struct node *head)
{
	if(!head)
		return NULL;
	struct node *temp=head->next;
	head->next=temp->next;
	temp->next=head;
	head=temp;
	head->next->next=swapPairsRecursive(head->next->next);
	return head;
	
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
	//swapPairs();
	head=swapPairsRecursive(head);
	printList();
	return 0;
}
