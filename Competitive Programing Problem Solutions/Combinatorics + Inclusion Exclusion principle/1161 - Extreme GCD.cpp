#include<bits/stdc++.h>
#define mx             10005
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
ll a[mx];
ll cnt[mx];
ll nCr(ll n,ll r){
    return n*(n-1)*(n-2)*(n-3)/(ll)24;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout<<nCr(5,4)<<endl;
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(cnt,0);
        int n; scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            for(int j=1;j*j<=a[i];j++){
                if(a[i]%j==0){
                    cnt[j]++;
                    if(j*j!=a[i]) cnt[a[i]/j]++;
                }
            }
        }
//        for(int i=1;i<=8;i++) cout<<cnt[i]<<endl;
        ll ans[mx];
        mem(ans,0);
        for(int i=mx;i>0;i--){
            ans[i]=nCr(cnt[i],4);
//            cout<<ans[i]<<endl;
            for(int j=2*i;j<mx;j+=i)
                ans[i]-=ans[j];
//                cout<<ans[i]<<endl;
        }
        printf("Case %d: %lld\n",cs,ans[1]);
    }
    return 0;
}
/*
Input
3
4
2 4 6 1
5
1 2 4 6 8
10
12 46 100 131 5 6 7 8 9 10
Output
Case 1: 1
Case 2: 4
Case 3: 195
*/
