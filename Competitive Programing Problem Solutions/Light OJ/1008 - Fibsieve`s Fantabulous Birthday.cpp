#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t; scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        ll s; scanf("%lld",&s);
        ll sq=ceil(sqrt(s));
        ll r,c;
        ll d=sq-1;
        d=d*d;
        if(s-d>sq){
            c=sq*sq-s+1;
            r=sq;
        }
        else{
            c=sq;
            r=s-d;
        }
        if(sq%2==0) swap(c,r);
        printf("Case %lld: %lld %lld\n",cs,c,r);
    }
    return 0;
}
/*
#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t; scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        ll s; scanf("%lld",&s);
        ll sq=ceil(sqrt(s));
        ll r,c;
        if(sq*sq==s){
            if(s%2==0){
                c=sq;
                r=1;
            }
            else{
                c=1;
                r=sq;
            }
        }
        else if(sq*sq>s){
            ll a=sq;
            a--;
            a=a*a;
            if(a%2==0){
                if((s-a)>=sq){
                    c=sq*sq-s+1;
                    r=sq;
                }
                else{
                    c=sq;
                    r=s-a;
                }
            }
            else{
                if((s-a)>=sq){
                    r=sq*sq-s+1;
                    c=sq;
                }
                else{
                    r=sq;
                    c=s-a;
                }
            }
        }
        printf("Case %lld: %lld %lld\n",cs,c,r);
    }
    return 0;
}
/*

*/

*/
