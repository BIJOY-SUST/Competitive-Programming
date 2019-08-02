#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
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
map<int,vector<int> >edges;
int cat[mx],k;
int cnt=0,ans=0;
bool flag;
bool visited[mx];
void dfs(int a,int cnt){
    flag=true;
    if(cat[a]) cnt++;
    else cnt=0;
    if(cnt>k) return;
    visited[a]=true;
    for(int i=0;i<edges[a].size();i++){
        int b=edges[a][i];
        if(!visited[b]){
            dfs(b,cnt);
            flag=false;
        }
    }
    if(flag) ans++;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&cat[i]);
    memset(visited,false,sizeof(visited));
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
