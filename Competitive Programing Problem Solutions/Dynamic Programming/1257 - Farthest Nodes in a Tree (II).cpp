//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define mx             30000
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
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
vector<pll >edge[mx];
ll node,temp_cnt;
ll dis1[mx],dis2[mx],dis[mx];
void dfs(ll u,ll par,ll cnt){
    if(temp_cnt<cnt){
        temp_cnt=cnt;
        node=u;
    }
    for(int i=0;i<edge[u].size();i++){
        pll v = edge[u][i];
        if(v.first!=par){
            dfs(v.first,u,cnt+v.second);
        }
    }
    return;
}
void dfs2(ll u,ll par,ll cnt){
    dis1[u]=cnt;
    for(int i=0;i<edge[u].size();i++){
        pll v = edge[u][i];
        if(v.first!=par){
            dfs2(v.first,u,cnt+v.second);
        }
    }
}
void dfs3(ll u,ll par,ll cnt){
    dis2[u]=cnt;
    dis[u]=max(dis1[u],dis2[u]);
    for(int i=0;i<edge[u].size();i++){
        pll v = edge[u][i];
        if(v.first!=par){
            dfs3(v.first,u,cnt+v.second);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        for(int i=0;i<mx;i++){
            edge[i].clear();
            dis[i]=dis1[i]=dis2[i]=0;
        }
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            ll u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            edge[u].push_back({v,w});
            edge[v].push_back({u,w});
        }
        temp_cnt=0;
        dfs(0,-1,0);
        temp_cnt=0;
        ll st=node;
        dfs(node,-1,1);
        ll en=node;
        dfs2(st,-1,0);
        dfs3(en,-1,0);
        printf("Case %d:\n",cs);
        for(int i=0;i<n;i++){
            printf("%lld\n",dis[i]);
        }
//        cout<<st<<" "<<en<<endl;
    }
    return 0;
}
/*

*/
