#include <iostream>

using namespace std;


long long int findClosestSocket(long long int *working_sockets, long long int n, long long int allotted_index, long long int l){

	long long int low = 0;
	long long int high = n;
	long long int mid = (low+high)/2;
	long long int ans_index;
	long long int low_to_alloted=0,high_to_alloted=n;

	while(low<high){
		mid = (low+high)/2;
		
		if (working_sockets[mid]==allotted_index)
		{	
			ans_index = mid;
			return mid;
			break;
		}
		else if(allotted_index>working_sockets[mid]){
			low = mid+1;
			
		}
		else{
			high = mid-1;
			
		}
	}
	
		low_to_alloted = low;
		high_to_alloted = low+1;
		// cout << high<< " " << low<<n<<endl;
		if (low<n && low > -1)
		{	if (high==-1)
			{
				if (working_sockets[0] - allotted_index<=l)
					return 0;
				else return -1;
			}
			long long int length_to_left = allotted_index - working_sockets[low_to_alloted];
			long long int length_to_right = working_sockets[high_to_alloted] - allotted_index;

			if (length_to_left <= l || length_to_right <= l)
			{
				if (length_to_right<length_to_left)
				{
					ans_index = high_to_alloted;
				}
				else{
					ans_index = low_to_alloted;
				}
			}
			else{
				ans_index = -1;
			}
			
	
		}
		else{
			if (low>=n)
			{	
				long long int length_to_left = allotted_index - working_sockets[n-1];

				// cout <<length_to_left<<endl;
				if (length_to_left <= l)
				{
					ans_index = n-1;
				}
				else{
					ans_index = -1;
				}
			}
		}
	
	return ans_index;
}


int main() {

	long long int n,q,assigned,length;
	double temp_length;
	cin>>n>>q;
	long long int working[n];
	for (long long int i = 0; i < n; ++i){cin>>working[i];}

	for (long long int i = 0; i < q; ++i){
		cin>>assigned>>temp_length;
		length = (long long int) temp_length /2;
		long long int a = findClosestSocket(working,n,assigned,length);
		if (a!=-1)
		{
			cout<<working[a]<<endl;
		}
		else cout<<-1<<endl;
	}
}




