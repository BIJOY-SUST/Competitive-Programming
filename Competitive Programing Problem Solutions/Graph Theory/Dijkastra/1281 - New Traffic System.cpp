#include<bits/stdc++.h>
#define mx             10010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
#define pp             pair<int,int>
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
int n;
vector<pp >edges[mx];
int dis[mx][12];
int Dijkstra(int st){
    for(int i=0;i<mx;i++){
        for(int j=0;j<12;j++){
            dis[i][j]=1e9;
        }
    }
    priority_queue<pair<int,pair<int,int> > >pq;
    pq.push({0,{0,st}});
    dis[st][0]=0;
    while(!pq.empty()){
        pair<int,pair<int,int> >u=pq.top();
        pq.pop();
        for(int i=0;i<edges[u.second.second].size();i++){
            pair<int,int> v=edges[u.second.second][i];
            if(v.second>0){
                if(dis[v.first][u.second.first]>dis[u.second.second][u.second.first]+v.second){
                    dis[v.first][u.second.first]=dis[u.second.second][u.second.first]+v.second;
                    pq.push({-dis[v.first][u.second.first],{u.second.first,v.first}});
                }
            }
            else{
                v.second=abs(v.second);
                if(dis[v.first][u.second.first+1]>dis[u.second.second][u.second.first]+v.second){
                    dis[v.first][u.second.first+1]=dis[u.second.second][u.second.first]+v.second;
                    pq.push({-dis[v.first][u.second.first+1],{u.second.first+1,v.first}});
                }
            }
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        for(int i=0;i<mx;i++) edges[i].clear();
        int n,m,k,d;
        scanf("%d %d %d %d",&n,&m,&k,&d);
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back({v,w});
        }
        for(int i=1;i<=k;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back({v,-w});
        }
        Dijkstra(0);
        int ans=1e9;
        for(int i=0;i<=d;i++){
            ans=min(ans,dis[n-1][i]);
        }
        if(ans!=1e9) printf("Case %d: %d\n",cs,ans);
        else printf("Case %d: Impossible\n",cs);
    }
    return 0;
}
/*
Input:

Output:

*/
