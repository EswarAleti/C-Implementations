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

struct node* mergeListsRecursive(struct node *head1,struct node *head2)
{
	if(!head1)
		return head2;
	if(!head2)
		return head1;
	struct node *mergedList;
	if(head1->data<=head2->data)
	{
		mergedList=head1;
		mergedList->next=mergeListsRecursive(head1->next,head2);
	}
	else
	{
		mergedList=head2;
		mergedList->next=mergeListsRecursive(head1,head2->next);
	}
	return mergedList;
}

struct node* mergeLists(struct node *head1,struct node *head2)
{
	struct node *mergedList=0,*temp;
	if(!head1)
		return head2;
	if(!head2)
		return head1;
	while(head1 && head2)
	{
		if(!mergedList)
		{
			if(head1->data < head2->data)
			{
				mergedList=head1;
				temp=mergedList;
				head1=head1->next;
			}
			else
			{
				mergedList=head2;
				temp=mergedList;
				head2=head2->next;
			}
		}
		else
		{
			if(head1->data < head2->data)
			{
				temp->next=head1;
				head1=head1->next;
				temp=temp->next;
			}
			else
			{
				temp->next=head2;
				head2=head2->next;
				temp=temp->next;
			}
		}
	}
	if(head1)
		temp->next=head1;
	else
		temp->next=head2;
	return mergedList;
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
	struct node *mergedList=mergeListsRecursive(head1,head2);
	printList(mergedList);
	return 0;
}
