#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=0;
void printList()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int findLengthOfLoop()
{
	struct node *slowPtr=head,*fastPtr=head;
	int flag=0,counter=0;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		while(slowPtr && fastPtr)
		{
			fastPtr=fastPtr->next;
			if(slowPtr==fastPtr)
				return counter;
			counter++;
		}
	}
	return counter;
}
int main()
{
	printList();
	struct node *node1=(struct node *)malloc(sizeof(struct node));
	node1->data=1;
	head=node1;
	struct node *node2=(struct node *)malloc(sizeof(struct node));
	node2->data=2;
	node1->next=node2;
	struct node *node3=(struct node *)malloc(sizeof(struct node));
	node3->data=3;
	node2->next=node3;
	node3->next=node1;
	/*struct node *node1=(struct node *)malloc(sizeof(struct node));
	node1->data=1;
	head=node1;
	struct node *node2=(struct node *)malloc(sizeof(struct node));
	node2->data=2;
	node1->next=node2;
	struct node *node3=(struct node *)malloc(sizeof(struct node));
	node3->data=3;
	node2->next=node3;
	struct node *node4=(struct node *)malloc(sizeof(struct node));
	node4->data=4;
	node3->next=node4;
	struct node *node5=(struct node *)malloc(sizeof(struct node));
	node5->data=5;
	node4->next=node5;
	node5->next=node2;*/
	printf("%d",findLengthOfLoop());
	return 0;
}
