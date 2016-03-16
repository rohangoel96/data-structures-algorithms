#include <bits/stdc++.h>
using namespace std;
 
vector<int> adjlist[112345];
int visited[112345];
int biparite;
 
void dfs(int current, int color) {

	// cout << current << " "<< color << endl;

	if (visited[current])
	{
		if (visited[current]!=color)
		{
			biparite = 0;
			return;
		}
	}

	else
	{
		visited[current] = color;
		for (int i = 0; i < adjlist[current].size(); ++i)
		{
			dfs(adjlist[current][i], (color==1) ? 2 : 1);	
		}
	}
}

 
int checkConnected(int n){
	for (int i = 1; i <=n ; ++i)
	{
		if(!visited[i]) return 0;
	}

	return 1;
}


int main() {
	int n, m, a, b, source, target;
	cin >> n >> m;
	for(int i = 0; i < m; i += 1) {
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	biparite = 1;
	//colors are 1 and 2, initial color = 1
	dfs(1,1);	

	cout << ((biparite && checkConnected(n)) ? "Bipartite" : "NOT Bipartite") <<endl;
	
	if(biparite && checkConnected(n))
	{
		cout << "Colours assigned to nodes:" << endl;
		for (int i = 1; i <= n; ++i)
		{
			cout << i << " " << visited[i] << endl;
		}
	}


}