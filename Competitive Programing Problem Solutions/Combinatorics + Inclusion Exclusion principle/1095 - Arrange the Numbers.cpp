/**
Problem Hints :
https://paste.ubuntu.com/26256256/
Formula :
Ans=n!−(nC1)×(n−1)!+(nC2)×(n−2)!−..…+(−1)^k×(nCk)×(n−k)!+….+(−1)^n
**/
#include<bits/stdc++.h>
#define mx             1010
#define mod            1000000007
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
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
ll fact[mx];
ll dp[mx][mx];
ll combination(int n,int r){
    if(r==0||r==n) return 1;
    if(dp[n][r]!=-1) return dp[n][r];
    else{
        dp[n][r]=(combination(n-1,r-1)+combination(n-1,r))%mod;
        return dp[n][r];
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    fact[0]=1;
    for(int i=1;i<=1001;i++) fact[i]=(fact[i-1]*i)%mod;
    mem(dp,-1);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        ll n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        ll ans=combination(m,k);
        ll ans2=fact[n-k];
        n=n-k;
        for(int i=1;i<=(m-k);i++){
            if(i&1) ans2-=(combination(m-k,i)*fact[n-i])%mod;
            else ans2+=(combination(m-k,i)*fact[n-i])%mod;
            ans2=(ans2+mod)%mod;
        }
        ans=(ans*ans2)%mod;
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
/*
The first part in this problem is simple, how many ways can you choose the k fixed places from m places? mCk
Now, how many places we have where derangement is must and how many places where it doesn't matter what you put?
(we are going to ignore fixed places as they are constant in all arrangements)
We have m-k places where derangement is must. And n-m places where it doesn't matter what you put.
Now, think that you want to put a number in one of those m-k places (call this place A). How many ways can you put a number there?
( For ease of writing, I will now consider x = m-k, y = n-m. We have to solve f(x, y) )
The number you are going to put in that place might come from the x-1 places, or it might come from y places.
If it comes from x-1 places, what are the 2 cases like in original derangement dp derivation?
Suppose, B is the place within the x-1 places from where you are taking the number.
a) You put the number from B in place A. And you put the number that was in A into B. So, A and B are already deranged now. Now, you have to solve the problem for f(x-2, y).
b) You put the number from B in A, but you don't want to put A's number in B. That means, it's forbidden for A's number to be in B, i;e B still needs to be deranged.
So, you have to solve for f(x-1, y) now. (this is same logic as original derangement dp derivation)
How many ways overall then? (x-1)*(f(x-2,y) + f(x-1,y))
What if the number comes from y places? What are the 2 cases then?
Let B the place from y places.
a) You put B's number in A and A's number in B. So, now you have x-1 numbers to derange and y-1 numbers free.
b) You put B's number in A but don't want to put A's number in B. So, you still need to derange B. i;e, the number of places to still derange is x-1+1 = x.
But you did use up one of the free numbers from y. So this is f(x, y-1)
Overall of this part is y*(f(x-1,y-1)+f(x,y-1))
*/
