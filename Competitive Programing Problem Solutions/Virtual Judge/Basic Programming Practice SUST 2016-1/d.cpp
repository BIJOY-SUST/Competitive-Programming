#include<bits/stdc++.h>
#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
#define valid(tx,ty)   tx>=1&&tx<=r&&ty>=1&&ty<=c
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
int a[mx][mx];
int r,c;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    scanf("%d%d%d",&r,&c,&k);
    mem(a,0);
    int ans=0;
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=1;
        ans++;
        if(valid(x,y)&&valid(x,y+1)&&valid(x-1,y)&&valid(x-1,y+1)){
            if(a[x][y]==1&&a[x][y+1]==1&&a[x-1][y]==1&&a[x-1][y+1]==1){
                printf("%d\n",ans);
                return 0;
            }
        }
        if(valid(x,y)&&valid(x-1,y)&&valid(x,y-1)&&valid(x-1,y-1)){
            if(a[x][y]==1&&a[x-1][y]==1&&a[x][y-1]==1&&a[x-1][y-1]==1){
                printf("%d\n",ans);
                return 0;

            }
        }
        if(valid(x,y)&&valid(x+1,y)&&valid(x,y-1)&&valid(x+1,y-1)){
            if(a[x][y]==1&&a[x+1][y]==1&&a[x][y-1]==1&&a[x+1][y-1]==1){
                printf("%d\n",ans);
                return 0;

            }
        }
        if(valid(x,y)&&valid(x+1,y)&&valid(x,y+1)&&valid(x+1,y+1)){
            if(a[x][y]==1&&a[x+1][y]==1&&a[x][y+1]==1&&a[x+1][y+1]==1){
                printf("%d\n",ans);
                return 0;

            }
        }
    }
    printf("0\n");
    return 0;
}
/*

*/
