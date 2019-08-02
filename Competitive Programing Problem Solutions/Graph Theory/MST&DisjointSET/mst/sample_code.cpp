#include<bits/stdc++.h>
using namespace std;
class edge{
public:
    int w;
    char u,v;
    bool operator<(const edge &p)const{
        return w<p.w;
    }
};
vector<edge>e;
map<char,int>representative;
int find_par(int x){
    if(representative[x]!=x) representative[x]=find_par(representative[x]);
    return representative[x];
}
int MST(int n){
    sort(e.begin(),e.end());
    for(char i='a';i<=97+n;i++){
        representative[i]=i;
    }
    int c=0,ans=0;
    for(int i=0;i<(int)e.size();i++){
        int pu=find_par(e[i].u);
        int pv=find_par(e[i].v);
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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int w;
        char u,v;
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
