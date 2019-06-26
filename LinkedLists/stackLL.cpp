#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int val)
{
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=val;
	if(!top)
	{
		top=newNode;
		top->next=NULL;
		return;
	}
	newNode->next=top;
	top=newNode;
}
int pop()
{
	if(!top)
	{
		printf(" ************ Under Flow ************ ");
		return -1;
	}
	int val=top->data;
	struct node *temp=top;
	top=top->next;
	free(temp);
	return val;	
}
int topOfStack()
{
	if(!top)
	{
		printf(" ************ Under Flow ************ ");
		return -1;
	}
	return top->data;
}
bool isStackEmpty()
{
	if(!top)
		return true;
	return false;
}
void displayStack()
{
	printf(" ************ Data on stack from top to bottom ************ \n");
	struct node *temp=top;
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
main()
{
	int val;
	push(81);
	push(23);
	push(91);
	push(23);
	push(59);
	displayStack();
	printf("\nTop of stack: %d\n",topOfStack());
	for(int i=0;i<5;i++)
	{
		val=pop();
		if(val!=-1)
			printf("\nPopped Data: %d\n",val);	
	}
	val=topOfStack();
	if(val!=-1)
		printf("\nTop of stack is: %d\n",val);
	if(isStackEmpty())
		printf("\nStack is empty\n");
	else
		printf("\nStack is not empty\n");
}
