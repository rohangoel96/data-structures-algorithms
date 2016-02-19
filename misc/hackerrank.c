#include "stdio.h"

void printArray(int *A, int l ,int r){
	int i=0;
	for (i = l; i <= r; ++i)
	{
		printf("%d", A[i]);
	}
	printf("\n");
}

int partition(int *A, int l, int r){
	int pivotValue = A[l];
	int i,j=0;
	int B[r-l+1];

	for (i = l+1; i < r-l+1; i++)
	{
		if (A[i]<pivotValue)
		{
			B[j++] = A[i];
		}
	}
	int pivotIndex = j;
	B[j++] = pivotValue;

	for (i = l+1; i < r-l+1; i++)
	{
		if (A[i]>pivotValue)
		{
			B[j++] = A[i];
		}
	}

	for (i = 0; i < r-l+1; i++)
	{
			A[l+i] = B[i];
		
	}
	printArray(A,l,r);
	return pivotIndex;
}


void quickSort(int *A, int l, int r){
	if (r-l>0)
	{ printArray(A,l,r);
		int pivotIndex = partition(A,l,r);
		quickSort(A,l,pivotIndex-1);
		quickSort(A,pivotIndex+1,r);
	}
}



int main(int argc, char const *argv[])
{
	int i,j,n,testNo;

	// printf("Enter No. of test cases : ");
	// scanf("%d",&testNo);
	// printf("\n");
	// for (j = 0; j < testNo; ++j)
	// {
		// printf("Enter Size : ");
		scanf("%d",&n);
		
		int A[n];
		
		// printf("Enter Array  : ");
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&A[i]);
		}

		// quickSort(A,0,n-1,n-1);
		quickSort(A,0,n-1);
		// printf("Sorted Array : ");

		for (i = 0; i < n; ++i)
		{
			printf("%d ", A[i]);
		}

	// 	printf("\n");
	// }

	return 0;
}