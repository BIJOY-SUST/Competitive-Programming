/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             20001
//#define mod            100000007
#define inf            1e5
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
vector<int>edges[mx];
int cost[mx][mx];
int n;
//int Distance[mx];
vector<int>Distance;
class data{
public:
    int node,w;
    bool operator<(const data& p)const{
        return w>p.w;
    }
};
int Dijkstra(int start,int End){
//    memset(Distance,0,sizeof(Distance));
//    for(int i=0;i<=n;i++) Distance[i]=inf;
    Distance.assign(n,inf);
    priority_queue<data>q;
    data u,v;
    u.node=start,u.w=0;
    q.push(u);
    Distance[start]=0;
    while(!q.empty()){
        u=q.top();
        q.pop();
        for(int i=0;i<edges[u.node].size();i++){
            v.node = edges[u.node][i];
            v.w = cost[u.node][v.node]+u.w;
            if(Distance[v.node]>v.w){
                Distance[v.node] = v.w;
                q.push(v);
            }
        }
    }
    return Distance[End];
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int e,start,End;
        scanf("%d %d %d %d",&n,&e,&start,&End);
        for(int i=1;i<=e;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            cost[u][v]=w;
            cost[v][u]=w;
        }
        int d = Dijkstra(start,End);
        if(d!=inf) printf("Case #%d: %d\n",tc,d);
        else printf("Case #%d: unreachable\n",tc);
        for(int i=0;i<=n;i++) edges[i].clear();
        Distance.clear();
    }
    return 0;
}
/**
Input:
5
5 5 1 5
1 2 3
2 3 4
3 5 5
1 4 4
4 5 100
Output:
12
**/

