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

struct node *reverse(struct node *head,int k)
{
	if(!head)
		return 0;
	if(!head->next)
		return head;
	struct node *first=0,*next=0;
	while(k)
	{
		next=head->next;
		head->next=first;
		first=head;
		head=next;
		k--;
	}
	return first;
}

void blockReverse(int k)
{
	//Counting number of blocks
	struct node *temp=head;
	int count=0;
	while(temp)
	{
		temp=temp->next;
		count++;
	}
	int noOfBlocks=count/k;
	
	//Getting node address of first node of each block except first block
	struct node *arr[noOfBlocks];
	temp=head;
	int index=0,var=noOfBlocks,flag=0;;
	while(var)
	{
		int dummy=k;
		while(temp && dummy)
		{
			temp=temp->next;
			dummy--;
		}
		if(temp)
			arr[index++]=temp;
		var--;
	}
	
	struct node *list;
	temp=head;
	index=0,var=noOfBlocks;
	while(var--)
	{
		//For first block
		if(!flag)
		{
			head=reverse(temp,k);
			flag=1;
			list=head;
		}
		//For all other blocks
		else
		{
			while(list->next)
			{
				list=list->next;
			}
			//Append first node to next of list
			list->next=reverse(arr[index++],k);
		}
	}
	//If there are un reversed nodes
	if(count%k!=0 && count>=k)
	{
		while(list->next)
		{
			list=list->next;
		}
		list->next=arr[index];	
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
	blockReverse(5);
	printList();
	return 0;
}
