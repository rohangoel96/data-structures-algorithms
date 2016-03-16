#include <bits/stdc++.h>

 // g++ dijkstra.cpp -std=c++11 && ./a.out < data

using namespace std;

int n, m, u, v, weight, distance_arr[112345], source;
vector<pair<int, int> > graph[112345]; // an array of vectors that store an integer pair
pair<int, int> tpair, tpair2; // temporary pairs for insertion into heap and vectors

void dijkstra(int source){
	priority_queue<pair<int, int> > q;
	tpair.first = 0; // minimum _distance to source
	tpair.second = source;
	q.push(tpair);
	while(!q.empty()) {
		tpair = q.top();
		q.pop();
		int minimum_distance = -tpair.first;
		int current_node = tpair.second;
		if (distance_arr[current_node] == -1) {
			distance_arr[current_node] = minimum_distance;
			for(auto neighbour: graph[current_node]) {  // g++ dijkstra.cpp -std=c++11 && ./a.out < data
				int next_node = neighbour.first;
				int dist = neighbour.second;
				if (distance_arr[next_node] == -1) {
					tpair2.first = -(minimum_distance + dist);
					tpair2.second = next_node;
					q.push(tpair2);
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i += 1) {
		cin >> u >> v >> weight;
		tpair.first = v;
		tpair.second = weight;
		graph[u].push_back(tpair);
		tpair.first = u;
		tpair.second = weight;
		graph[v].push_back(tpair);
	}
	
	for(int i = 0; i < n; i += 1) {
		distance_arr[i] = -1;
	}
	
	cin >> source;
	dijkstra(source);

	for(int i = 0; i < n; i += 1) {
		cout << distance_arr[i] << " ";
	}
	cout << endl;
}

