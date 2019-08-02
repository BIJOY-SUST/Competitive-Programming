#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define nl              '\n'
#define sf              scanf
#define pf              printf
#define F               first
#define S               second
#define pb              push_back
#define eb              emplace_back
#define ui              unsigned int
#define ll              long long int
#define ull             unsigned long long int
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<ll>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 1e5+10;
const ll inf       = (1LL<<62);
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here

struct data{
    int u,v,w;
    bool operator <(const data &p)const{
        return w<p.w;
    }
};
vector<data>adj,backadj;
vpii graph[mx];
int n,m,par[mx],level[mx],table[mx][105];
set<int>se;
ll taka[mx];
vll d[mx],dist(mx);

int findpar(int x){
    return par[x]==x?x:par[x]=findpar(par[x]);
}

void krus(){
    sort(all(adj));
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=0;i<m;i++){
        int pu=findpar(adj[i].u);
        int pv=findpar(adj[i].v);
        if(pu!=pv){
            par[pv]=pu;
            graph[adj[i].u].pb({adj[i].v,adj[i].w});
            graph[adj[i].v].pb({adj[i].u,adj[i].w});
        }
        else{
            se.insert(adj[i].u);
            se.insert(adj[i].v);
            backadj.pb(adj[i]);
        }
    }
    return;
}
void dfs(int u,int p,int d){
    par[u]=p;level[u]=d;
    for(auto v:graph[u]){
        if(v.F==p) continue;
        taka[v.F]+=taka[u]+v.S;
        dfs(v.F,u,d+1);
    }
    return;
}
void stable(){
    mem(table,-1);
    for(int i=1;i<=n;i++) table[i][0]=par[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(table[i][j-1]!=-1){
                table[i][j]=table[table[i][j-1]][j-1];
            }
        }
    }
    return;
}
ll query(int p,int q){
    if(level[p]<level[q]) swap(p,q);
    int logn=50;
    for(int i=logn;i>=0;i--){
        if(level[p]-(1<<i)>=level[q]){
            p=table[p][i];
        }
    }
    if(p==q) return p;
    for(int i=logn;i>=0;i--){
        if(table[p][i]!=-1 && table[p][i]!=table[q][i]){
            p=table[p][i];
            q=table[q][i];
        }
    }
    return table[p][0];
}
ll treedis(int u,int v){
    int lca=query(u,v);
    return taka[u]+taka[v]-2LL*taka[lca];
}

vll dij(int st){
    for(int i=0;i<=n;i++) dist[i]=inf;
    dist[st]=0;
    priority_queue<int,vi,greater<ll> >pq;
    pq.push(st);
    while(!pq.empty()){
        int u=pq.top();pq.pop();
        for(auto v:graph[u]){
            if(dist[u]+v.S<dist[v.F]){
                dist[v.F]=dist[u]+v.S;
                pq.push(v.F);
            }
        }
    }
    return dist;
}
void allc(){
    se.clear();
    for(int i=0;i<mx;i++){
        graph[i].clear();
        d[i].clear();
    }
    mem(par,0);
//    mem(table,0);
    mem(taka,0);
    mem(level,0);
    adj.clear();
    backadj.clear();
//    dist.clear();
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        allc();
        cin>>n>>m;
        int q;
        cin>>q;
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj.pb({u,v,w});
        }
        krus();
        dfs(1,-1,0);
        stable();
        for(auto x:backadj){
            graph[x.u].pb({x.v,x.w});
            graph[x.v].pb
            ({x.u,x.w});
        }
        for(auto x:se) d[x]=dij(x);
        cout<<"Case "<<cs<<":"<<nl;
        while(q--){
            int u,v;
            cin>>u>>v;
            ll ans=treedis(u,v);
    //        debug(ans);
            for(auto x:se){
                ans=min(ans,d[x][u]+d[x][v]);
            }
            cout<<ans<<nl;
        }
    }
    return 0;
}

