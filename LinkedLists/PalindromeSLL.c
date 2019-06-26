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
	struct node *temp1=0,*temp2=0;
	while(head)
	{
		temp2=head->next;
		head->next=temp1;
		temp1=head;
		head=temp2;
	}
	return temp1;
}
int isPalindrome()
{
	struct node *slowPtr=head,*fastPtr=head;
	while(fastPtr->next && fastPtr->next->next)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
	}
	slowPtr->next=reverse(slowPtr->next);
	struct node *temp1=head;
	struct node *temp2=slowPtr->next;
	while(temp2)
	{
		if(temp1->data != temp2->data)
		{
			slowPtr->next=reverse(slowPtr->next);
			return 0;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	slowPtr->next=reverse(slowPtr->next);
	return 1;
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
	if(isPalindrome())
		printf("Yes\n");
	else
		printf("No\n");
	printList();
	return 0;
}
