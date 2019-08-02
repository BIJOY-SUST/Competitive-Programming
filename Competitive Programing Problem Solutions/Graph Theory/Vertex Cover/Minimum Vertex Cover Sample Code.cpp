#include<bits/stdc++.h>
#define mx             1010
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
vector<int>edge[mx];
int dp[mx][mx];
int par[mx];
//bool vis[mx];
int func(int u,int isgurd){
    if(edge[u].size()==0) return 0;
    int &ret=dp[u][isgurd];
    if(ret!=-1) return ret;
    int sum=0;
//    cout<<"BIJOY"<<endl;

    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(v!=par[u]){
            par[v]=u;
            if(isgurd==0){
                sum+=func(v,1);
            }
            else{
                sum+=min(func(v,0),func(v,1));

            }
        }
    }
    return ret=sum+isgurd;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e;
    while(scanf("%d%d",&n,&e)==2){
        if(n==0) break;
        for(int i=1;i<mx;i++) edge[i].clear();
        mem(dp,-1);
        mem(par,0);
        for(int i=1;i<=e;i++){
            int u,v; scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int ans=min(func(1,0),func(1,1));
        printf("%d\n",ans);
    }
    return 0;
}
/**
Sample Input
6 7
1 2
2 3
3 1
3 4
2 5
4 5
5 6
Sample Output
3
**/
