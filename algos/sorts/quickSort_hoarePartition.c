#include "stdio.h"

int hoarePartition(int *A, int l, int r){
	int i=l-1,j=r+1;
	int pivotValue = A[l];

	while(1){
			do{i++;}
            while(A[i]<pivotValue);
            do{j--;}
            while(A[j]>pivotValue);
             
		if (i<j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else{
			return j;
		}
	}
}

//my first try, turns out to be lomuto modified. (use quicksort(A,l,pivot-1) then
// int hoarePartitionRohan(int *A, int l, int r) { 
// 	int pivot = A[l];
// 	int i = l;
// 	int j = r + 1;
// 	while(1) {
// 		do {
// 			j--;
// 		} while(A[j] > pivot);

// 		do {
// 			i++;
// 		} while(A[i] < pivot);

// 		if(i < j) {
// 			swap(A[i], A[j]);
// 		}
// 		else {
// 			swap(A[l], A[j]);
// 			return j;
// 		}
// 	}
// }
// 

ᐧ
void quickSort(int *A, int l, int r){
	if (l<r)
	{
		int pivot = hoarePartition(A,l,r);
		quickSort(A,l,pivot);
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