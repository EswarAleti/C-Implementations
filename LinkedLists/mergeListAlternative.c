#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head1=0,*head2=0;

struct node *createList()
{
	int val;
	struct node *temp,*head=0;
	printf("Enter numbers consecutively ends with -1: ");
	while(1)
	{
		scanf("%d",&val);
		if(val==-1)
			return head;
			
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

struct node* mergeLists(struct node *list1,struct node *list2)
{
	struct node *mergeList=(struct node *)malloc(sizeof(struct node));
	struct node *temp=mergeList;
	while(list1 && list2)
	{
		temp->next=list1;
		list1=list1->next;
		temp=temp->next;
		temp->next=list2;
		list2=list2->next;
		temp=temp->next;
	}
	if(!list1)
		temp->next=list2;
	else
		temp->next=list1;
	mergeList=mergeList->next;
	return mergeList;
}

void printList(struct node *head)
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
	head1=createList();
	printList(head1);
	head2=createList();
	printList(head2);
	struct node *mergedList=mergeLists(head1,head2);
	printList(mergedList);
	return 0;
}
