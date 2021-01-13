#include<bits/stdc++.h>
using namespace std;
void bfs(int src,int adj[1005][1005],int n){
    int dis[1005];
    int par[1005];
    queue q;
    for(int i; i <= n; i++){
        dis[i] = 100000000;
        par[i];
    }
    dis[src] = 0;
    q.push(src);
    while(q.size()>0){
        int u = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(adj[u][i]==1){
                if(dis[i]>dis[u]+1){
                    dis[i] = dis[u] + 1;
                    par[i] = u;
                    printf("%d ",i);
                    q.push(i);
                }
            }
        }
    }
}
int main(){
    int s[7][7] = {{0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0}

    };
    bfs(4,s,7);
    return 0;
}
