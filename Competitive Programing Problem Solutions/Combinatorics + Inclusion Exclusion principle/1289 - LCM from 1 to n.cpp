#include<bits/stdc++.h>
#define mx             100000005
//#define mod            4294967296
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
int biton(int n,int pos){return n=n|(1<<pos);}
int bitoff(int n,int pos){return n=n&~(1<<pos);}
bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
ll mark[(mx>>6)+5];
int cnt=0;
unsigned int prime[6000000];
unsigned int dp[6000000];
void sieve(){
    mem(mark,0);
    for(ll i=3;i<=(ll)sqrt(mx);i+=2){
        if(!bitcheck(mark[i>>6],((i>>1)&31))) for(ll j=i*i;j<=mx;j+=i<<1)
            mark[j>>6]=biton(mark[j>>6],((j>>1)&31));
    }
    prime[cnt++]=2;
    for(ll i=3;i<=mx;i+=2) if(!bitcheck(mark[i>>6],((i>>1)&31))) prime[cnt++]=i;
}
unsigned int under(int n){
    unsigned int ans=1,temp;
    for(int i=0;prime[i]*prime[i]<=n;i++){
        temp=n;
        temp/=prime[i];
        while(temp>=prime[i]){
            temp/=prime[i];
            ans*=prime[i];
        }
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    sieve();
    mem(dp,0);
    dp[0]=2;
    for(int i=1;i<=cnt;i++){
        dp[i]=dp[i-1]*prime[i];
    }
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n; scanf("%d",&n);
        unsigned int ans=under(n);
        int mm=upper_bound(prime,prime+cnt,n)-prime;
        ans=ans*dp[mm-1];
        cout<<"Case "<<cs<<": "<<ans<<'\n';
    }
    return 0;
}
/*
When a problem says that you have to do modulo 2^32 (and it requires only addition, subtraction and multiplication)
then just take them as unsigned integers and do regular operations.
Just think that the compiler uses 32 bit operations, and if it overflows, then the most significant bits will be lost but
the least significant 32 bits will be correct, which is equivalent to modulo 2^32.
*/
