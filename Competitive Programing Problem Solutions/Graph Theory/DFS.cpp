#include<bits/stdc++.h>
using namespace std;
vector<int>adj[5000];
int n,e;
void aa[5000];
int f(int k){
    aa[k] = 1;
    for(int i=0;i<adj[k].size();i++){
            int v=adj[u][i];
            if(aa[v]==0){
                f(v);
            }
        }
    }
}
int main(){
    int u,v,w;
    cin>>n>>e;
    memset(aa,0,sizeof(aa));
    for(int i=0;i<=e;i++){
        cin>>u>>v>>w;
        adj[u].push_back(v,w);
        adj[v].push_back(u,w);
    }
    int l;
    cin>>l;
    if(aa[10]==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
