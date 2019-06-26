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
void evenOdd()
{
	struct node *temp,*list,*dummy;
	if(head->data%2!=0)
	{
		temp=head;
		while(temp->next)
		{
			if(temp->next->data%2==0)
			{
				dummy=temp->next;
				temp->next=temp->next->next;
				dummy->next=head;
				head=dummy;
				break;
			}
			temp=temp->next;
		}
	}
	list=head;
	temp=head;
	while(temp && temp->next)
	{
		if(temp->next->data%2==0 && temp->next!=list->next)
		{
			dummy=temp->next;
			temp->next=(temp->next)?temp->next->next:NULL;
			dummy->next=list->next;
			list->next=dummy;
			list=list->next;
		}
		else
			temp=temp->next;
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
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	createList();
	evenOdd();
	printList();
	return 0;
}
