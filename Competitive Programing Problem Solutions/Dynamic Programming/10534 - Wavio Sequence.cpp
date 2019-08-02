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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
//        for(int i=0;i<arr.size();i++) cout<<arr[i]<<endl;
        vector<int>lis(n,0),lds(n,0),L(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            int pos=lower_bound(L.begin(),L.begin()+cnt,arr[i])-L.begin();
            L[pos]=arr[i];
            lis[i]=pos+1;
            if(pos==cnt) ++cnt;
        }
        L.assign(n,0);
//        for(int i=0;i<n;i++){
//            cout<<L[i]<<endl;
//        }
        reverse(arr,arr+n);
//        for(int i=0;i<n;i++){
//            cout<<arr[i]<<endl;
//        }
        cnt=0;
        for(int i=0;i<n;i++){
            int pos=lower_bound(L.begin(),L.begin()+cnt,arr[i])-L.begin();
            L[pos]=arr[i];
            lds[i]=pos+1;
            if(pos==cnt) ++cnt;
        }
        L.assign(n,0);

        reverse(lds.begin(),lds.end());
//        for(int i=0;i<n;i++){
//            cout<<lds[i]<<endl;
//        }
//        cout<<lis.size()<<" "<<lds.size()<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
//            cout<<lis[i]<<" "<<lds[i]<<endl;
            ans=max(ans,2*min(lis[i],lds[i])-1);
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/*

*/
