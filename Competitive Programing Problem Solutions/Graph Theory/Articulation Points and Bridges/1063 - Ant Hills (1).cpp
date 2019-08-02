#include<bits/stdc++.h>
#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
#define   me             printf("BIJOY\n");
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
vector<int>edges[mx];
int parent[mx],low[mx],temp[mx],child[mx];
bool vis[mx],is_cut[mx];
int c,ans;
void dfs(int u){
    vis[u]=true;
    low[u]=temp[u]=++c;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(v==parent[u]) continue;
        else if(!vis[v]){
            parent[v]=u;
            child[u]++;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=temp[u]){
                is_cut[u]=true;
            }
        }
        else low[u]=min(low[u],temp[v]);
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n,e; scanf("%d %d",&n,&e);
        for(int i=0;i<e;i++){
            int u,v; scanf("%d %d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        memset(parent,-1,sizeof(parent));
        memset(child,0,sizeof(child));
        memset(low,0,sizeof(low));
        memset(temp,0,sizeof(temp));
        memset(vis,false,sizeof(vis));
        memset(is_cut,false,sizeof(is_cut));
        c=0;
        ans=0;
//        cout<<ans<<endl;
//        for(int i=1;i<=n;i++){
//            if(!vis[i]){
//                dfs(i);
//                if(child[i]>1) ans++;
//            }
//        }
        dfs(1);
        if(child[1]>1) ans++;
        for(int i=2;i<=n;i++) if(is_cut[i]) ans++;
        printf("Case %d: %d\n",cs,ans);
        for(int i=0;i<mx;i++) edges[i].clear();
    }
    return 0;
}
/*

*/
