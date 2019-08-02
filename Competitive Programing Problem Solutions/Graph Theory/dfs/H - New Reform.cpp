#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             100005
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
bool vis1[mx];
int ans;
void dfs(int u,int p){
    vis1[u]=true;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!vis1[v]){
            dfs(v,u);
        }
        else if(v!=p){
            //cout<<11111<<endl;
            ans=0;
        }
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,e;
    scanf("%d %d",&n,&e);
    for(int i=1;i<=e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    memset(vis1,false,sizeof(vis1));
    int ans1=0;
    ans=0;
    for(int i=1;i<=n;i++){
        if(!vis1[i]){
            //cout<<ans<<endl;
            ans++;
            dfs(i,-1);
            ans1+=ans;
            ans=0;
            //cout<<ans<<endl;
        }
    }
    printf("%d\n",ans1);
    return 0;
}
/*
Input
4 3
2 1
1 3
4 3
Output
1
Input
5 5
2 1
1 3
2 3
2 5
4 3
Output
0
Input
6 5
1 2
2 3
4 5
4 6
5 6
Output
1
10 10
1 2
2 5
3 5
2 3
3 4
6 7
7 8
8 9
7 9
9 10
*/
