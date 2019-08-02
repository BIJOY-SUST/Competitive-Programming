#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
#define mx             150005
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
ll v,e;
void dfs(int u){
    vis[u]=true;
    v++;
    for(__typeof(edges[u].begin())it=edges[u].begin();it!=edges[u].end();it++){
        e++;
        if(!vis[*it]){
            dfs(*it);
        }
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            v=0;
            e=0;
            dfs(i);
            if(v==1||(v==2&&e==2)){
                continue;
            }
            else if(e==(v*(v-1))){
                continue;
            }
            else{
                flag=true;
                break;
            }
        }
    }
    if(flag) printf("NO\n");
    else printf("YES\n");
    return 0;
}
/*

*/
