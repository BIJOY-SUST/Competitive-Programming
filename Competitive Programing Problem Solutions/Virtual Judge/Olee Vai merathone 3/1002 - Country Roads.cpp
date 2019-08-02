#include<bits/stdc++.h>
#define mx 10001
using namespace std;
int money[mx];
map<int,vector<int> >edges;
map<int,vector<int> >cost;
void BFS_Dijkstra(int home){
    queue<int>q;
    q.push(home);
    money[home]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(max(cost[u][i],money[u])<money[v]){
                money[v]=max(cost[u][i],money[u]);
                q.push(v);
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        memset(money,0,sizeof(money));
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) money[i]=INT_MAX;
        for(int j=1;j<=m;j++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int k;
        scanf("%d",&k);
        BFS_Dijkstra(k);
        for(int i=0;i<n;i++){
            if(money[i]==INT_MAX) printf("Impossible\n");
            else printf("%d\n",money[i]);
        }
        for(int i=0;i<mx;i++){
            edges[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
