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
struct node * findStartOfLoop()
{
	struct node *slowPtr=head,*fastPtr=head;
	int flag=0;
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
		printf("Hiii\n");
		slowPtr=head;
		while(slowPtr && fastPtr)
		{
			if(slowPtr==fastPtr)
				return slowPtr;
			slowPtr=slowPtr->next;
			fastPtr=fastPtr->next;
		}
	}
	return NULL;
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
	struct node *node4=(struct node *)malloc(sizeof(struct node));
	node4->data=4;
	node3->next=node4;
	node4->next=node3;
	//printList();
	printf("%d",findStartOfLoop()->data);
	return 0;
}
