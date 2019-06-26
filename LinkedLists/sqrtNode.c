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
struct node *findsqrtNode()
{
	if(!head)
		return;
	struct node *temp=head,*list;
	int flag=0,i=0,j=0;
	while(temp)
	{
		if(i==j*j)
		{
			list=flag?list->next:head;
			flag=1;
			j++;
		}
		temp=temp->next;
		i++;
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
	printf("%d",findsqrtNode()->data);
	return 0;
}
