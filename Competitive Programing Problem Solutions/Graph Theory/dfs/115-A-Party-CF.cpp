#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             2010
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
bool visited[mx];
int ans=0;
void dfs(int u,int c){
    visited[u]=true;
    if(c>ans) ans=c;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!visited[v]){
            dfs(v,c+1);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        if(k!=-1){
            //edges[k].push_back(i);
            edges[i].push_back(k);
        }
    }
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        dfs(i,1);
    }
    printf("%d\n",ans);
    return 0;
}
/*
input
5
-1
1
2
1
-1
output
3
*/
