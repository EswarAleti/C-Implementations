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
struct node *findFractionalNode(int k)
{
	if(k<=0 || !head)
		return 0;
	struct node *temp=head,*list;
	int flag=0;
	while(temp)
	{
		int i=k;
		while(temp && i--)
		{
			temp=temp->next;
		}
		list=flag?list->next:head;
		flag=1;
	}
	return list;
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
	printf("%d",findFractionalNode(3)->data);
	return 0;
}
