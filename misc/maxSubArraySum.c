#include "stdio.h"

void maxSubArraySum(int *A, int n){

}

int main(int argc, char const *argv[])
{
	int i,n;
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

	return 0;
}