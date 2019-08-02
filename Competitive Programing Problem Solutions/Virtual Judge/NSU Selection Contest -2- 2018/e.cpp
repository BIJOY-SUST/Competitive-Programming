#include<bits/stdc++.h>
#define mx             55
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
vector<int>edges[mx];
int parent[mx],child[mx],low[mx],temp[mx];
bool vis[mx],is_cut[mx];
int c;
void dfs(int u){
    vis[u]=true;
    low[u]=temp[u]=++c;
//    cout<<low[u]<<endl;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(v==parent[u]) continue;
        else if(!vis[v]){
            child[u]++;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
//            if(parent[u]==-1&&child[u]>1) is_cut[u]=true;
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
    for(int cs=1;cs<=t;cs++){
        mem(parent,-1);
        mem(low,0);
        mem(temp,0);
        mem(child,0);
        mem(vis,false);
        mem(is_cut,false);
        for(int i=0;i<mx;i++) edges[i].clear();
        int n,e;
        scanf("%d %d",&n,&e);
        for(int i=1;i<=e;i++){
            int x,y;scanf("%d%d",&x,&y);
            edges[x].push_back(y);
            //edges[y].push_back(x);
        }
        c=0;
        parent[1]=-1;
        dfs(1);
    //    if(child[1]>1) is_cut[1]=true;
    //    else is_cut[1]=false;
        is_cut[1]=child[1]>1?true:false;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(is_cut[i]) ans++;
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/*

*/
