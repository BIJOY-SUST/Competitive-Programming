//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
int dp1[40][40];
ll dp2[40][40][70];
string s1,s2;
int ans1;
ll ans2;
int lcs(int i,int j){
    if(i>=s1.size()||j>=s2.size()) return 0;
    int &ret=dp1[i][j];
    if(ret!=-1) return ret;
    ret=0;
    if(s1[i]==s2[j]){
        ret=lcs(i+1,j+1)+1;
    }
    else{
        ret=max(lcs(i+1,j),lcs(i,j+1));
    }
    return ret;
}
ll distinct(int i,int j,int c){
    if(i>=s1.length()){
//        cout<<c<<endl;
        c+=s2.length()-j;
//        cout<<"i "<<i<<" "<<j<<" "<<c<<" "<<ans1<<'\n';
        if(c==ans1) return 1;
        else return 0;
    }
    if(j>=s2.length()){
//        cout<<c<<endl;
        c+=s1.length()-i;
//        cout<<"j "<<i<<" "<<j<<" "<<c<<" "<<ans1<<'\n';
        if(c==ans1) return 1;
        else return 0;
    }
    ll &ret=dp2[i][j][c];
    if(ret!=-1) return ret;
    ret=0;
    if(s1[i]==s2[j]){
        ret=distinct(i+1,j+1,c+1);
    }
    else{
        ret+=distinct(i+1,j,c+1);
        ret+=distinct(i,j+1,c+1);
    }
    return ret;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    fast;
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(dp1,-1);
        mem(dp2,-1);
        cin>>s1>>s2;
        ans1=s1.length()+s2.length()-lcs(0,0);
//        cout<<lcs(0,0)<<endl;
        ans2=distinct(0,0,0);
        cout<<"Case "<<cs<<": "<<ans1<<" "<<ans2<<'\n';
    }
    return 0;
}
/*
We have to find two things :
1. The length of the shortest string that contains the names as subsequence.
2. Total number of unique shortest strings which contain the names as subsequence.

lets analyse the 1st case :
USA
USSR

The shortest string length that contains the names as subsequence is : 5 and there are three strings of length 5 which contains "USA" and "USSR" as subsequence (note that it is not substring).
USSAR
USASR
USSRA

So the answer is 5(shortest string length) 3 (number of strings).

hope it helps.
*/
