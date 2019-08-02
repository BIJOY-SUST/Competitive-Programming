#include<bits/stdc++.h>
#define mx             2010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<m
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
char a[mx][mx];
bool vis[mx][mx];
int n,m,k;
int ans=0,ans2=0;
void dfs(int u,int v,int d){
//    for(int i=0;i<4;i++){
        int tx=u+0;
        int ty=v+1;
        if(valid(tx,ty)){
            if(a[tx][ty]=='.'){
                dfs(tx,ty,d++);
                ans=max(ans,d);

            }
        }
        else return;
//    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                int ans=dfs(i,j,0);
            }
        }
    }
    return 0;
}
/*

*/
