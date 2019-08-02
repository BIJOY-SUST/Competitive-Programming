#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             200010
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;
vector<int>edges[mx];
bool vis[mx];
int dis[mx];

void bfs(int u){
    queue<int>q;
    //memset(dis,0,sizeof(dis));
    for(int i=1;i<=mx;i++) dis[i]=mx;
    q.push(u);
    dis[u]=0;
    while(!q.empty()){
        int uu=q.front();
        q.pop();
        for(int i=0;i<edges[uu].size();i++){
            int v=edges[uu][i];
            if(dis[v]>dis[uu]+1){
                dis[v]=dis[uu]+1;
                //cout<<v<<" "<<dis[v]<<endl;
                q.push(v);
            }
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;scanf("%d%d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bfs(1);
    //cout<<dis[n]<<endl;
    if(dis[n]<=2) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
    return 0;
}
