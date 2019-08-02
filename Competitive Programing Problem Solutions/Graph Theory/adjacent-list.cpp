#include<bits/stdc++.h>
using namespace std;
vector<int>edge[100000];
vector<int>cost[100000];
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(1);
        cost[v].push_back(1);
    }
    return 0;
}
