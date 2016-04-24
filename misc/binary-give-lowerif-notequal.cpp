#include <bits/stdc++.h>
using namespace std;
 
int binarySearch(int *A, int low, int high, int value){
	
	while(low<=high){
		int mid = low + (high-low)/2;
		if(value < A[mid]){
			high = mid - 1;
		}
		else if(value > A[mid]){
			low = mid + 1;
		}
		else{
			return mid;
		}
	}
	return low - 1 ;
}


int main(int argc, char const *argv[])
{
	int A[5] = {4,8,10,13,20};
	cout << binarySearch(A, 0, 4, 1)<<endl;
	cout << binarySearch(A, 0, 4,  5)<<endl;
	cout << binarySearch(A, 0, 4 , 9)<<endl;
	cout << binarySearch(A, 0, 4, 11)<<endl;
	cout << binarySearch(A, 0, 4, 13)<<endl;
	cout << binarySearch(A, 0, 4, 21)<<endl;

}
