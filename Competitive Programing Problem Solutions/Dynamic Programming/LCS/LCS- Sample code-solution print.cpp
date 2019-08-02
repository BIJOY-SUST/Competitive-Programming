#include<bits/stdc++.h>
#define mx             101
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
int dp[mx][mx];
bool vis[mx][mx];
string s1,s2,s;
int lcs(int i,int j){
    if(s1[i]=='\0'||s2[j]=='\0') return 0;
    if(vis[i][j]) return dp[i][j];
    int ans=0;
    if(s1[i]==s2[j]) ans=1+lcs(i+1,j+1);
    else{
        int ret1=lcs(i+1,j);
        int ret2=lcs(i,j+1);
        ans=max(ret1,ret2);
    }
    vis[i][j]=true;
    dp[i][j]=ans;
    return dp[i][j];
}
void printlcs(int i,int j){
    if(s1[i]=='\0'||s2[j]=='\0'){
        cout<<s<<'\n';
        return;
    }
    if(s1[i]==s2[j]){
        s+=s1[i];
        printlcs(i+1,j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1]) printlcs(i+1,j);
        else printlcs(i,j+1);
    }
}
void printall_lcs(int i,int j){
    if(s1[i]=='\0'||s2[j]=='\0'){
        cout<<s<<'\n';
//        cout<<i<<" "<<j<<'\n';
        return;
    }
    if(s1[i]==s2[j]){
        s+=s1[i];
        printall_lcs(i+1,j+1);
//        cout<<i<<" "<<j<<'\n';
        s.erase(s.end()-1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1]) printall_lcs(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1]) printall_lcs(i,j+1);
        else{
            printall_lcs(i+1,j);
            printall_lcs(i,j+1);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    mem(vis,false);
    cin>>s1>>s2;
    int ans=lcs(0,0);
    cout<<ans<<'\n';
    printlcs(0,0);
//    printall_lcs(0,0);
    return 0;
}
/*
HELLOM
HMLLD
hello
loxhe
*/
