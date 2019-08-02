#include<bits/stdc++.h>

using namespace std;

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
#define ump             unordered_map
#define uset            unordered_set
#define PQ              priority_queue
#define nl              '\n'
#define pf              printf
#define sf              scanf
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define grtsrt(v)       sort(v.begin(),v.end(),greater<int>())
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)

template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}

const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 1e6+10;
const int inf       = 0x3f3f3f3f;
const int mod       = 1e9+7;
const double pi         = 2*acos(0.0);
const double E          = 2.71828182845904523536;
const double eps        = 1e-6;
bool mark[mx];vector<int>prime;
void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(mx);i+=2){if(mark[i]){for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///code start here


int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    fast;
    ll t;
    cin>>t;
    for(ll cs=1;cs<=t;cs++){

        double l,w;
        cin>>l>>w;
        cout<<"Case "<<cs<<": ";
        if(l<w){
            swap(l,w);
        }
        double low=0,hi=w/2.0,mid,a,b,h,ans;
        for(int i=1;i<=100;i++){
            mid=(low+hi)/2.0;
            h=mid-eps;
            a=h*(l-2.0*h)*(w-2.0*h);
            h=mid+eps;
            b=h*(l-2.0*h)*(w-2.0*h);
            if(a<b){
                low=mid;
            }
            else{
                hi=mid;
            }
            ans=max(a,b);
        }
//        debug(ans);
        cout<<fixed<<setprecision(10)<<ans<<nl;


    }
    return 0;
}
