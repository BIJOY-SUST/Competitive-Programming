#include<bits/stdc++.h>
#define mx             110
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
#define me             printf("BIJOY\n");
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//desclate< class T > inline T SQR(T a) {return ((a)*(a));}
//desclate< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//desclate< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//desclate<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//desclate<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//desclate<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
vector<int>edges[mx];
int parent[mx],low[mx],desc[mx],child[mx];
bool vis[mx],is_cut[mx];
int c;
void dfs(int u){
    vis[u]=true;
    low[u]=desc[u]=++c;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(parent[u]==v) continue;
        else if(!vis[v]){
            child[u]++;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=desc[u]) is_cut[u]=true;
        }
        else low[u]=min(low[u],desc[v]);
    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        for(int i=1;i<=mx;i++) edges[i].clear();
        memset(vis,false,sizeof(vis));
        memset(is_cut,false,sizeof(is_cut));
        memset(parent,0,sizeof(parent));
        memset(low,0,sizeof(low));
        memset(desc,0,sizeof(desc));
        memset(child,0,sizeof(child));
        int x,y; char ch;
        while(scanf("%d",&x)==1&&x) {
			while(scanf("%d%c",&y,&ch)==2) {
                edges[x].push_back(y);
                edges[y].push_back(x);
				if(ch == '\n')	break;
			}
		}
//        for(int i=1;i<=n;i++){
//            for(int j=0;j<edges[i].size();j++){
//                cout<<i<<" "<<edges[i][j]<<endl;
//            }
//        }
        c=0;
        dfs(1);
        is_cut[1]=child[1]>1?true:false;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(is_cut[i]){
                ++ans;
                //me
            }
        }
        printf("%d\n",ans);
//        printf("\n");
    }
    return 0;
}
/*
Sample Input
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0
Sample Output
1
2
*/


