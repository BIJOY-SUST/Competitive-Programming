#include<bits/stdc++.h>
using namespace std;
int n,e;
map<int,vector<int> >edges;
map<int,bool>visited;
bool DFS(int vertex,int parent){
    visited[vertex]=true;
    for(int i=0;i<edges[vertex].size();i++){
        int c=edges[vertex][i];
        if(!visited[c]){
            if(DFS(c,vertex)){
                return true;
            }
        }
        else if(c!=parent){
            return true;
        }
    }
    return false;
}
bool isCyclic(){
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(DFS(i,-1)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int u,v;
    while(cin>>n>>e){
    for(int i=0;i<e;i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    isCyclic()? cout<<"Yes"<<endl:cout<<"No"<<endl;
    edges.clear();
    visited.clear();
    }
    return 0;
}
