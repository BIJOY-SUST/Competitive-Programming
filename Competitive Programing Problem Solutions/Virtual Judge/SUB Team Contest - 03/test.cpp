#include<bits/stdc++.h>
#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
#define pp             pair<ll,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
vector<pp >edge[mx];
ll dis[mx];
bool vis[mx];
bool f=false;
int par[mx];
void dijkstra(int x){
    priority_queue<pp ,vector<pp >,greater<pp > >q;
    pp u,v;
    q.push({0,x});
    dis[x]=0;
    while(!q.empty()){
        u=q.top(); q.pop();
        for(int i=0;i<edge[u.second].size();i++){
            v=edge[u.second][i];
//            cout<<"BIJOY"<<endl;
//            cout<<dis[u.second]<<" "<<v.first<<" "<<dis[v.second]<<endl;
            if(dis[u.second]+v.first<dis[v.second]){
                dis[v.second]=dis[u.second]+v.first;
                q.push({dis[v.second],v.second});
//                cout<<dis[v.second]<<endl;
            }
        }
    }
}
void dfs(int u){
    if(u==1){
        f=true;
        return;
    }
    vis[u]=true;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i].second;
        int w=edge[u][i].first;
        if(dis[u]==dis[v]+w) continue;
        if(!vis[v]){
            par[v]=u;
            dfs(v);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0;i<mx;i++){
        edge[i].clear();
        dis[i]=1e9;
        par[i]=-1;
        vis[i]=false;
    }
    for(int i=1;i<=e;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    dijkstra(1);
    dfs(0);
    if(f){
        vector<int>ans;
        int x=1;
        while(x!=-1){
            ans.push_back(x);
            x=par[x];
        }
        reverse(ans.begin(),ans.end());
        printf("%d",ans.size());
        for(int i=0;i<ans.size();i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    else{
        printf("impossible\n");
    }
    return 0;
}
/*
Input:

Output:

*/
