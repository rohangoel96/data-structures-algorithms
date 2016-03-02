#include <bits/stdc++.h>
using namespace std;
 
vector<int> adjlist[112345];
int maxd = -1;
int maxele = -1;

void dfs(int current, int parent, int depth){

	depth++;
	if (depth > maxd)
	{
		maxd = depth;
		maxele = current;
	}

	for (int i = 0; i < adjlist[current].size(); ++i)
	{
		if (adjlist[current][i]!=parent)
		{
			dfs(adjlist[current][i], current, depth);
		}		
	}
}



int main(int argc, char const *argv[])
{

	//assuming a correct tree will be given, not a graph

	int n, m, a, b, diameter;
	cin >> n >> m;

	for(int i = 0; i < m; i += 1)
	{
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	//trivial condition to be a tree

	if (!(m==n-1)) cout << "Not a Tree" << endl;
	
	else{

		//find the diameter
		dfs(1,-1,0);
		dfs(maxele, -1, 0);

		//path(linear) graph diameter = n-1
		diameter = maxd - 1;

		// cout << diameter<< endl;

		if (diameter == n-1) cout << "Path Graph" << endl; 
		else cout << "Not a Path Graph" << endl;
	}
	return 0;
}