#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head1=0,*head2=0;
struct node * findMergeNodeSLL()
{
	struct node *list1=head1,*list2=head2;
	int count1=0,count2=0,i;
	while(list1)
	{
		count1++;
		list1=list1->next;
	}
	while(list2)
	{
		count2++;
		list2=list2->next;
	}
	int diff;
	if(count1>count2)
	{
		diff=count1-count2;
		list1=head1;
		list2=head2;
	}
	else
	{
		diff=count2-count1;
		list1=head2;
		list2=head1;
	}
	for(i=0;i<diff;i++)
		list1=list1->next;
	while(list1 && list2)
	{
		if(list1==list2)
			return list1;
		list1=list1->next;
		list2=list2->next;
	}
	return NULL;
}
/*void printList()
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
}*/
int main()
{
	struct node *node1=(struct node *)malloc(sizeof(struct node));
	node1->data=1;
	head1=node1;
	struct node *node2=(struct node *)malloc(sizeof(struct node));
	node2->data=2;
	node1->next=node2;
	struct node *node3=(struct node *)malloc(sizeof(struct node));
	node3->data=3;
	node2->next=node3;
	head2=node3;
	struct node *node4=(struct node *)malloc(sizeof(struct node));
	node4->data=4;
	node3->next=node4;
	struct node *node5=(struct node *)malloc(sizeof(struct node));
	node5->data=5;
	node4->next=node5;
	struct node *node6=(struct node *)malloc(sizeof(struct node));
	node6->data=6;
	node2->next=node6;
	node5->next=node6;
	struct node *node7=(struct node *)malloc(sizeof(struct node));
	node7->data=7;
	node6->next=node7;
	node7->next=NULL;
	
	struct node *temp=findMergeNodeSLL();
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	return 0;
}
