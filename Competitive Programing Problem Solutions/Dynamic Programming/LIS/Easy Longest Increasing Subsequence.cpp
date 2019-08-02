#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//
int m_pos,n,arr[mx],dp[mx],I[mx],sequence[mx];
int LIS(){
    I[0]=-inf;
    for(int i=1;i<=n;i++) I[i]=inf;
    int lis_len=0;
    for(int i=0;i<n;i++){
        int low=0,high=lis_len,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(I[mid]<arr[i]) low=mid+1;
            else high=mid-1;
//            cout<<"mid "<<low<<" "<<high<<" "<<mid<<endl;
        }
//        cout<<"i "<<i<<" "<<low<<" "<<high<<" "<<lis_len<<endl;
        I[low]=arr[i];
        dp[i]=low;
        if(lis_len<low){lis_len=low;m_pos=i;}
    }
//    for(int i=0;i<n;i++) cout<<dp[i]<<" ";
//    cout<<endl;
    return lis_len;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int ans=LIS();
    printf("%d\n",ans);
    return 0;
}
/*

*/
