#include<bits/stdc++.h>
//#define mx             100001
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
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n; scanf("%d",&n);
        int k=n,cnt1=0,ans=0;
        for(int i=1;i<=n;i++){
            int val; scanf("%d",&val);
            if(val<0){
                cnt1++;
                val=(-1)*val;
                ans+=val;
            }
            else ans+=val;
        }
//        cout<<ans<<" "<<cnt1<<endl;
        if(k-cnt1==0){
            printf("Case %d: inf\n",cs);
        }
        else{
//            int temp=ans/(k-cnt1);
            k=k-cnt1;
            while(__gcd(ans,k)!=1){
                int d=__gcd(ans,k);
                ans=ans/d;
                k=k/d;
            }
            printf("Case %d: %d/%d\n",cs,ans,k);
        }
    }
    return 0;
}
/*

*/
