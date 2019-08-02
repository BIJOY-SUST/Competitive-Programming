#include<bits/stdc++.h>
using namespace std;
vector<int>edges[100000];
int visited[100000];
int n,e;
int bfs(int start,int end){
    queue<int>q;
    q.push(start);
    memset(visited,-1,sizeof(visited));
    visited[start] = 0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(visited[v]==-1){
                q.push(v);
                visited[v]=visited[u]+1;
            }
        }
    }
    return visited[end];
}

int main(){
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int start,finish;
    cin>>start>>finish;
    int y = bfs(start,finish);
    if(y!=-1){
        cout<<"This expected node situated in this graph...And the shortest path "<<start<<" to "<<finish<<" : "<<y<<endl;
    }
    else{
        cout<<"This expected node isn't situated in this graph."<<endl;
    }
    return 0;
}
