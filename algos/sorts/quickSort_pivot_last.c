#include "stdio.h"

int partition(int *A, int l, int r){
	int pivotValue = A[r]; //PIVOT ALWAYS TAKEN AS THE LAST ELEMENT
	int wall = l-1; //wall initialised to the left of first element 
	int i;

	for (i = l; i < r; ++i)
	{
	 	if (A[i] < pivotValue)
	 	{	
	 		//replace with the wall + 1 element
	 		int temp = A[wall+1];
	 		A[wall+1] = A[i];
	 		A[i] = temp;
	 		wall++;
	 	}
	}

	int pivotIndex = wall + 1;
	//bring the pivot to the right position
	int temp = A[pivotIndex];
	A[pivotIndex] = pivotValue; //pivotValue=A[r]
	A[r] = temp;
	
	return pivotIndex;

}


void quickSort(int *A, int l, int r){
	if (l<r)
	{
		int pivot = partition(A,l,r);
		quickSort(A,l,pivot-1);
		quickSort(A,pivot+1,r);
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

		quickSort(A,0,n-1);
		
		printf("Sorted Array : ");

		for (i = 0; i < n; ++i)
		{
			printf("%d ", A[i]);
		}

		printf("\n");
	}

	return 0;
}