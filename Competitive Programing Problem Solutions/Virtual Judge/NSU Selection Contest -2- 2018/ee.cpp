#include<bits/stdc++.h>
#define mx             100010
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
vector<int>edges[mx];
bool vis[mx];
void dfs(int u){
    vis[u]=true;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!vis[v])dfs(v);
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(vis,false);
        for(int i=0;i<mx;i++) edges[i].clear();
        int n,e;
        scanf("%d %d",&n,&e);
        for(int i=1;i<=e;i++){
            int x,y;scanf("%d%d",&x,&y);
            edges[x].push_back(y);
            //edges[y].push_back(x);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/**
Input:

Output:

**/
