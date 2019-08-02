/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
vector<ll>v;
ll v1[mx],v2[mx];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ll n;
    scanf("%lld",&n);
    for(ll i=0;i<n;i++){
        ll x;scanf("%lld",&x);
        v.push_back(x);
    }
    memset(v1,0,sizeof(v1));
    memset(v2,0,sizeof(v2));
    for(ll i=1;i<=n;i++){
        v1[i]=v1[i-1]+v[i-1];
    }
    sort(v.begin(),v.end());
    for(ll i=1;i<=n;i++){
        v2[i]=v2[i-1]+v[i-1];
    }
    ll m;
    scanf("%lld",&m);
    for(ll i=0;i<m;i++){
        ll type,l,r;
        scanf("%lld %lld %lld",&type,&l,&r);
        if(type==1) printf("%lld\n",v1[r]-v1[l-1]);
        else printf("%lld\n",v2[r]-v2[l-1]);
    }
    return 0;
}
