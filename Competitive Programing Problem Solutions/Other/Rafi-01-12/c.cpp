#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define ull            unsigned long long int
//#define mx             100001
//#define mod            1000000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll ans=0;
        ll n;
        scanf("%lld",&n);
        ans=n*(n+1)/2;
        ll cnt=0;
        while(pow(2,cnt)<=n){
            ans=ans-2*pow(2,cnt);
            cnt++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*

*/


