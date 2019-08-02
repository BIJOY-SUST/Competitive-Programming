#include<bits/stdc++.h>
using namespace std;
int n,e;
map<int,vector<int> >edges;
map<int,bool>visited;
vector<int>Stack;
void DFS(int u){
    visited[u]=true;

    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!visited[v]){
            DFS(v);
        }
    }Stack.push_back(u);
}
/*void DFS(int u){
    visited[u]=true;

    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!visited[v]){
            DFS(v);
        }
    }//Stack.push_back(u);
}*/
int main(){
    int T,u,v;
    cin>>T;
    while(T--){
        int c=0;
        cin>>n>>e;
        for(int i=1;i<=n;i++){
            visited[i]=false;
        }
        for(int i=1;i<=e;i++){
            cin>>u>>v;
            edges[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                DFS(i);
            }
        }
        reverse(Stack.begin(),Stack.end());
        //for(int i=0;i<Stack.size();i++){
           // cout<<Stack[i];
        //}
        for(int i=1;i<=n;i++){
            visited[i]=false;
        }
        for(int i=0;i<n;i++){
            int k=Stack[i];
            if(!visited[k]){
                DFS(k);
                c++;
            }
        }
        cout<<c<<endl;
        edges.clear();
        visited.clear();
        Stack.clear();
    }
    return 0;
}
