#include<bits/stdc++.h>
using namespace std;
int M_C_S;
map<int,int>Parent;
map<int,int>Rank;
int find_par(int x){
    if(!Parent[x]==x) Parent[x]=find_par(Parent[x]);
    return Parent[x];
}
void Union(int u,int v){
    int pu=find_par(u);
    int pv=find_par(v);
    if(pu!=pv){
        M_C_S--;
        if(Rank[pu]>Rank[pv]) Parent[pv]=pu;
        else{
            Parent[pu]=pv;
            if(Rank[pu]==Rank[pv]) Rank[pv]++;/**This graph contains, however, a number of subgraphs that are connected,one for each of the following sets of nodes: {A}, {B}, {C}, {D}, {E}, {A,B}, {B,D}, {C,E}, {A,B,D}A connected subgraph is maximal if there are no nodes and edges inthe original graph that could be added to the subgraph and still leave it connected.**/
        }
    }
}
int main(){
    int T;
    bool flag=false;
    string s;
    scanf("%d\n",&T);
    while(T--){
        flag=true;
        getline(cin,s);
        int n;
        M_C_S=n=s[0]-'A'+1;
        for(int i=1;i<=n;i++){
            Parent[i]=i;
            Rank[i]=0;
        }
        while(1){
            getline(cin,s);
            if(s.empty()) break;
            int u=s[0]-'A'+1;
            int v=s[1]-'A'+1;
            Union(u,v);
        }
        if(flag=true) cout<<endl;
        cout<<M_C_S<<endl;
    }
    return 0;
}
