#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




void printArray(long long int* A, int n){
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<" ";;
	}

	cout<<endl;
}


long long int binarySearch(long long int*A, long long int l, long long int r, long long int c,long long int n){
	long long ans=-1;
	while(l<=r){

		// cout<<"Check"<<l<<r<<endl;

		long long int mid = (l+r)>>1;
		long long int cows=1;
		long long int index_wrt_diff = 0;
		long long int i=1;

		// cout<<"MID"<<mid;
		// cout<<"INDEXES :";
		

		for (int i = 0; i < n; ++i)
		{
			
			if (A[i]-A[index_wrt_diff]>=mid)
			{	// cout<<index_wrt_diff;
				cows++;
				index_wrt_diff = i;
			}
		}








		// cout<<"COWS:"<<cows<<endl;
		if (cows<c)
		{
			r=mid-1;
		}
		else{
			l = mid+1;
			if (mid>ans)
			{
				ans=mid;
			}
			
		}

	}

	return ans;

}



int main() {

	int t;
	cin>>t;

	while(t--)
	{
		long long int n,c;
		cin>>n>>c;
		long long int arr[n];
		for(int i=0;i<n;i++)cin>>arr[i];
		sort(arr,arr+n);

		cout<<binarySearch(arr,arr[0],arr[n-1]-arr[0],c,n);



	}


}


