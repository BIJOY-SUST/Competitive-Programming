#include<bits/stdc++.h>
#define mx             1001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
int r,c;
int dis[mx][mx];
int grid[mx][mx];
int Dijkstra(int x1,int y1){
    for(int i=0;i<r;i++)for(int j=0;j<c;j++) dis[i][j] = 1e9;
    dis[x1][y1]=grid[x1][y1];
    priority_queue<pair<int,pp>,vector<pair<int,pp>>,greater<pair<int,pp>> >q;
    q.push({dis[x1][y1],{x1,y1}});
    while(!q.empty()){
        pair<int,pair<int,int> >p=q.top();
        q.pop();
        int d=p.first;
        pp u=p.second;
//        cout<<"mmm"<<endl;
        if(dis[u.first][u.second]==d){
        for(int i=0;i<4;i++){
            int tx=u.first+fx[i];
            int ty=u.second+fy[i];
//            dis[tx][ty]=grid[tx][ty];
            if(valid(tx,ty)){
                int k=grid[tx][ty]+dis[u.first][u.second];
                if(dis[tx][ty]>k){
                    dis[tx][ty]=k;
                    q.push({k,{tx,ty}});
                }
            }
        }
        }
    }
    return dis[r-1][c-1];
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        memset(grid,0,sizeof(grid));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d",&grid[i][j]);
            }
        }
//        cout<<"bbb"<<endl;
        int ans=Dijkstra(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
/*

*/
