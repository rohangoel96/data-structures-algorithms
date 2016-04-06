#include <bits/stdc++.h>
using namespace std;
 

int size[1123456];
int arr[112346];

void makeset(int n){
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
		size[i] = 1;
	}
}

int root(int i)
{
    while(arr[i] != i)           //chase parent of current element until it reaches root.
    {
    	i = arr[i];
    }
    
    return i;
}

void union(int a, int b){
	int rootA = root(a);
	int rootB = root(b);

	if(size[rootA] < size[rootB]){
		arr[rootA] = arr[rootB];
		size[rootB] += size[rootA];
	}
	else{
		arr[rootB] = arr[rootA];
		size[rootA] += size[rootB];
	}
}

bool connected(int a, int b){
	return root(a) == root(b);
}

