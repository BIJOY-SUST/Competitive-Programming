#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_set2 = tree<pair <T, string>, null_type, less<pair <T, string>>, rb_tree_tag, tree_order_statistics_node_update>;
//***********************************************Code Start Here************************************************************************************//
vector<int>edge[mx],redge[mx];
stack<int>topsort;
bool vis[mx];
void dfs(int u){
    vis[u]=true;
    for(auto x:edge[u]){
        if(!vis[x]) dfs(x);
    }
    topsort.push(u);
    return;
}
void dfs2(int u){
    vis[u]=true;
    cout<<u<<" ";
    for(auto x:redge[u]){
        if(!vis[x]) dfs2(x);
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
        for(int i=1;i<=n;i++){
            for(auto x:edge[i]){
                redge[x].push_back(i);
            }
        }
        mem(vis,false);
        int ans=0;
        while(!topsort.empty()){
            int u=topsort.top();
            topsort.pop();
            if(!vis[u]) ans++,dfs2(u);
            cout<<endl;
        }
        printf("Case %d: ",cs);
        cout<<ans<<endl;
        for(int i=0;i<mx;i++) edge[i].clear(),redge[i].clear();
    }
    return 0;
}
/*
5
5 5
2 1
1 3
3 2
1 4
4 5
*/
