/// Below a code here which will be Optimized.
///If we find LCA from tree then we converts LCA problem to adhoc problem.
#include<bits/stdc++.h>
#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
vector<int>edges[999010];
int par[mx],level[mx],sparse[mx][25];
void dfs(int from,int u,int dep){
    par[u]=from;
    level[u]=dep;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(v!=from) dfs(u,v,dep+1);
    }
}
void create_table(int n){
    for(int i=1;i<=n;i++) sparse[i][0]=par[i];
    sparse[1][0]=-1;
    for(int j=1;(1<<j)<n;j++){
        for(int i=1;i<=n;i++){
            if(sparse[i][j-1]!=-1){
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
            }
        }
    }
}
int lca_query(int n,int p,int q){
    if(level[p]<level[q]) swap(p,q);
    int c;
    for(c=0;(1<<c)<=level[p];c++);
    c--;
    for(int i=c;i>=0;i--){
        if(level[p]-(1<<i)>=level[q]){
            p=sparse[p][i];
        }
    }
    if(p==q) return p;
    for(int i=c;i>=0;i--){
        if(sparse[p][i]!=-1&&sparse[p][i]!=sparse[q][i]){
            p=sparse[p][i]; q=sparse[q][i];
        }
    }
    return par[p];
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(par,-1);
        mem(level,0);
        mem(sparse,-1);
//        edges.clear();
        for(int i=1;i<=mx;i++) edges[i].clear();
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int m; scanf("%d",&m);
            while(m--){
                int v; scanf("%d",&v);
                edges[i].push_back(v);
                edges[v].push_back(i);
            }
        }
        dfs(-1,1,0);
        create_table(n);
        int q; scanf("%d",&q);
        printf("Case %d:\n",cs);
        while(q--){
            int x,y; scanf("%d%d",&x,&y);
            int ans=lca_query(n,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
#include<bits/stdc++.h>
#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
int par[mx],vis[mx];
int lca_query(int root,int p,int q){
    int lca;
    while(1){
        vis[p]=1;
        if(p==root){
            break;
        }
        p=par[p];
    }
    while(1){
        if(vis[q]==1){
            lca=q;
            break;
        }
        q=par[q];
    }
    return lca;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(par,-1);
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int m; scanf("%d",&m);
            while(m--){
                int v; scanf("%d",&v);
                par[v]=i;
            }
        }
        int q; scanf("%d",&q);
        printf("Case %d:\n",cs);
        while(q--){
            mem(vis,0);
            int x,y; scanf("%d%d",&x,&y);
            int ans=lca_query(1,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
*/
