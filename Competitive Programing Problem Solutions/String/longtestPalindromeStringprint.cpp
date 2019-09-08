#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
/************** [Faster I/O FUNCTIONS] **************/
#define     pf                  printf
#define     sfs(a)              scanf("%s",&a)
#define     sfi1(a)             scanf("%d",&a)
#define     sfi2(a,b)           scanf("%d %d",&a,&b)
#define     sfi3(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define     sfi4(a,b,c,d)       scanf("%d %d %d %d",&a,&b,&c,&d)
#define     sfd1(a)             scanf("%lf",&a)
#define     sfd2(a,b)           scanf("%lf %lf",&a,&b)
#define     sfd3(a,b,c)         scanf("%lf %lf %lf",&a,&b,&c)
#define     sfd4(a,b,c,d)       scanf("%lf %lf %lf %lf",&a,&b,&c,&d)
#define     sfll1(a)            scanf("%lld",&a)
#define     sfll2(a,b)          scanf("%lld %lld",&a,&b)
#define     sfll3(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
#define     sfll4(a,b,c,d)      scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define     sfull1(a)           scanf("%llu",&a)
#define     sfull2(a,b)         scanf("%llu %llu",&a,&b)
#define     sfull3(a,b,c)       scanf("%llu %llu %llu",&a,&b,&c)
/************** [LEGENDS/CONSTANTS] **************/
#define hi cout<<"Hi, BIJOY...!"<<nl
#define nl '\n'
#define mp make_pair
#define ll long long
#define ull unsigned long long int
#define pb push_back
#define eb emplace_back
#define F first
#define S second
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plp;
typedef pair<pll, ll> ppl;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, int> ppi;
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end
#define fast            ios_base::sync_with_stdio(false), cin.tie(NULL)
ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}

///geometri_basic
struct Point{double x,y;};
struct StateLine{double x,y,c;};
StateLine line(Point A, Point B){StateLine L;L.x=B.y-A.y;L.y=A.x-B.x;L.c=L.x*A.x+L.y*A.y;return L;}
StateLine lombo_line(Point A, Point B){
    Point M;M.x=(A.x+B.x)/2.00;M.y=(A.y+B.y)/2.00;
    StateLine L; L.x=A.x-B.x;L.y=A.y-B.y;L.c=M.x*B.x-M.x*A.x+M.y*B.y-M.y*A.y;return L;
}
Point line_intersect(StateLine A, StateLine B){Point P;double d=(A.x*B.y-B.x*A.y);if(d==0){/*parallel;*/}
    P.x=(B.y*A.c-A.y*B.c)/d;P.y=(A.x*B.c-B.x*A.c)/d;return P;}
    double Distance(Point A, Point B){return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

///Ordered Set
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>order_set;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>p_order_set;
//*st.find_by_order(x) && st.order_of_key(x)
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>prefix_trie;
//auto range = st.prefix_range(string) && (auto it=range.first;it!=range.second;it++)

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}

//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}
//prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mxn       = (300000)+10 , inf = 0x3f3f3f3f;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536, EPS = 1e-9;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define BIJOY 2016331012
#undef BIJOY
/************************Code start here*******************/

char str[1000010];

char* longestPalindrome(char* s) {
    int slen = strlen(s);
    int tlen = slen * 2 + 1;
    char t[tlen];
    for (int i = 0; i < slen; i++) {
        t[2 * i] = '|';
        t[2 * i + 1] = s[i];
    }

    t[tlen - 1] = '|';
    int lps_len[tlen];

    int c = 0, r = 0, max = 0;
    lps_len[0] = 0;
    for (int i = 1; i < tlen; i++) {
        if (i < r && i + lps_len[2 * c - i] < r) {
            lps_len[i] = lps_len[2 * c - i];
        } else {
            int j = r + 1;
            while (j < tlen && 2 * i - j > -1 && t[j] == t[2 * i - j]) {
                j++;
            }
            lps_len[i] = j - i - 1;
            c = i;
            r = j - 1;
            if (lps_len[i] > lps_len[max]) {
                max = i;
            }
        }
    }

    int max_len = lps_len[max];
    int max_index = (max - max_len) / 2;
    char *buf = (char *) malloc(sizeof(char) * (max_len + 1));
    for (int i = 0; i < max_len; i++) {
        buf[i] = s[i + max_index];
    }
    buf[max_len] = '\0';
    return buf;
}




void Solve(){

	sfs(str);

	printf("%s\n", longestPalindrome(str) );



    return;
}


int32_t main() {
    #ifdef BIJOY
        TimeStart = chrono::steady_clock::now();
    #endif

    Solve();

    #ifdef BIJOY
        TimeEnd = chrono::steady_clock::now();
        auto ElapsedTime = TimeEnd - TimeStart;
        cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
    #endif
    return 0;
}