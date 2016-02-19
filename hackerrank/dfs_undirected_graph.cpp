#include <bits/stdc++.h>
using namespace std;
 
vector<int> adjlist[10];
int visited[10];
 
int dfs(int current, int target) {
	visited[current] = 1;
	if(current == target) {
		return 1;
	}
	for(int i = 0; i < adjlist[current].size(); i += 1) {
		if(!visited[adjlist[current][i]]) {
			if(dfs(adjlist[current][i], target) == 1) {
				return 1;
			}
		}
	}
	return 0;
}
 
 
int main() {
	int n, m, a, b, source, target;
	cin >> n >> m;
	for(int i = 0; i < m; i += 1) {
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	cin >> source >> target;
	cout << dfs(source, target) << endl;
}