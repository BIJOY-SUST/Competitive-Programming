#include<bits/stdc++.h>
#define mx 40001
using namespace std;
//map<int,vector<int> >edges;
//int cost[mx][mx];
//vector<long long int>cost;
vector<pair<long long int,int> >edges[mx];
bool visited[mx];
int ddd;
//int DFS(int u,long long int w){
//    visited[u]=true;
//    for(int i=u;i<edges[u].size();i++){
//        int v=edge[u][i];
//        int ccc=cost[u][i];
//        if(!visited[v]&&ccc>=w){
//            ddd++;
//        }
//    }
//}
int BFS(int start,long long int w){
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v = edges[u][i].second;
            long long int ccc=edges[u][i].first;
            //cout<<u<<" "<<v<<" "<<ccc<<endl;
            if(!visited[v]&&ccc>=w){
                //cout<<"kon kon"<<v<<endl;
                visited[v]=true;
                ddd++;
                q.push(v);
            }
        }
    }
    return ddd;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        int n,e;
        scanf("%d %d",&n,&e);
        for(int j=1;j<=e;j++){
            int u,v;
            long long int w;
            scanf("%d %d %lld",&u,&v,&w);
            edges[u].push_back(make_pair(w,v));
            edges[v].push_back(make_pair(w,u));
//            cost[u][v]=w;
//            cost[v][u]=w;
//              cost[u].push_back(make_pair(v,w));
//              cost[v].push_back(make_pair(u,w));
        }
        //cout<<cost[1][2]<<endl;
        int q;
        scanf("%d",&q);
        for(int j=1;j<=q;j++){
            long long int c;
            scanf("%lld",&c);
            ddd=0;
            memset(visited,false,sizeof(visited));
            int ans=BFS(1,c);
            printf("%d\n",ans);
        }
        for(int i=0;i<n;i++){
            edges[i].clear();
        }
    }
    return 0;
}
