#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

//Function to print the array
void print_array(int a[] , int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf("%d ",a[i]);
	}

}

//Function that return index of val in array if val existed in array, -1 otherwise
int BinarySearch(int a[] , int low ,int high ,int val, float *comp)
{
	int mid;
	if(low <= high)
	{
		//Increment the comparisions
		(*comp)++;
		mid = (low+high) / 2;
		//If val found then return index
		if(a[mid] == val)
		{
			return mid;
		}
		//If val is greater than current value then search right sub array
		else if(a[mid] < val)
		{
			return BinarySearch(a , mid+1 , high , val,comp);
		}
		//else search the left subarray
		return BinarySearch(a , low , mid-1 , val,comp);
	}
	return -1;
}

//swap function
void swap(int *element1ptr , int *element2ptr)
{
	int c = *element1ptr;
	*element1ptr = *element2ptr;
	*element2ptr = c;
}

//implementation of selection sort
void SelectionSort(int a[] , int n ,long long *swaps , long long *comp)
{
	int i , min_index ,j;
	for(i = 0 ; i < n-1 ;i++)
	{
		min_index = i;
		for(j = i+1 ; j< n ;j++)
		{
			//Increment comparisions by 1
			(*comp)++;
			if(a[j] < a[min_index])
			{
				min_index = j;
			}
		}
		//Increment swaps by 1
		(*swaps)++;
		swap(&a[i] , &a[min_index]);
	}

}
int main()
{
	int arr[N] ,i,res;
	long long  swaps=0 , comp = 0;
	srand(time(0));
	for(i = 0 ; i < N ; i++)
	{
		arr[i] = rand() % N + 1;
	}
	//printf("\n\nInitial Random array :");
	//print_array(arr , N);
	SelectionSort(arr , N , &swaps ,&comp);
	//printf("\n\nSorted array:");
	//print_array(arr , N);
	printf("\nNumber of elements in array: %d",N);
	printf("\nNumber of Swaps in selection sort:%lld",swaps);
	printf("\nNumber of Comparisions in selection sort:%lld",comp);

	float total_comp=0;
	for(i=0;i<N;i++)
	{
		BinarySearch(arr, 0 ,N-1,arr[i] ,&total_comp);	
	}
	printf("\nAverage comparisions in BinarySearch: %f",total_comp/N);
	return 0;
}