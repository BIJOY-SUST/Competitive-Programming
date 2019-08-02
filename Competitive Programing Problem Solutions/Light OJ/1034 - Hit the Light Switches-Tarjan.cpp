//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

//#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define mx             100010
//#define inf            0x3f3f3f3f
//#define mod            1000000007
//#define PI             2*acos(0.0)
//#define E              2.71828182845904523536
//#define ll             long long int
//#define ull            unsigned long long int
//#define pii            pair<int,int>
//#define pll            pair<ll,ll>
//#define toint(s)       atoi(s.c_str())
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
//template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
//template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
//template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template <typename T> using ordered_set2 = tree<pair <T, string>, null_type, less<pair <T, string>>, rb_tree_tag, tree_order_statistics_node_update>;
//***********************************************Code Start Here************************************************************************************//
vector<int>edge[mx],edge2[mx];
stack<int>topsort;
int low[mx],disc[mx],scc[mx];
bool vis[mx];
int cnt,ans,cur_source;
void tarjan_scc(int u){
    vis[u]=true;
    topsort.push(u);
    low[u]=disc[u]=++cnt;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
//        cout<<u<< " "<<v<<endl;
        if(disc[v]==0){
            tarjan_scc(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],disc[v]);
    }
    if(low[u]==disc[u]){
        int v;
        ++cur_source;
        do{
            v=topsort.top();
            topsort.pop();
            vis[v]=false;
            scc[v]=cur_source;
//            cout<<v<<" "<<cur_source<<endl;
        } while(v!=u);
//        cout<<endl;
    }
    return;
}
void dfs(int u){
    if(vis[u]) return;
    vis[u]=true;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(scc[u]!=scc[v]) edge2[scc[u]].push_back(scc[v]);
        dfs(v);
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        for(int i=0;i<mx;i++){
            edge[i].clear();
            edge2[i].clear();
            low[i]=0;
            disc[i]=0;
            scc[i]=0;
        }
        int n,m;
        cnt=0,ans=0,cur_source=0;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
        }
//        cout<<endl;
        mem(vis,false);
        for(int i=1;i<=n;i++){
            if(disc[i]==0) tarjan_scc(i);
        }
        mem(vis,false);
        for(int i=1;i<=n;i++){
            if(vis) dfs(i);
        }
        vector<int>arr(mx,0);
        for(int i=1;i<=cur_source;i++){
            for(int j=0;j<edge2[i].size();j++){
                arr[edge2[i][j]]++;
            }
        }
        for(int i=1;i<=cur_source;i++){
//            cout<<i<<" "<<arr[i]<<endl;
            if(arr[i]==0) ++ans;
        }
        cout<<"Case "<<cs<<": "<<ans<<endl;
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
gggggggggggggg
2 1

3 2

1 3

4 4
kkkkkkkkkkkkkk
1 2
2 2
3 0
4 0
*/

