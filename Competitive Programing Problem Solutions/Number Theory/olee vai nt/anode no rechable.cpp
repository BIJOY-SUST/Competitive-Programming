#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >edges;
map<int,int>visited;
void BFS(int start){
    queue<int>q;
    q.push(start);
    visited[start]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v = edges[u][i];
            if(!visited.count(v)){
                visited[v] = visited[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    int E,i=1;
    while(cin>>E&&E!=0){
        for(int i=1;i<=E;i++){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        int start,TTL;
        while(cin>>start>>TTL&&(start!=0||TTL!=0)){
            visited.clear();
            BFS(start);
            int N_reachable=0;
            map<int,int>::iterator it;
            for(it=visited.begin();it!=visited.end();it++){
                if(it->second>TTL){
                    N_reachable++;
                }
            }
            N_reachable += edges.size() - visited.size();
            cout<<"Case "<<i<<": "<<N_reachable<<" nodes not reachable from node "<<start<<" with TTL = "<<TTL<<"."<<endl;
            i++;
        }
        edges.clear();
    }
    return 0;
}
