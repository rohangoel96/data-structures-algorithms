#include<bits/stdc++.h>
using namespace std;

int main() 
{
   
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<int>adjlist[1001];
        int distance[1001];
         for(int i=0;i<1001;i++)
    {
            
        distance[i]=-1;    
              //printf("%d ",distance[i]);
    }
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            adjlist[x].push_back(y);
            adjlist[y].push_back(x);
        }
        int s;
        scanf("%d",&s);
        queue<int>q;
        q.push(s);
        distance[s]=0;
        int c;
        while(!q.empty())
        {
         
            c=q.front();
           printf("%d ",c);
            q.pop();
            for(int i=0;i<adjlist[c].size();i++)
            {
                if(distance[adjlist[c][i]]==-1)
                {
                    distance[adjlist[c][i]]=distance[c]+1;
                    q.push(adjlist[c][i]);
                }
                
            }
        }
        for(int i=1;i<=n;i++)
        {
           if(i!=s)
            {
                if(distance[i]==-1)
                    printf("-1 ");
                else
                    printf("%d ",distance[i]);
            }
        }
        
        printf("\n");
    }
    return 0;
}