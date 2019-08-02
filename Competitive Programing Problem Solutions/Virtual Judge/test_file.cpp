#include<bits/stdc++.h>
using namespace std;
vector<int>edges[10000];
int color[1000];
int n,e;
bool isBipartite(int n){
    queue<int>q;                    ///0 1 0 1
    q.push(n);                              ///1 0 1 0
    memset(color,-1,sizeof(color));         ///0 1 0 1
    color[n]=1;                             ///1 0 1 0
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(color[v]==-1){
                color[v]=1-color[u];
                q.push(v);
            }
            else if(color[u]==color[v]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    while(cin>>n){
    if(n==0){
        break;
    }
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    isBipartite(0) ? cout<<"BICOLORABLE."<<endl:cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}

/*while (!q.empty()){
        q.pop();
    }*/
