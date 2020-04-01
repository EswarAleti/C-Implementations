#include<stdio.h>

void merge(int A[], int L[], int n1, int R[], int n2)
{
	int i=0,j=0,k;
	for(k=0;k<n1+n2;k++)
	{
		if(i<n1)
		{
			if(j==n2 || L[i]<=R[j])
			{
				A[k]=L[i];
				i++;
			}
			else
			{
				A[k]=R[j];
				j++;
			}
		}
		else
		{
			if(j<n2)
			{
				A[k]=R[j];
				j++;
			}
		}
	}
}

void merge_sort(int A[], int n)
{
	if(n==1)
	{
		return;
	}
	int n1=n/2;
	int n2=n-n1;
	int L[n1],R[n2];
	int i;
	for(i=0;i<n1;i++)
	{
		L[i]=A[i];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=A[n1+i];
	}
	merge_sort(L,n1);
	merge_sort(R,n2);
	merge(A,L,n1,R,n2);
}

int main()
{
	int A[10]={5,2,7,9,3,1,4,10,6,8};
	int i;
	//Array pritning before sorting
	printf("\nArray before sorting: ");
	for(i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}
	
	//call merge_sort to sort the array A
	merge_sort(A,10);

	//Array printing after sorting
	printf("\nArray after sorting: ");
	for(i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
