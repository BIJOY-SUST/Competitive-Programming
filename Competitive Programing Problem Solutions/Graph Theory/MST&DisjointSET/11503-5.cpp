#include<bits/stdc++.h>
using namespace std;
int parent[100000+10];
int find_parent(int x){
    if(parent[x]<0) return x;
    return parent[x]=find_parent(parent[x]);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int indegree=1;
        memset(parent,-1,sizeof(parent));
        map<string,int>representative;
        for(int i=1;i<=n;i++){
            string u,v;
            cin>>u>>v;
            if(!representative[u]) representative[u]=indegree++;
            if(!representative[v]) representative[v]=indegree++;
            int pu=find_parent(representative[u]);
            int pv=find_parent(representative[v]);
            if(pu==pv){
                printf("%d\n",parent[pu]*-1);
                continue;
            }
            if(parent[pu]<parent[pv]){
                parent[pu]+=parent[pv];
                parent[pv]=pu;
                printf("%d\n",parent[pu]*-1);
            }
            else{
                parent[pv]+=parent[pu];
                parent[pu]=pv;
                printf("%d\n",parent[pv]*-1);
            }
        }
    }
    return 0;
}
