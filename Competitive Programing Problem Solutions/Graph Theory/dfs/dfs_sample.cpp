#include<bits/stdc++.h>
using namespace std;
void DFS(int u){
    visited[u]=true;
    stack.push(u);
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!visited[v]){
            DFS(v);
        }
    }
}
int main(){
    reaf();
    DFS();
    return 0;
}
