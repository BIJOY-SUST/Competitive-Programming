#include<bits/stdc++.h>
#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define me             printf("BIJOY\n");
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
int dis[mx],d[mx];
vector<int>edges[mx];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1){
        if(n==-1) break;
        for(int i=0;i<=mx;i++) edges[i].clear();
        mem(dis,0);
        mem(d,0);
        for(int i=1;i<=n;i++){
            scanf("%d",&dis[i]);
            int q; scanf("%d",&q);
            while(q--){
                int v; scanf("%d",&v);
                edges[i].push_back(v);
            }
        }
        d[1]=100;
        queue<int>q;
        q.push(1);
        bool flag=false;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(u==n){
                flag=true;
                break;
            }
            for(int i=0;i<edges[u].size();i++){
                int v=edges[u][i];
                if(d[u]+dis[v]>d[v]&&d[u]+dis[v]<=20000){
                    d[v]=d[u]+dis[v];
                    q.push(v);
                }
            }
        }
        if(flag) printf("winnable\n");
        else printf("hopeless\n");
    }
    return 0;
}
/*
Sample Input
5
0 1 2
-60 1 3
-60 1 4
20 1 5
0 0
5
0 1 2
20 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
21 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
20 2 1 3
-60 1 4
-60 1 5
0 0
-1
Sample Output
hopeless
hopeless
winnable
winnable
*/
