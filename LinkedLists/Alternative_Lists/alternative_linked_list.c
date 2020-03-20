#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *next;
};
typedef struct node Node;

Node *interleave_list(Node *head1, Node *head2)
{
	//If head1 is NULL then head2 will be the alternative list
	if(head1==NULL)
	{
		return head2;
	}
	//initialize list Node as head1
	Node *list=head1;
	//Iterate until we reach end of any list
	while(list->next!=NULL && head2!=NULL)
	{
			//initialize temp Node as head1
			Node *temp=head2;
			//Move the head2 to next node
			head2=head2->next;
			//Insert temp node
			temp->next=list->next;
			list->next=temp;
			//Move to 2nd next node of list
			list=list->next->next;
	}
	//If head2 has at least one element then append to the list
	if(head2!=NULL)
	{
		list->next=head2;	
	}
	//return head1
	return head1;
}

struct node *create_list()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	if(n==0)
	{
		return NULL;
	}
	Node *head=NULL,*tail=NULL;
	int val,i;
	printf("Enter values of nodes: ");
	for(i=0;i<n;i++)
	{
		Node *new_node=(Node *)malloc(sizeof(Node));
		scanf("%d",&val);
		new_node->val=val;
		new_node->next=NULL;
		if(i==0)
		{
			head=new_node;
			tail=new_node;
		}
		else
		{
			tail->next=new_node;
			tail=new_node;
		}
	}
	return head;
}

void display(Node *head)
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	printf("Elements in list are: ");
	Node *temp=head;
	while(temp)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
}

int main()
{
	Node *head1 = create_list();
	Node *head2 = create_list();
	Node *head = interleave_list(head1,head2);
	display(head);	
	return 0;
}
