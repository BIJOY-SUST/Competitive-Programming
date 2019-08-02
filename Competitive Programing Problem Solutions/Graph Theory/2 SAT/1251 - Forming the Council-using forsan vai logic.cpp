#include<bits/stdc++.h>

using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(x)      for(__typeof(x.begin()) it=(x.begin());it!=(x.end());++it)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<ll>edge[mx],r_edge[mx],top;
bool vis[mx];
ll scc[mx],colour;
void dfs(int u){
    vis[u]=true;
    forstl(edge[u]) if(!vis[*it]) dfs(*it);
    top.push_back(u);
}
void dfs2(int u){
    vis[u]=true;
    scc[u]=colour;
    forstl(r_edge[u]) if(!vis[*it]) dfs2(*it);
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll cs=1;cs<=t;cs++){
        for(ll i=0;i<mx;i++){
            edge[i].clear();
            r_edge[i].clear();
            scc[i]=0;
        }
        ll n,m;
        cin>>m>>n;
        ll x=m;
        while(x--){
            ll u,v;
            cin>>u>>v;
            if(u>0){
                if(v>0){
                    edge[n+u].push_back(v); //n+u is used for negation of u
                    edge[n+v].push_back(u);
                    r_edge[v].push_back(n+u);
                    r_edge[u].push_back(n+v);
                }
                else{
                    v=abs(v);
                    edge[n+u].push_back(n+v);
                    edge[v].push_back(u);
                    r_edge[n+v].push_back(n+u);
                    r_edge[u].push_back(v);
                }
            }
            else {
                if(v>0){
                    u=abs(u);
                    edge[u].push_back(v);
                    edge[n+v].push_back(n+u);
                    r_edge[v].push_back(u);
                    r_edge[n+u].push_back(n+v);
                }
                else{
                    u=abs(u);
                    v=abs(v);
                    edge[u].push_back(n+v);
                    edge[v].push_back(n+u);
                    r_edge[n+v].push_back(u);
                    r_edge[n+u].push_back(v);
                }
            }
        }
        mem(vis,false);
        for(ll i=1;i<=2*n;i++) if(!vis[i]) dfs(i);
        reverse(top.begin(),top.end());
        mem(vis,false);
        colour=0;
        forstl(top) if(!vis[*it]) ++colour,dfs2(*it);
        bool yes=false;
        for(ll i=1;i<=n;i++){
            if(scc[i]==scc[i+n]){
                yes=true;
                break;
            }
        }
        printf("Case %lld: ",cs);
        if(yes) cout<<"No"<<endl;
        else{
            vector<ll>ans;
            for(int i=1;i<=n;i++) if(scc[i]>scc[i+n]) ans.push_back(i);
            cout<<"Yes"<<endl;
            cout<<ans.size();
            forstl(ans) cout<<" "<<*it;
            cout<<endl;
        }
    }
    return 0;
}

