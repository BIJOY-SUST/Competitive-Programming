#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
int dis[101][101];
int graph[101][101];
int V,E;
void Floyd_Warshall (){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dis[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){/// If vertex k is on the shortest path from i to j,...
                    dis[i][j]=dis[i][k]+dis[k][j];///...then update the value of dis[i][j]
                }
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%d %d",&V,&E);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i==j) graph[i][j]=0;
                else graph[i][j]=1e7;
            }
        }
        for(int i=1;i<=E;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u][v]=1;
            graph[v][u]=1;
        }
        Floyd_Warshall();
        int u,v;
        scanf("%d %d",&u,&v);
        int ans=-9999;
        for(int i=0;i<V;i++){
            ans=max(ans,dis[u][i]+dis[i][v]);
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}

