#include<bits/stdc++.h>
using namespace std;
int n,e;
map<int,vector<int> >edges;
map<int,bool>visited;
vector<int>task;
void DFS(int u){
    visited[u]=true;
    task.push_back(u);
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!visited[v]){
            DFS(v);
        }
    }
    ///task.push_back(u);
}
int main(){
    int u,v;
    cin>>n>>e;
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<e;i++){
        cin>>u>>v;
        edges[u].push_back(v);
    }
    ///DFS(1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    for(int i=0;i<task.size();i++){
        cout<<task[i]<<" ";
    }
    cout<<endl;
    return 0;
}
