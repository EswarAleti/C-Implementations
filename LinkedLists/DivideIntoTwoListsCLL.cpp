#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*list1,*list2;
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
void divideList()
{
	struct node *slowPtr=head,*fastPtr=head;
	while(fastPtr->next!=head && fastPtr->next->next!=head)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
	}
	list2=slowPtr->next;
	list1=head;
	slowPtr->next=list1;
	if(fastPtr->next==head)
	{
		fastPtr->next=list2;
	}
	else
	{
		fastPtr->next->next=list2;
	}
}
void displayCLL(struct node *head)
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
	divideList();
	displayCLL(list1);
	displayCLL(list2);
	return 0;
}
