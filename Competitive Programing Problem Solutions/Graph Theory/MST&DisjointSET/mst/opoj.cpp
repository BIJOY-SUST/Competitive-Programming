#include<bits/stdc++.h>
using namespace std;
struct edge{
    long long u,v,w;
    bool operator<(const edge& p)const{
        return w<p.w;
    }
};
vector<edge>e;
long long representative[10001];
int find_par(long long x){
    if(representative[x]!=x) representative[x]=find_par(representative[x]);
    return representative[x];
}
int MST(int n){
    sort(e.begin(),e.end());
    for(char i=1;i<=n;i++){
        representative[i]=i;
    }
    long long c=0,ans=0;
    for(int i=0;i<(int)e.size();i++){
        long long pu=find_par(e[i].u);
        long long pv=find_par(e[i].v);
        if(pu!=pv){
            representative[pu]=pv;
            c++;
            ans+=e[i].w;
            if(c==n-1){
                break;
            }
        }
    }
    return ans;
}
int main(){
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        edge ob;
        ob.u=u;
        ob.v=v;
        ob.w=w;
        e.push_back(ob);
    }
    cout<<MST(n)<<endl;
    return 0;
}

