#include<bits/stdc++.h>
#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
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
int parent[mx],child[mx],low[mx],disc[mx];
bool vis[mx],is_cut[mx];
int c;
void dfs(int u){
//    static int c=0;
//    cout<<c<<endl;
    vis[u]=true;
    low[u]=disc[u]=++c;
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
            if(low[v]>=disc[u]) is_cut[u]=true;
        }
        else{
            low[u]=min(low[u],disc[v]);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,e;
    scanf("%d %d",&n,&e);
    for(int i=1;i<=e;i++){
        int x,y;scanf("%d%d",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    c=0;
    parent[1]=-1;
    dfs(1);
//    if(child[1]>1) is_cut[1]=true;
//    else is_cut[1]=false;
    is_cut[1]=child[1]>1?true:false;
    for(int i=1;i<=n;i++){
        if(is_cut[i]) printf("%d\n",i);
    }
    return 0;
}
/*
Input:
4 3
1 2
2 3
3 4

5 5
2 1
1 3
3 2
1 4
4 5

7 7
1 2 1 3 3 4 4 5 4 6 6 7 3 7
Output:
2
3

1
4

1
3
4
*/
