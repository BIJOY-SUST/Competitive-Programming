#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
ll arr[20];
ll lcm(ll a,ll v){
    return ((a/__gcd(a,v))*v);
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        ll n,m; scanf("%lld%lld",&n,&m);
        for(int i=0;i<m;i++) scanf("%lld",&arr[i]);
        ll ans1=n,ans2=0;
        for(int i=1;i<(1<<m);i++){
            ll temp=1;
            for(int j=0;j<m;j++){
                if(bitcheck(i,j)) temp=lcm(temp,arr[j]);
            }
            if(one(i)%2) ans2+=(n/temp);
            else ans2-=(n/temp);
        }
        ll ans=ans1-ans2;
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
/*
Input
2
15 3
2 3 5
10 4
2 4 5 7
Output
Case 1: 4
Case 2: 3
*/
