#include<bits/stdc++.h>
using namespace std;
//template<typename T> T bigmod(T a,T p,T m){ if(p==0)return 1%m;T x=bigmod(a,p/2,m);x=((x%m)*(x%m))%m;if(p%2==1)x=(x*(a%m))%m;return x%m;}
//template <typename T> T POW(T a,T b){if(b==0) return 1;T ans=POW(a,b/2);ans=ans*ans;if(b%2==1)ans*=a;return ans;}
#define ll long long int
//#define  INF numeric_limits<double>::infinity(); // for double type variable
//template<typename T> T egcd(T a,T b,T *x,T *y){if(b==0){*x=1;*y=0;return a;}T x1,y1;T gcd=egcd(b,a%b,&x1,&y1);*x=y1;*y=x1-(a/b)*y1;return gcd;}
//template<typename T> T ModInverse(T p,T Mod) {return bigmod(p,Mod-2,Mod);}
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int inf       = 0x3f3f3f3f;
//#define maxint 2147483647
#define f  ios_base::sync_with_stdio(false),cin.tie(NULL)
//#define mem(arr,val)        memset(arr,val,sizeof(arr))
//define assignn(arr,size,val) for(int i=0;i<size;i++)arr[i]=val;
//template <typename T> T gcd(T a, T b){while (b){T t = a % b;a = b;b = t;}return a;}
//template <typename T> T lcm(T a, T b){return a / gcd(a, b) * b;}
//template <typename T> T gcd(T a, T b, T c){return gcd(gcd(a, b), c);}
//template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
//template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//#define Unique(x)  x.erase(unique(x.begin(),x.end()),x.end())
//#define valid(tx,ty)  tx>=0&&tx<r&&ty>=0&&ty<c
const  double PI         = (2*acos(0.0));
//__builtin_popcount()
//cout<<fixed<<setprecision(9);
//const int inf       = 0x3f3f3f3f;
//typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
//const int mx = 2e5+10;
//ll fact[mx];
//void factorial(){fact[0]=1;for(int i=1;i<=mx;i++) fact[i]=(fact[i-1]*i)%mod;}
//ll nCr(ll n,ll r){return (fact[n]*ModInverse(((ll)fact[n-r]*(ll)fact[r])%mod,(ll)mod))%mod;}

//bool mark[mx];
//vector<ll>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(ll i=3;i<=(ll)sqrt(mx);i+=2){if(mark[i]){for(ll j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(ll i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///code start here
int main()
{
//
    string a,b;
    getline(cin,a);
    getline(cin,b);
    cout<<a<<" "<<b<<endl;

    return 0;
}
