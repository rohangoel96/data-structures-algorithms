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


int main() {

	int t;
	cin>>t;

	while(t--){

		long long int n,x,m;
		scanf("%lld %lld %lld", &n, &x, &m );
	  	long long int arr[n];

	  	for (long long int i = 0; i < n; ++i)
	  	{
	  		scanf("%lld", &arr[i]);
	  	}

	  	if (x==1)
	  	{
	  		printf("%lld\n",arr[0]% 1000000007);
	  	}

	  	else if(x==2) {
	  			printf("%lld\n", (arr[0]*m+arr[1])%1000000007);
	  	}

	  	else{
	  		
	  		for (long long int j = 0; j < m; ++j)
	  		{
	  			for (long long int i = 1; i < x; ++i)
		  		{
		  			arr[i] += arr[i-1]	;
		  		}

		  		// printArray(arr,n);

	  		}
	  		
	  		printf("%lld\n",(arr[x-1]% 1000000007));

	  	}

  	}

}


