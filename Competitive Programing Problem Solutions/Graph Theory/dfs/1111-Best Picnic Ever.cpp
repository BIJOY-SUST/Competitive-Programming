#include<bits/stdc++.h>
#define mx             10010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
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
vector<int>node;
vector<int>edges[mx];
bool vis[mx];
int cnt;
void dfs(int u){
    vis[u]=true;
//    cnt++;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!vis[v]) dfs(v);
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int k,n,m; scanf("%d%d%d",&k,&n,&m);
        while(k--){
            int h;scanf("%d",&h);
            node.push_back(h);
        }
        for(int i=1;i<=m;i++){
            int u,v; scanf("%d%d",&u,&v);
            edges[v].push_back(u);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            bool flag=false;
            mem(vis,false);
//            cnt=0;
            dfs(i);
            for(int i=0;i<node.size();i++){
                if(!vis[node[i]]){
                    flag=true;
                    break;
                }
            }
            if(!flag) ans++;
        }
        printf("Case %d: %d\n",cs,ans);
        node.clear();
        for(int i=0;i<=mx;i++) edges[i].clear();
    }
    return 0;
}
/*

*/

