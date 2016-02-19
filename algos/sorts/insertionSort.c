#include "stdio.h"

void insertionSort(int *A, int n){
	int i,j;

	for (i = 1; i < n; i++)
	{
		j = i;

		while(j>0 && A[j] < A[j-1])
		{	
			int temp = A[j];
			A[j] = A[j-1];
			A[j-1] = temp;
			j--;
		}
	}
}

void reverseInsertionSort(int *A ,int n){
	int i,j;

		for (i = 1; i < n; i++)
		{
			j = i;

			while(j>0 && A[j] > A[j-1])
			{	
				int temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				j--;
			}
		}
}


int main(int argc, char const *argv[])
{
	int i,j,n,testNo;

	printf("Enter No. of test cases : ");
	scanf("%d",&testNo);
	printf("\n");
	for (j = 0; j < testNo; ++j)
	{
		printf("Enter Size : ");
		scanf("%d",&n);
		
		int A[n];
		
		printf("Enter Array  : ");
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&A[i]);
		}

		insertionSort(A,n);
		// reverseInsertionSort
		printf("Sorted Array : ");

		for (i = 0; i < n; ++i)
		{
			printf("%d ", A[i]);
		}

		printf("\n");
	}


	return 0;
}