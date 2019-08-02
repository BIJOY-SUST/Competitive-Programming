#include<bits/stdc++.h>
#define mx             210
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
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
ll weight[mx];
bool vis[mx];
ll dis[mx];
ll cost[mx][mx];
int n,e;
bool b_f(int u){
    for(int i=1;i<=mx;i++) dis[i]=100001;
    dis[u]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<edges[j].size();k++){
                int v=edges[j][k];
                ll w=cost[j][v];
                //cout<<v<<" "<<w<<endl;
                if((dis[j]+w)<dis[v]){
                    dis[v]=dis[j]+w;
                    //cout<<dis[v]<<endl;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<edges[i].size();j++){
            int v=edges[i][j];
            ll w=cost[i][v];
            if(dis[i]+w<dis[v]) return true;
        }
    }
    return false;
}
void dfs(int u){
    vis[u]=true;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!vis[v]) dfs(v);
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(vis,false);
        mem(weight,0);
        mem(dis,0);
        mem(cost,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&weight[i]);
        scanf("%d",&e);
        for(int i=1;i<=e;i++){
            int u,v; scanf("%d %d",&u,&v);
            ll w=weight[v]-weight[u];
            edges[u].push_back(v);
            cost[u][v]=w*w*w;
        }
        dfs(1);
        int q; scanf("%d",&q);
//        cout<<edges[5][0].second<<endl;
        bool iscycle=b_f(1);
        printf("Case %d:\n",cs);
        for(int i=1;i<=q;i++){
            int des; scanf("%d",&des);
            if(vis[des]){
                if(dis[des]<3||dis[des]>=100001){
                    printf("?\n");
                }
                else{
                    printf("%lld\n",dis[des]);
                }
            }
            else{
                printf("?\n");
            }
        }
        for(int i=1;i<=mx;i++) edges[i].clear();
    }
    return 0;
}
/*
Key Idea.
Compute the minimum earning to all nodes from 1.
For each node which can be reached with negative earning,
all its descendants can be reached with negative earning too.
So, perform a dfs to mark all nodes with negative earning.
For each query, if the node is reachable with negative earning,
or not reachable or with earning < 3, puts '?' otherwise puts the total earning form 1.
*/
