#include<bits/stdc++.h>
#define mx             101
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
//int n,m;
ll dp[mx];
ll dp2[mx][mx];
ll sieve(ll n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else if(dp[n]!=-1) return dp[n];
    else{
        dp[n]=(n-1)*(sieve(n-1)+sieve(n-2));
        return dp[n];
    }
}
ll combination(ll n,ll r){
    if(r==0||r==n) return 1;
    if(dp2[n][r]!=-1) return dp2[n][r];
    else{
        dp2[n][r]=combination(n-1,r)+combination(n-1,r-1);
        return dp2[n][r];
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ll n,m,nn;
    while(scanf("%lld%lld",&n,&m)==2){
        mem(dp,-1);
        mem(dp2,-1);
        ll ans=0;
        nn=n;
        ans+=sieve(nn);
    //    cout<<ans<<endl;
        for(int i=1;i<=m;i++){
            nn--;
            ans=ans+(combination(n,i)*sieve(nn));
    //        cout<<nn<<" "<<combination(n,i)<<" "<<sieve(nn)<<" "<<ans<<endl;
        }
        if(n==m) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
/*
In my solution think of test case: 4 1
For 4 envelopes we can put 1 invitation correct maximum. So either he can put 0 invitation correct and 1 invitation correct.
So, For 0 invitation correct i,e: every invitation goes to wrong address, the number of process would be de-arrangement of 4 invitation.
so, dearrangement of 4= 9.
Now let's store the result in sum=9.
Now, For the case of 1 invitation to be correct. Think the invitations as A,B,C,D.

we can count the placing of letters by 4C1(from combination)=4 and if we mutiply the dearrangement
of other 3 letters: 4C1*dearrangement(3)=8.
So we have counted the solution putting 1 invitation correct which is 8 and let's add it to the other solution of putting 0 invitation correct that is 9. So the sum =9+8=17.
which is the solution of this problem.. And don't forget to use long long int because for int the result would be overflowed and verdict would be wa..
*/
