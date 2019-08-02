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
vector<pp >ans;
int parent[mx],low[mx],temp[mx],child[mx];
bool vis[mx],is_cut[mx];
int c;
void dfs(int u){
    vis[u]=true;
    low[u]=temp[u]=++c;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(parent[u]==v) continue;
        else if(!vis[v]){
            child[u]++;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>temp[u]){
                ans.push_back(make_pair(min(u,v),max(u,v)));
            }
        }
        else{
            low[u]=min(low[u],temp[v]);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
//    int t;
//    scanf("%d",&t);
//    for(int cs=1;cs<=t;cs++){
    int n;
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++){
            int u,d; scanf("%d (%d)",&u,&d);
            while(d--){
                int v; scanf("%d",&v);
                edges[u].push_back(v);
                edges[v].push_back(u);
            }
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<edges[i].size();j++){
//                printf("%d ",edges[i][j]);
//            }
//            cout<<endl;
//        }
        memset(vis,false,sizeof(vis));
        memset(is_cut,false,sizeof(is_cut));
        memset(parent,-1,sizeof(parent));
        memset(low,0,sizeof(low));
        memset(temp,0,sizeof(temp));
        memset(child,0,sizeof(child));
        c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i);
        }
        sort(ans.begin(),ans.end());
        //printf("Case %d:\n",cs);
        printf("%d critical links\n",ans.size());
        for(int i=0;i<ans.size();i++){
            printf("%d - %d\n",ans[i].first,ans[i].second);
        }
        for(int i=0;i<mx;i++) edges[i].clear();
        ans.clear();
        printf("\n");
    }
    return 0;
}
/*

*/

