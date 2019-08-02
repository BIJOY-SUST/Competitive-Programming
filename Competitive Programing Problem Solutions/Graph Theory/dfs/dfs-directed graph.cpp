#include<bits/stdc++.h>
using namespace std;
int n,e;
map<int,vector<int> >edges;
map<int,bool>visited;
map<int,bool>Stack;
using namespace std;
bool DFS(int u){
    if(!visited[u]){
        visited[u]=true;
        Stack[u]=true;
        for(int i=0;i<edges[u].size();i++){
            int v = edges[u][i];
            if(!visited[v]&&DFS(v)){
                return true;
            }
            else if(Stack[v]){
                return true;
            }
        }
    }
    Stack[u]=false;
    return false;
}
bool IsCyclic(){
    for(int i=0;i<n;i++){
        visited[i]=false;
        Stack[i]=false;
    }
    for(int i=0;i<n;i++){
        if(DFS(i)){
            return true;
        }
    }
    return false;
}
int main(){
    int u,v;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        edges[u].push_back(v);
    }
    IsCyclic()? cout<<"Yes"<<endl:cout<<"No"<<endl;
    return 0;
}
