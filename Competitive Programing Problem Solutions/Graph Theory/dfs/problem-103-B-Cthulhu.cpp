#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             110
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
vector<int>edges[5001];
int n,m;
bool vis1[mx];
bool flag=false;
int ans=0;
void dfs(int u,int parent){
    vis1[u]=true;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        //cout<<u<<" "<<v<<endl;
        if(!vis1[v]){
            dfs(v,u);
        }
        else if(v!=parent){
            ans++;
            //cout<<u<<"  "<<v<<" "<<ans<<endl;
        }
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    if(n==m){
        memset(vis1,false,sizeof(vis1));
        dfs(1,-1);
        for(int i=1;i<=n;i++){
            if(!vis1[i]){
                flag=true;
                break;
            }
        }
        //cout<<ans<<endl;
        if(!flag&&ans==2) printf("FHTAGN!\n");
        else printf("NO\n");
    }
    else printf("NO\n");
    return 0;
}
/*
input
6 6
6 3
6 4
5 1
2 5
1 4
5 4
output
FHTAGN!
input
6 5
5 6
4 6
3 1
5 1
1 2
output
NO
*/
