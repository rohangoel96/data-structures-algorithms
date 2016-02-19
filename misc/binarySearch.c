#include "stdio.h"

int binarySearch(int *A, int l, int r, int element){
	int mid = (l+r)/2;
	
	if(l<r){
		if (element==A[mid])
		{
			return mid;
		}
		else if (element<A[mid])
		{
			return binarySearch(A, l, mid, element);
		}
		else if (element>A[mid]){
			return binarySearch(A, mid+1,r, element);
		}
	}
	else{
		return -1;
	}

}

int main(int argc, char const *argv[])
{
	int i,j,n,e;
	printf("Enter Size : ");
	scanf("%d",&n);
	
	int A[n];
	
	printf("Enter Array  : ");
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&A[i]);
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n-i-1; ++j)
		{
			if (A[j+1]<A[j])
			{	
				printf("Array Not Sorted. Try Again\n---------------------------\n");
				main(argc,argv);
			}
		}
	}
	printf("Enter element  : ");
	scanf("%d",&e);

	printf("Element found at position: %d\n",1+binarySearch(A,0,n,e));

	return 0;
}