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

struct node *reverse(struct node *head)
{
	struct node *first=0,*next=0;
	while(head)
	{
		next=head->next;
		head->next=first;
		first=head;
		head=next;
	}
	return first;
}

struct node *mergeList(struct node *list1,struct node *list2)
{
	struct node *list=list1;
	while(list && list2)
	{
		struct node *temp=list2;
		list2=list2->next;
		temp->next=list->next;
		list->next=temp;
		list=list->next->next;
	}
	return list1;
}

struct node *reorderList()
{
	struct node *slowPtr=head,*fastPtr=head;
	while(fastPtr->next && fastPtr->next->next)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
	}
	struct node *list2=reverse(slowPtr->next);
	slowPtr->next=0;
	struct node *list1=head;
	struct node *temp=mergeList(list1,list2);
	return temp;
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
	head=reorderList();
	printList();
	return 0;
}
