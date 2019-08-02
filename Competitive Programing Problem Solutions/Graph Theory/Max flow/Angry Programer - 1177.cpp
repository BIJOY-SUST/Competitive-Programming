#include<bits/stdc++.h>
#define mx             110
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
int capacity[mx][mx],par[mx];
bool vis[mx];
vector<int>edges[mx];
//vector<int>path;
//vector<vector<int> >paths;
bool bfs(int n,int start,int finish){
    bool flag=false;
    mem(vis,false);
    mem(par,-1);
    queue<int>q;
    q.push(start);
    vis[start]=true;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(!vis[v]&&capacity[u][v]>0){
                vis[v]=true;
                par[v]=u;
                q.push(v);
                if(v==finish){
                    flag=true;
                    break;
                }
            }
        }
    }
    return flag;
}
int FordFulkarson(int n,int start,int finish){
//    path.clear();
//    paths.clear();
    int max_flow=0;
    while(bfs(n,start,finish)){
        int v=finish,flow=1e9;
        while(v!=start){
    //        path.push_back(v);
            int u = par[v];
            flow=min(flow,capacity[u][v]);
            v=u;
        }
    //    path.push_back(start);
        max_flow+=flow;
        v=finish;
        while(v!=start){
            int u = par[v];
            capacity[u][v]-=flow;
            capacity[v][u]+=flow;
            v=u;
        }
//        reverse(path.begin(),path.end());
//        paths.push_back(path);
//        path.clear();
    }
    return max_flow;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        for(int i=0;i<mx;i++) edges[i].clear();
        mem(capacity,0);
        int n,e;
        scanf("%d%d",&n,&e);
        for(int i=2;i<n;i++){
            int w;
            scanf("%d",&w);
            edges[i].push_back(i+n);
//            edges[i+n].push_back(i);
            capacity[i][i+n]+=w;
        }
        for(int i=1;i<=e;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(u==1||u==n){
                edges[u].push_back(v);
//                edges[v].push_back(u);
                capacity[u][v]+=w;
            }
            else{
                edges[u+n].push_back(v);
//                edges[v+n].push_back(u);
                capacity[u+n][v]+=w;
            }
            if(v==1||v==n){
                edges[v].push_back(u);
//                edges[u].push_back(v);
                capacity[v][u]+=w;
            }
            else{
                edges[v+n].push_back(u);
//                edges[u+n].push_back(v);
                capacity[v+n][u]+=w;
            }
        }
        int ans = FordFulkarson(n,1,n);
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/*
Input:

Output:

*/
