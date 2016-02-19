#include "stdio.h"

void bubbleSort(int *A, int n){
	int i,j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n-i-1; ++j)
		{
			if (A[j+1]<A[j])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
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

		bubbleSort(A,n);
		printf("Sorted Array : ");

		for (i = 0; i < n; ++i)
		{
			printf("%d ", A[i]);
		}

		printf("\n");
	}

	return 0;
}