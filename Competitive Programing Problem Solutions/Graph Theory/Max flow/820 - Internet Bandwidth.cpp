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
int bfs(int n,int start,int finish){
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
    //int t; scanf("%d",&t);
    //for(int cs=1;cs<=t;cs++){
    int n,cs=0;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        for(int i=0;i<mx;i++) edges[i].clear();
        mem(capacity,0);
//        int n; scanf("%d",&n);
        int start,finish,e;
        scanf("%d%d%d",&start,&finish,&e);
        for(int i=1;i<=e;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            capacity[u][v]+=w;
            capacity[v][u]+=w;
        }
        int ans = FordFulkarson(n,start,finish);
        printf("Network %d\nThe bandwidth is %d.\n",++cs,ans);
        printf("\n");
    }
    return 0;
}
/*
Input:
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
0
Output:

*/

