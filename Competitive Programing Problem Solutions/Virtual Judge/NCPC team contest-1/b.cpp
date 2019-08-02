//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fread(p) freopen(p,"r",stdin);
#define fwrite(p) freopen(p,"w",stdout);
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define nl "\n"
#define mem(s,k) memset(s, k, sizeof(s))
#define sf scanf
#define pf printf
#define PI 2*acos(0.0)
#define ALL(p) (p.begin(),p.end())
#define mod(a,b) ((((a)%(b))+(b))%(b))
#define debug(x) cout<< #x" " << x <<endl
#define time_start clock_t start = clock();
#define time_end clock_t finish = clock(); cout << (double)(finish-start)/CLOCKS_PER_SEC << endl;
const double EPS = 1e-9;

////--- Graph Moves---////
//const ll xx[] = {0,0,1,-1};
//const ll yy[] = {1,-1,0,0};
//const ll xx_king[] = {0,0,1,-1,1,1,-1,-1};
//const ll yy_king[] = {1,-1,0,0,1,-1,1,-1};
//const ll xx_knight[]= {-2,-1,1,2,2,1,-1,-2};
//const ll yy_knight[]= {1,2,2,1,-1,-2,-2,-1};
////------------------////

//template<typename T> POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//template<typename T> BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//template<typename T> ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template<typename T> using orderedSet = tree< T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

////----------- Bit Manipulation -----------------//
//int bitOn(int N,int pos){return N=N OR (1<<pos);}
//int bitOff(int N,int pos){return N= N &~(1<<pos);}
//bool bitCheck(int N,int pos){return (bool)(N & (1<<pos));}
////---------------------------------------------//

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll x,n;
        cin >> x >> n;
        if(n==1){
            cout<<x<<nl;
            continue;
        }
        if(x > n)
        {
            vector<ll> g(n+2,0);
            for(int i=1; i<=n; i++)
                g[i] = 1;
            x -= n;
            ll p = n-1, d = x/p, rem = x%p;

            for(int i=2; i<=n-1; i++)
                g[i] += d;

            if(d%2 == 0){
                g[1] += d/2;
                g[n] += d/2;
                int j= n-1;
                while(rem != 0)
                    g[j]++, j--, rem--;
            }
            else{
                g[n] += d/2;
                g[1] += (d/2) + 1;
                int j= 2;
                while(rem != 0)
                    g[j]++, j++, rem--;
            }
            for(int i=1; i<=n; i++)
                cout << g[i] << " ";
            cout << nl;
        }
        else{
            for(int i=1; i<=x; i++)
                cout << 1 << " ";
            for(int i=x+1; i<=n; i++)
                cout << 0 << " ";
            cout << nl;
        }
    }
}
