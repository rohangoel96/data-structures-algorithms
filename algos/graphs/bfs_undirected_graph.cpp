#include <bits/stdc++.h>
using namespace std;
 
vector<int> adjlist[10];
int visited[10];
 
int bfs(int root) {
	queue <int> q;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if (!visited[top])
		{
			visited[top] = 1;
			cout << top << " ";

			for (int i = 0; i < adjlist[top].size(); ++i)
			{
				q.push(adjlist[top][i]);
			}
		}
	}
}
 
 
int main() {
	int n, m, a, b, source, target;
	cin >> n >> m;
	for(int i = 0; i < m; i += 1) {
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	bfs(0);
}

// MAYBE WRONG
//THIS IS CORRECT


// Breadth-First-Search(Graph, root):

//     for each node n in Graph:            
//         n.distance = INFINITY        
//         n.parent = NIL

//     create empty queue Q      

//     root.distance = 0
//     Q.enqueue(root)                      

//     while Q is not empty:        
            
//         current = Q.dequeue()
    
//         for each node n that is adjacent to current:
//             if n.distance == INFINITY:
//                 n.distance = current.distance + 1
//                 n.parent = current
//                 Q.enqueue(n)
