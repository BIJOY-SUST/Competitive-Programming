#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define nl              '\n'
#define sf              scanf
#define pf              printf
#define F               first
#define S               second
#define pb              push_back
#define eb              emplace_back
#define ui              unsigned int
#define ll              long long int
#define ull             unsigned long long int
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<ll>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
template <typename T> T POW(T b,T p)
{
    T Ans=1;
    while(p)
    {
        if(p&1)Ans=(Ans*b);
        b=(b*b);
        p>>=1;
    }
    return Ans;
}
template <typename T> T BigMod(T b,T p,T Mod)
{
    T Ans=1;
    while(p)
    {
        if(p&1)Ans=(Ans*b)%Mod;
        b=(b*b)%Mod;
        p>>=1;
    }
    return Ans;
}
template <typename T> T ModInverse(T p,T Mod)
{
    return BigMod(p,Mod-2,Mod);
}
typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 2e6+10;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here


//a is the total matrix, last column is the constant matrix and other columns are coefficient matrix
//final ans is stored is ans matrix
//row order is kept and assigned the given (intended) value to first row then second row ans so on
long long gauss ( vector < vector < long long > > a, vector < long long > & ans, long long mod)
{
    int n = ( int ) a. size ( ) ;
    int m = ( int ) a [ 0 ] . size ( ) - 1 ;
    vector < int > where ( n, - 1 ) ;
    for ( int col = 0, row = 0 ; col < m && row < n ; ++ row )
    {
        int sel = col ;
        for ( int i = col ; i < m ; ++ i )
            if ( abs ( a [ row ] [ i ] ) > abs ( a [ row ] [ sel ] ) )
                sel = i ;
        if ( abs ( a [ row ] [ sel ] ) == 0 )
            continue ;
        for ( int i = 0 ; i < n ; ++ i )
            swap ( a [ i ] [ col ], a [ i ] [ sel ] ) ;
        where [ row ] = col ;
//print3(row,col,a[row][col]);
        for ( int i = 0 ; i < n ; ++ i )
            if ( i != row )
            {
                long long c = a [ row ] [ col ];
                long long d = a [ i ][ col ];
                for ( int j = col ; j <= m ; ++ j )
                {
                    a [ i ] [ j ] = (c*a[i][j]-d*a[row][j])%mod ;
                    a [i][j]=(a[i][j]+mod)%mod;
                }
            }
        ++ col ;
    }
    ans. assign ( m, 0 ) ;
    for ( int i = 0 ; i < n ; ++ i )
        if ( where [ i ] != - 1 )
            ans [ where[i] ] = (a [ i ] [ m ]*
                                BigMod( a [ i ] [ where[i] ],mod-2,mod))%mod ;
    for ( int i = 0 ; i < n ; ++ i )
    {
        long long sum = 0 ;
        for ( int j = 0 ; j < m ; ++ j )
        {
            sum += (ans [ j ] * a [ i ] [ j ])%mod ;
            sum %= mod;
        }
        if ( abs ( sum - a [ i ] [ m ] ) != 0 ) //no solution
            return 0 ;
    }
    long long totalans=1;
    for ( int i = 0 ; i < m ; ++ i )
        if ( where [ i ]== - 1 ) //use mod if necessary
            totalans=(totalans* mod)%1000000007;
    return totalans ;
}
int main()
{
    int n,m;
    while(scanf("%d",&n)==1)
    {
        vector<vector<ll> > mat(n);
        vector<ll> ans;
        ll v;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                scanf("%lf",&v);
                mat[i].push_back(v);
            }
        }
        int d=gauss(mat,ans,mod);
        for(int i=0; i<n; i++) debug(ans[i]);
    }
    return 0;
}
/**
3
1 2 1 3
2 0 1 1
0 1 1 2

3
3.0 2.0 -4.0 3.0
2.0 3.0 3.0 15.0
5.0 -3 1.0 14.0
*/
