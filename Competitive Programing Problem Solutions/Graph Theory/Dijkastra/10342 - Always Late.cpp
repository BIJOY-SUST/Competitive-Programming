#include<bits/stdc++.h>
#define mx             100001
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
vector<int>dis[5010];
void dijkastra(int st,int en){
    priority_queue<pp,vector<pp >,greater<pp > >q;
    q.push({0,st});
    while(!q.empty()){
        pp u=q.top();
        q.pop();
        if(dis[u.second].size()==0)
            dis[u.second].push_back(u.first);
        else if(dis[u.second].back()!=u.first)
            dis[u.second].push_back(u.first);
        if(dis[u.second].size()>2) continue;
        for(int i=0;i<edges[u.second].size();i++){
            pp v=edges[u.second][i];
            if(dis[v.first].size()==2) continue;
            q.push({u.first+v.second,v.first});
        }
    }

}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    int t;
//    scanf("%d",&t);
//    for(int cs=1;cs<=t;cs++){
    int n,e,cs=1;
    while(scanf("%d%d",&n,&e)==2){
        printf("Set #%d\n",cs++);
        for(int i=0;i<5010;i++){
            edges[i].clear();
        }
        for(int i=1;i<=e;i++){
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            edges[x].push_back({y,w});
            edges[y].push_back({x,w});
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            for(int i=0;i<5010;i++){
                dis[i].clear();
            }
            dijkastra(a,b);
//            cout<<"BIJOY"<<endl;
            if(dis[b].size()<2)
                printf("?\n");
            else
                printf("%d\n",dis[b][1]);
        }

    }
    return 0;
}
/*

*/

