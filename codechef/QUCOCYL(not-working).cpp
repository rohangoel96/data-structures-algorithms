#include <bits/stdc++.h>

 // g++ dijkstra.cpp -std=c++11 && ./a.out < data

using namespace std;

long long int n, m, c,f ,u, v, weight, source;
long long int  distance_arr[112345];
vector<pair<long long int, long long int> > graph[112345]; // an array of vectors that store an integer pair
pair<long long int, long long int> tpair, tpair2; // temporary pairs for insertion into heap and vectors
int c_arr[112345];
int f_arr[112345];

void dijkstra(int source){
	priority_queue<pair<long long int, long long int> > q;
	tpair.first = 0; // minimum _distance to source
	tpair.second = source;
	q.push(tpair);
	while(!q.empty()) {
		tpair = q.top();
		q.pop();
		long long int  minimum_distance = -tpair.first;
		long long int current_node = tpair.second;
		if (distance_arr[current_node] == -1) {
			distance_arr[current_node] = minimum_distance;
			for(auto neighbour: graph[current_node]) {  // g++ dijkstra.cpp -std=c++11 && ./a.out < data
				long long int next_node = neighbour.first;
				long long int dist = neighbour.second;
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
	cin >> n >> m >> c >> f;
	for (int i = 0; i < c; ++i)
	{
		cin >> c_arr[i];
	}
	for (int i = 0; i < f; ++i)
	{
		cin >> f_arr[i];
	}


	for(int i = 0; i < m; i += 1) {
		cin >> u >> v >> weight;
		tpair.first = v;
		tpair.second = weight;
		graph[u].push_back(tpair);
		// tpair.first = u;
		// tpair.second = weight;
		// graph[v].push_back(tpair);
	}
	
	for(int i = 0; i < n; i += 1) {
		distance_arr[i] = -1;
	}
	
	dijkstra(0);

	for (int i = 0; i < c; ++i)
	{
		tpair.first = c_arr[i];
		tpair.second = distance_arr[c_arr[i]];
		graph[n].push_back(tpair);
	}

	for(int i = 0; i <= n; i += 1) {
		distance_arr[i] = -1;
	}

	dijkstra(n);
	
	long long int temp, ans=1000000001;
	
	for (int i = 0; i < f; ++i)
	{
		temp = distance_arr[f_arr[i]];
		ans = ans < temp ? ans : temp; 

	}

	cout << ans << endl;
	
	// for(int i = 0; i < n; i += 1) {
	// 	cout << distance_arr[i] << " ";
	// }
	// cout << endl;
}

