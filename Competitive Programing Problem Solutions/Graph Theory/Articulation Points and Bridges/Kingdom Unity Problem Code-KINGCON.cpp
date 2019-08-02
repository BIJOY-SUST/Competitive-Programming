#include<bits/stdc++.h>
#define mx             10010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
#define ll             long long int
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
using namespace std;
vector<int>edges[5000000];
int parent[mx],child[mx],low[mx],temp[mx];
bool vis[mx],is_cut[mx];
//int c;
void dfs(int u){
    static int c=0;
    vis[u]=true;
    low[u]=temp[u]=++c;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(v==parent[u]) continue;
        else if(!vis[v]){
            child[u]++;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=temp[u]) is_cut[u]=true;
        }
        else{
            low[u]=min(low[u],temp[v]);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
//        c=0;
        memset(vis,false,sizeof(vis));
        memset(is_cut,false,sizeof(vis));
        memset(parent,-1,sizeof(parent));
        memset(child,0,sizeof(child));
        memset(low,-1,sizeof(low));
        memset(temp,-1,sizeof(temp));
        int n,e;
        ll k;
        scanf("%d %d %lld",&n,&e,&k);

        for(int i=0;i<e;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
//        parent[0]=-1;
        dfs(0);
//        is_cut[0]=child[0]>1?true:false;
        if(child[0]>1) is_cut[0]=true;
        else is_cut[0]=false;
        ll ans=0;
        for(int i=0;i<n;i++){
            if(is_cut[i]) ans+=k;
        }
        printf("%lld\n",ans);
        for(int i=0;i<n;i++) edges[i].clear();
    }
    return 0;
}
/*

*/
