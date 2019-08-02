#pragma comment(linker, "/stack:200000000")
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
#define ump             unordered_map
#define uset            unordered_set
#define PQ              priority_queue
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define grtsrt(v)       sort(v.begin(),v.end(),greater<int>())
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 3e5+10;
const int inf       = 0x3f3f3f3f;
const int mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
bool mark[mx];vector<int>prime;
void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(mx);i+=2){if(mark[i]){for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///code start here

vi edge[mx];
set<int>ans[mx];
int low[mx],disc[mx],scc[mx];
int cnt,cnt2;
map<pii,bool>rasta;
map<pii,int>ami;
bool vis[mx];

void tarjan(int u,int pre){
    low[u]=disc[u]=++cnt;
    vis[u]=1;
    for(auto v:edge[u]){
        if(!vis[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u]){
                if(ami[{u,v}]==1){
                    rasta[{min(u,v),max(u,v)}]=1;
                }
            }
        }
        else if(v!=pre) low[u]=min(low[u],disc[v]);
    }
    return;
}
void dfs(int u){
    vis[u]=1;
    scc[u]=cnt2;
    for(auto v:edge[u]){
        if(vis[v]) continue;
        if(rasta.find({min(u,v),max(u,v)})==rasta.end()){
            dfs(v);
        }
    }
    return;
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    int e,k,n,u,v,x,y;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        edge[x].pb(y);
        edge[y].pb(x);
        ami[{x,y}]++;
        ami[{y,x}]++;
    }
    cnt=0;
    mem(vis,0);
    tarjan(1,0);
    cnt2=1;
    mem(vis,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            cnt2++;
        }
    }
    for(int i=1;i<=n;i++){
        for(auto j:edge[i]){
            if(rasta.find({i,j})!=rasta.end()){
                ans[scc[i]].insert(scc[j]);
                ans[scc[j]].insert(scc[i]);
            }
        }
    }
    int cc=0;
    for(int i=1;i<cnt2;i++){
        if(ans[i].size()==1) cc++;
    }
    if(cc>2){
            cout<<"NO"<<nl;
    }
    else{
        cout<<"YES"<<nl;
    }

    return 0;
}
/*

*/
