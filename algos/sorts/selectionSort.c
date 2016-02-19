#include "stdio.h"

void selectionSort(int *A, int n){
	int i,j,minPosition;

	for (i = 0; i < n; ++i)
	{	
		minPosition = i;

		for (j = i+1; j < n; ++j)
		{
			if (A[j] < A[minPosition])
			{
				minPosition = j;
			}
		}

		if (minPosition != i)
		{
			int temp = A[minPosition];
			A[minPosition] = A[i];
			A[i] = temp;

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

		selectionSort(A,n);
		
		printf("Sorted Array : ");

		for (i = 0; i < n; ++i)
		{
			printf("%d ", A[i]);
		}

		printf("\n");
	}
	return 0;
}