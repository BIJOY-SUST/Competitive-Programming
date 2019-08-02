#include<bits/stdc++.h>
#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
//#define ll             long long int
#define me             printf("BIJOY\n");
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
vector<int>edges[mx];
int par[mx],low[mx],disc[mx],child[mx],mark[mx];
bool vis[mx],flag;
int c,c1;
set<pp >bridge;
void dfs(int u){
    vis[u]=true;
    low[u]=disc[u]=++c;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(v==par[u]) continue;
        else if(!vis[v]){
            child[u]++;
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u])
                bridge.insert(make_pair(min(u,v),max(u,v)));
        }
        else low[u]=min(low[u],disc[v]);
    }
}
void dfs2(int u){
    c1++;
    vis[u]=true;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(bridge.find(pp(min(u,v),max(u,v)))==bridge.end()){
            bool f=false;
            if(mark[u]){
                if(mark[u]==mark[v]){
                    flag=true;
                    f=true;
                }
            }
            if(f==false&&!vis[v]){
                if(mark[u]==1) mark[v]=2;
                else mark[v]=1;
                dfs2(v);
            }
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n,e; scanf("%d %d",&n,&e);
        for(int i=0;i<e;i++){
            int u,v; scanf("%d %d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        mem(par,-1);
        mem(low,0);
        mem(disc,0);
        mem(child,0);
        mem(vis,false);
        mem(mark,0);
        c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i);
        }
        int ans=0;
        mem(vis,false);
        for(int i=0;i<n;i++){
            flag=false;
            c1=0;
            if(!vis[i]){
                mark[i]=1;
                dfs2(i);
                if(flag) ans+=c1;
            }
        }
//        for(int i=0;i<n;i++){
//            cout<<low[i]<<endl;
//        }
        printf("Case %d: %d\n",cs,ans);
        for(int i=0;i<mx;i++) edges[i].clear();
        bridge.clear();
    }
    return 0;
}
/*
Input
1

6 6
0 1
1 2
2 0
3 2
3 4
3 5
Output
Case 1: 3
*/
