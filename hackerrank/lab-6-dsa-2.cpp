#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> adjlist[100000];
int maxd=-1;
int random_farthest=0;

void dfs_tree(int current, int parent, int depth){

  // cout << current <<endl;
  depth++;
 
  if (adjlist[current].size()==1)
  {
    // cout<<"leaf"<<current<<depth<<endl;
 
    if (depth>maxd){ maxd = depth; random_farthest=current;}
  }

  for (int i = 0; i < adjlist[current].size(); ++i)
  {
    if (adjlist[current][i]!=parent)
    {
      dfs_tree(adjlist[current][i], current, depth);
    }
  }

}



int main(int argc, char const *argv[])
{
  int n,r,a,b;
  cin>>n;

  for (int i = 1; i < n; ++i)
  { cin>>a>>b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  }

  dfs_tree(1,-1,0);
  dfs_tree(random_farthest,-1,0);
  cout<<maxd-1<<endl;

  return 0;
}