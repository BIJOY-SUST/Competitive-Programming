#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
ll fact[25];
vector<int>v;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; scanf("%d",&t);
    fact[0]=1;
    for(int i=1;i<=20;i++) fact[i]=fact[i-1]*i;
    for(int cs=1;cs<=t;cs++){
        ll n; scanf("%lld",&n);
        for(int i=20;i>=0;i--){
            if(fact[i]<=n){
                n=n-fact[i];
                v.push_back(i);
//                bug(fact[i]);
            }
        }
        if(n!=0){
            printf("Case %d: impossible\n",cs);
        }
        else{
            reverse(v.begin(),v.end());
            printf("Case %d: %d!",cs,v[0]);
            for(int i=1;i<v.size();i++){
                printf("+%d!",v[i]);
            }
            printf("\n");
        }
        v.clear();
    }
    return 0;
}
/*

*/
