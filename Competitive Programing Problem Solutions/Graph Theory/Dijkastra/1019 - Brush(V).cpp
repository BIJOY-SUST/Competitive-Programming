#include<bits/stdc++.h>
#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
int dis[mx];
int dij(int st,int en){
    priority_queue<pp,vector<pp>,greater<pp> >q;
    for(int i=0;i<mx;i++) dis[i]=1e9;
    pp u,v;
    q.push({0,st});
    dis[st]=0;
    while(!q.empty()){
        u=q.top();
        q.pop();
        for(int i=0;i<edges[u.second].size();i++){
            v = edges[u.second][i];
            if(dis[u.second]+v.second<dis[v.first]){
                dis[v.first]=dis[u.second]+v.second;
                q.push({dis[v.first],v.first});
            }
        }
    }
    return dis[en];
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,n,e;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%d%d",&n,&e);
        for(int i=1;i<=e;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back({v,w});
            edges[v].push_back({u,w});
        }
        int ans=dij(1,n);
        if(ans!=1e9) printf("Case %d: %d\n",cs,ans);
        else printf("Case %d: Impossible\n",cs);
        for(int i=0;i<mx;i++) edges[i].clear();
    }
    return 0;
}
/*

*/
