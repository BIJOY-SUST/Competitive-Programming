#include<bits/stdc++.h>
using namespace std;
int n,e,l;
map<int,vector<int> >edges;
map<int,bool>visited;
void DFS(int h){
    visited[h]=true;
    int Size=edges[h].size();
    for(int i=0;i<Size;i++){
        int v=edges[h][i];
        if(!visited[v]){
            DFS(v);
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>e>>l;
        for(int i=1;i<=n;i++){
            visited[i]=false;
        }
        edges.clear();
        //edges.resize(10001);
        int u,v;
        for(int i=1;i<=e;i++){
            cin>>u>>v;
            edges[u].push_back(v);
        }
        int k;
        for(int i=1;i<=l;i++){
            cin>>k;
            DFS(k);
        }
        int c=0;
        for(int i=1;i<=n;i++){
            if(visited[i]){
                c++;
            }
        }
        cout<<c<<endl;
        edges.clear();
        visited.clear();
    }
    return 0;
}
