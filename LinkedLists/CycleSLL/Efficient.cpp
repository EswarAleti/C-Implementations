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
bool isLoopInSLL()
{
	struct node *slowPtr=head,*fastPtr=head;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		if(slowPtr==fastPtr)
			return true;
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
	}
	return false;
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
	node3->next=node2;
	printf("%d",isLoopInSLL());
	return 0;
}
