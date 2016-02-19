#include "stdio.h"

void merge(int *A, int l1, int mid, int r2){
	int r1=mid, l2=mid+1;
	int i=l1, j=l2;
	int k=0,h=0;
	int temp[r2-l1+1];

	while(i<=r1 && j<=r2){
		if (A[i]<A[j]){temp[k++] = A[i++];}
		else{temp[k++] = A[j++];}
	}

	while(i<=r1){temp[k++]=A[i++];}
	while(j<=r2){temp[k++]=A[j++];}

	while(h<r2-l1+1){
		A[l1+h]=temp[h];
		h++;
	}

}

void mergeSort(int *A, int l,int r){
	if (r-l>0)
	{
		int mid = (l+r)/2;
		mergeSort(A,l,mid);
		mergeSort(A,mid+1,r);
		merge(A,l,mid,r);
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

		mergeSort(A,0,n-1);
		
		printf("Sorted Array : ");

		for (i = 0; i < n; ++i)
		{
			printf("%d ", A[i]);
		}

		printf("\n");
	}
	return 0;
}