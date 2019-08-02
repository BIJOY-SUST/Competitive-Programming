///buji nai bujte hobe
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define pf  printf
#define case2(z)            printf("Case %d: ",z)
#define sf(a) scanf("%d",&a)
#define sffl(a,b)           scanf("%lld %lld",&a,&b)
#define loop1(i,n) for(int i=1;i<=n;i++)
bool p[MAX+2];
vector<int>prime;

void sieve()
{
    p[0]=p[1]=1;
    int root=sqrt(MAX);
    for(int i=2; i<=root; i++)
    {
        if(p[i]==0)
        {
            //prime.push_back(i);
            for(int j=i*i; j<=MAX; j+=i)
            {
                p[j]=1;
                if(i%2==1) j+=i;
            }
        }
    }
    for(int i=2; i<=MAX; i++)
    {
        if(p[i]==0) prime.push_back(i);
    }
}

ll m=1000000007;

ll big_mod(ll n,ll p)
{
    if(p==0) return 1;
    if(p%2==0)
    {
        ll x=big_mod(n,p/2)%m;
        return (x*x)%m;
    }
    else return ((n%m)*(big_mod(n,p-1)%m))%m;
}

ll mod_inverse(ll n)
{
    return big_mod(n,m-2);
}

ll sum_of_divisor(ll n,ll p)
{
    ll sum=1,c,s;
    ll k=n;
    ll root=sqrt(n);
    for(ll i=0; prime[i]<=root; i++)
    {
        if(k%prime[i]==0)
        {
            c=0;
            while(k%prime[i]==0)
            {
                k/=prime[i];
                c++;
            }
            root=sqrt(k);
            ll x=big_mod(prime[i],(c*p)+1);
            ll y=mod_inverse(prime[i]-1);
            s=(((x-1+m)%m)*((y+m)%m))%m; // here we add m to get the exact result because x or y can be of negative value since in the problem, n & m are signed integer
            sum=((sum%m)*(s%m))%m;
            printf("%lld %lld %lld %lld\n",x,y,s,sum);
        }
    }
    if(k>1)
    {
        ll x=big_mod(k,p+1);
        ll y=mod_inverse(k-1);
        s=(((x-1+m)%m)*((y+m)%m))%m;
        sum=((sum%m)*(s%m))%m;
        printf("%lld %lld %lld %lld\n",x,y,s,sum);
    }
    return sum;
}

int main()
{
    //CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    sf(t);
    sieve();
    loop1(z,t)
    {
        ll n,p;
        sffl(n,p);
        case2(z);
        pf("%lld\n",sum_of_divisor(n,p));
    }
    return 0;
}
