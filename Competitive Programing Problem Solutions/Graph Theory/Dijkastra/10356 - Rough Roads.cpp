#include<bits/stdc++.h>
#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
vector<pp >edges[mx];
int dis[3][mx];
void dfs(int st,int we,int b_w){
    b_w=(b_w+1)%2;
    for(int i=0;i<edges[st].size();i++){
        int v=edges[st][i].first;
        int w=edges[st][i].second;
        if(dis[b_w][v]>we+w){
            dis[b_w][v]=we+w;
            dfs(v,we+w,b_w);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e;
    int cs=1;
    while(scanf("%d%d",&n,&e)==2){
        for(int i=0;i<mx;i++){
            dis[0][i]=1e9;
            dis[1][i]=1e9;
            edges[i].clear();
        }
        for(int i=1;i<=e;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back({v,w});
            edges[v].push_back({u,w});
        }
        dfs(0,0,0);
        int ans=dis[0][n-1];
        printf("Set #%d\n",cs++);
        if(ans==1e9){
            printf("?\n");
        }
        else printf("%d\n",ans);
    }
    return 0;
}
/*

*/
