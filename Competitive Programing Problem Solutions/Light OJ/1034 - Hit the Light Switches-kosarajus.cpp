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
#define toint(s)       atoi(s.c_str())
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//********************************************Code Start Here*********************************************************//
vector<int>edge[mx];
vector<int>topsort;
bool vis[mx];
void dfs(int u){
    vis[u]=true;
    for(__typeof(edge[u].begin())it=edge[u].begin();it!=edge[u].end();it++){
        if(!vis[*it]) dfs(*it);
    }
    topsort.push_back(u);
    return;
}
void dfs2(int u){
    vis[u]=true;
    for(__typeof(edge[u].begin())it=edge[u].begin();it!=edge[u].end();it++){
        if(!vis[*it]) dfs2(*it);
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
        }
        mem(vis,false);
        for(int i=1;i<=n;i++){
            if(!vis[i]) dfs(i);
        }
        mem(vis,false);
        int ans=0;
        for(int i=topsort.size()-1;i>=0;i--){
            int u=topsort[i];
            if(!vis[u]) ans++,dfs2(u);
        }
        printf("Case %d: ",cs);
        cout<<ans<<endl;
        for(int i=0;i<mx;i++) edge[i].clear();
        topsort.clear();
    }
    return 0;
}
