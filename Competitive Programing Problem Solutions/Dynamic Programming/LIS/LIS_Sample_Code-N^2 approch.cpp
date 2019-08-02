///Longest Increasing Subsequence
///An O(n2) approach
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

int m_pos,n,arr[mx],dp[mx],sequence[mx];
int LIS(){
    for(int i=0;i<mx;i++) dp[i]=1;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        if(arr[j]>arr[i]&&dp[j]<dp[i]+1) dp[j]=dp[i]+1;
    int ans=0;
//    for(int i=0;i<n;i++) cout<<dp[i]<<" ";
//    cout<<endl;
    for(int i=0;i<n;i++) if(ans<dp[i]){ans=dp[i];m_pos=i;}
    return ans;
}
void lis_print(int M){
    int top=M-1;
    sequence[top]=arr[m_pos];top--;
    for(int i=m_pos-1;i>=0;i--) if(arr[i]<arr[m_pos]&&dp[i]==dp[m_pos]-1){
        m_pos=i;sequence[top]=arr[m_pos];top--;
    }
    printf("LIS is :");
    for(int i=0;i<M;i++) printf(" %d",sequence[i]);
    printf("\n");
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int ans=LIS();
    printf("The LIS length is %d\n",ans);
    lis_print(ans);
    return 0;
}
/*
Input:
20
4964 6419 169 1651 61 981 6941 6 1 914 5 5416 4106 41 961986 419 419 416 1 14
Output:
The LIS length is 4
LIS is : 1 5 41 961986
*/
