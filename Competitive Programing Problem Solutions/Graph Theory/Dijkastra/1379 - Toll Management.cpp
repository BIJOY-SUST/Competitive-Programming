#include<bits/stdc++.h>
#define mx             10010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
vector<pp >edges1[2*mx];
vector<pp >edges2[2*mx];
vector<pair<int,pp > >aled;
ll dis1[mx],dis2[mx];
int dijkstra1(int x,ll *dis){
    priority_queue<pp ,vector<pp >,greater<pp > >q;
    pp u,v;
    q.push({0,x});
    dis[x]=0;
    while(!q.empty()){
        u=q.top();
        q.pop();
        for(int i=0;i<edges1[u.second].size();i++){
            v=edges1[u.second][i];
            if(dis[u.second]+v.first<dis[v.second]){
                dis[v.second]=dis[u.second]+v.first;
                q.push({dis[v.second],v.second});
            }
        }
    }
}
int dijkstra2(int x,ll *dis){
    priority_queue<pp ,vector<pp >,greater<pp > >q;
    pp u,v;
    q.push({0,x});
    dis[x]=0;
    while(!q.empty()){
        u=q.top();
        q.pop();
        for(int i=0;i<edges2[u.second].size();i++){
            v=edges2[u.second][i];
            if(dis[u.second]+v.first<dis[v.second]){
                dis[v.second]=dis[u.second]+v.first;
                q.push({dis[v.second],v.second});
            }
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    scanf("%d",&k);
    for(int cs=1;cs<=k;cs++){
        for(int i=0;i<mx;i++){
            edges1[i].clear();
            edges2[i].clear();
            dis1[i]=1e9;
            dis2[i]=1e9;
        }
        aled.clear();
        int n,m,s,t,p;
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges1[u].push_back({w,v});
            edges2[v].push_back({w,u});
            aled.push_back({w,{u,v}});
        }
        dijkstra1(s,dis1);
        dijkstra2(t,dis2);
        int ans=-1,f_dis=-1;
        for(int i=0;i<aled.size();i++){
            pair<int,pair<int,int> > h=aled[i];
            ll d1=dis1[h.second.first]+dis2[h.second.second]+h.first;
            //ll d2=dis2[h.second.first]+dis1[h.second.second]+h.first;
            if(d1<=p){
                ans=max(ans,h.first);
            }
//            if(d2<=p){
//                ans=max(ans,h.first);
//            }
        }
        if(ans!=1e9) printf("Case %d: %d\n",cs,ans);
        else printf("Case %d: -1\n",cs);

    }
    return 0;
}
/*

*/
