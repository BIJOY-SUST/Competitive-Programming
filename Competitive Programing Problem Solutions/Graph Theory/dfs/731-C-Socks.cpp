#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             1000010
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
int col[mx];
map<int,int>mm;
int node=0,c=0;
bool vis[mx];
void dfs(int x){
    node++;
    vis[x]=true;
    mm[col[x-1]]++;
    //cout<<x<<n<<mm[col[x-1]]<<endl;
    if(mm[col[x-1]]>c) c=mm[col[x-1]];
    for(int i=0;i<edges[x].size();i++){
        int v=edges[x][i];
        if(!vis[v]){
            dfs(v);
        }
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&col[i]);
    }
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    //memset(mm,0,sizeof(mm));
    memset(vis,false,sizeof(vis));
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            //memset(mm,0,sizeof(mm));
            //cout<<n<<" "<<c<<endl;
            ans+=node-c;
            node=0;
            c=0;
            mm.clear();
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
input
3 2 3
1 2 3
1 2
2 3
output
2
input
3 2 2
1 1 2
1 2
2 1
output
0
*/
