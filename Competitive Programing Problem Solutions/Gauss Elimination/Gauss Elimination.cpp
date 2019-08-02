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
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
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
int gauss ( vector < vector < double > > a, vector < double > & ans )
{
    int n = ( int ) a. size ( ) ;
    int m = ( int ) a [ 0 ] . size ( ) - 1 ;
    vector < int > where ( m, - 1 ) ;
    for ( int col = 0, row = 0 ; col < m && row < n ; ++ col )
    {
        int sel = row ;
        for ( int i = row ; i < n ; ++ i )
            if ( abs ( a [ i ] [ col ] ) > abs ( a [ sel ] [ col ] ) ) //maxvalued row for this column
                sel = i ;
        if ( abs ( a [ sel ] [ col ] ) < eps )
            continue ;
        for ( int i = col ; i <= m ; ++ i )
            swap ( a [ sel ] [ i ], a [ row ] [ i ] ) ; //swap the rows
        where [ col ] = row ;
        for ( int i = 0 ; i < n ; ++ i )
            if ( i != row )
            {
                double c = a [ i ] [ col ] / a [ row ] [ col ] ;
                for ( int j = col ; j <= m ; ++ j )
                    a [ i ] [ j ] -= a [ row ] [ j ] * c ;
            }
        ++ row ;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            printf("%5.2f ",a[i][j]);
        }
        printf("\n");
    }
    ans. assign ( m, 0 ) ;
    for ( int i = 0 ; i < m ; ++ i ){
//        cout<<where[i]<<" "<<m<<nl;
        if ( where [ i ] != - 1 )
            ans [ i ] = a [ where [ i ] ] [ m ] / a [ where [ i ] ] [ i ] ;

    }
//checking right
    for ( int i = 0 ; i < n ; ++ i )
    {
        double sum = 0 ;
        for ( int j = 0 ; j < m ; ++ j ){
            sum += ans [ j ] * a [ i ] [ j ] ;
//            cout<<ans[j]<<" "<<a[i][j]<<" "<<sum<<nl;
        }
        if ( abs ( sum - a [ i ] [ m ] ) > eps ) //no solution
            return 0 ;
    }
    for ( int i = 0 ; i < m ; ++ i )
        if ( where [ i ]== - 1 ) //infinite solution
            return inf;
    return 1 ; //unique solution
}
int main()
{
    int n,m;
    while(scanf("%d",&n)==1)
    {
        vector<vector<double> > mat(n);
        vector<double> ans;
        double v;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                scanf("%lf",&v);
                mat[i].push_back(v);
            }
        }
        int d=gauss(mat,ans);
        if(d) for(int i=0; i<n; i++) debug(ans[i]);
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
