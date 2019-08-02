#include<bits/stdc++.h>
#define mx             100000001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll gcd(ll a,ll b){a=abs(a);b=abs(b);if(b!=0) return gcd(b,a%b);else return a;}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
vector<int>prime;
int mark[(mx>>6)+5];
void sieve(){
    memset(mark,0,sizeof(mark));
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(!bitcheck(mark[i>>6],((i>>1)&31))) for(int j=i*i;j<=mx;j+=i<<1)
            mark[j>>6]=biton(mark[j>>6],((j>>1)&31));
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(!bitcheck(mark[i>>6],((i>>1)&31))) prime.push_back(i);
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    sieve();
    for(int i=0;i<25;i++)
        cout<<prime[i]<<'\n';
    return 0;
}
/*

*/

