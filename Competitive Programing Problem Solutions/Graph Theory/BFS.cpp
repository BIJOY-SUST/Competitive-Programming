#include<bits/stdc++.h>
using namespace std;
vector<int>adj[5000];
int n,e;
int aa[5000];
int f(int start,int end){
    queue<int>q;
    q.push(start);
    memset(aa,-1,sizeof(aa));
    aa[start] = 0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(aa[v]==-1){
                q.push(v);
                aa[v]=aa[u]+1;
            }
        }
    }
    return aa[end];
}

int main(){
    int u,v,w;
    cin>>n>>e;
    for(int i=0;i<=e;i++){
        cin>>u>>v>>w;
        adj[u].push_back(v,w);
        adj[v].push_back(u,w);
    }
    int start,end;
    cin>>

    return 0;
}
