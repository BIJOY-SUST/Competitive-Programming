#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<int >
#define in(a) scanf("%d",&a);
#define in2(a,b)  scanf("%d %d",&a,&b);
#define N 100050
#define inf 100000007
//#define mx 1000000
#define mem(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define pr(a) printf("%d\n",a);
using namespace std;
ll arr[N],dp[N];
vi v;
ll bigmod(ll B,ll P, ll M)
{
    ll R=1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;

    }
    return R;
}
int main()
{
   int a,b,c,n,k;
   int t;
   cin>>t;
   while(t--)
   {
       int mx=-1;
       int mn=100000;
       cin>>n;
       for(int i=0;i<n;i++)
       {
           cin>>a;
           mn=min(mn,a);
           mx=max(mx,a);
       }
       cout<<mx-mn<<endl;
   }

    return 0;
}

