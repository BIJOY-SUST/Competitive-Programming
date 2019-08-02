#include<bits/stdc++.h>
#define mx 20003
using namespace std;
map<int,vector<int> >edges;
int color[mx];
int BFS(int n){
    queue<int>q;
    q.push(n);
    int Vampires=0,Lykans=0;///colour 1=vampires
    color[n]=1;             ///colour 2=lykans
    Vampires++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(color[v]==-1&&color[u]==1){
                color[v]=2;
                Lykans++;
                q.push(v);
            }
            else if(color[v]==-1){
                color[v]=1;
                Vampires++;
                q.push(v);
            }
        }
    }
    return max(Vampires,Lykans);
}
int Bipartite(){
    int ans=0;
    memset(color,-1,sizeof(color));
    for(int i=0;i<mx;i++){
        if(color[i]==-1&&!edges[i].empty()){
            ans+=BFS(i);
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int node;
        scanf("%d",&node);
        for(int j=1;j<=node;j++){
            int u,v;
            scanf("%d %d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        int ans=Bipartite();
        printf("Case %d: %d\n",i,ans);
        edges.clear();
    }
    return 0;
}
