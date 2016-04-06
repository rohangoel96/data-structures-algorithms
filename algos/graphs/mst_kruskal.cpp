//Single number representing the total weight of the minimum spanning tree on this graph.
// There will be only one possible MST.


//https://www.hackerearth.com/notes/disjoint-set-union-union-find/


#include <bits/stdc++.h>
using namespace std;

int size[112345];
int arr[112345];
pair<int, pair<int, int> >  edges[112345]; 
pair<int, pair<int, int> > tpair, edge;

void makeset(int n){
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
		size[i] = 1;
	}
}

int root(int i)
{
    while(arr[i] != i)   
    {
    	i = arr[i];
    }
    
    return i;
}

void set_union(int a, int b){
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


int main(){

	int n, m, u, v, w, s;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;
		tpair.first = w;
		tpair.second.first = u;
		tpair.second.second = v;
		edges[i] = tpair;
	}

	int weight_mst = 0;

	sort(edges, edges + m);

	makeset(n+1); //indexing 1 to n

	for (int i = 0; i < m; ++i)
	{
		edge = edges[i];
		if (!connected(edge.second.first, edge.second.second))
		{
			set_union(edge.second.first, edge.second.second);
			weight_mst+= edge.first;
		}
	}

	cout << weight_mst;

	return 0;
}