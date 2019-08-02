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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    queue<int>st;
    int j=0,cnt=0;
    int ans=-1;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            st.push(i);
            cnt++;
        }
        if(cnt>k){
//            cout<<i<<" "<<j<<endl;
            flag=true;
            ans=max(ans,i-j);
            j=st.front()+1;
            st.pop();
            cnt--;
        }
    }
//    cout<<cnt<<" "<<j<<endl;
//    cout<<"joy"<<endl;
    if(!flag) ans=n;
    else if(flag) ans=max(ans,n-j);
    while(!st.empty()) st.pop();
    j=0,cnt=0;
    flag=false;
    for(int i=0;i<n;i++){
        if(s[i]=='b'){
            st.push(i);
            cnt++;
        }
        if(cnt>k){
//            cout<<i<<" "<<j<<endl;
            flag=true;
            ans=max(ans,i-j);
            j=st.front()+1;
            st.pop();
            cnt--;
        }
    }
//    cout<<cnt<<" "<<j<<endl;
    if(!flag) ans=n;
    else if(flag) ans=max(ans,n-j);
    cout<<ans<<endl;
    return 0;
}
/*
input
8 1
aabaabaa
10
2
babbaabbbb
output
5
*/
