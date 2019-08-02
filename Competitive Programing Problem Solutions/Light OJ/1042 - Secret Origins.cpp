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
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
ll func(ll val){
    ll lowbit=val&(-val);
    ll leftbit=val+lowbit;
    /*
    int ans;
    for(int i=0;(1<<i)<=n;i++){
        if(bitcheck(n,i)){
            ans=n+(1<<i);
            break;
        }
    }
    */
    ll ans=leftbit;
    int a=one(val)-one(leftbit);
    for(int i=0;i<a;i++) ans+=(1<<i);
    return ans;
//    cout<<leftbit<<endl;
//    ll chngbit=val^leftbit;
//    cout<<chngbit<<endl;
//    ll r8bit= (chngbit/lowbit)>>2;
//    cout<<r8bit<<endl;
//    return (leftbit|r8bit);
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        ll n;
        scanf("%lld",&n);
        ll ans=func(n);
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
/*

*/
