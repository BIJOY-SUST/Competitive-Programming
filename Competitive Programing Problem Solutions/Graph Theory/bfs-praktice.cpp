#include<bits/stdc++.h>
using namespace std;
vector<int>edges[100000];
int visited[100000];
int BFS(int start,int finish){
    queue<int>q;
    q.push(start);
    memset(visited,-1,sizeof(visited));
    visited[start] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v = edges[u][i];
            if(visited[v]==-1){
                q.push(v);
                visited[v] = visited[u]+1;
            }
        }
    }
    return visited[finish];
}
int main(){
    int N,E;
    cin>>N>>E;
    for(int i=1;i<=E;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int start,finish;
    cin>>start>>finish;
    int y = BFS(start,finish);
    if(y!=-1){
        cout<<"The node is situated in this graph...Path distance : "<<y<<endl;
    }
    else{
        cout<<"The node isn't situated in this graph."<<endl;
    }
    return 0;
}
