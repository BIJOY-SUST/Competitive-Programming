#include<bits/stdc++.h>
#define mx             1010
#define mod            1000007
//#define pi             2*acos(0.0)
//#define ll             long long int
#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
int aRight[mx][26],bRight[mx][26];
pp dp[mx][mx];
string s1,s2;
pp func(int l,int r){
    if(l==s1.size()||r==s2.size()) return {0,1};
    pp &ret = dp[l][r];
    if(ret.first!=-1) return ret;
    ret ={0,1};
    for(int i=0;i<26;i++){
        int ll=aRight[l][i];
        int rr=bRight[r][i];
        if(ll==-1||rr==-1) continue;
        pp now= func(ll+1,rr+1);
        if(ret.first<now.first+1){
            ret.first=now.first+1;
            ret.second=now.second;
        }
        else if(ret.first==now.first+1){
            ret.second=(ret.second+now.second)%mod;
        }
    }
    return ret;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        cin>>s1>>s2;
        mem(aRight,-1);
        mem(bRight,-1);
        for(int i=0;i<=s1.size();i++) for(int j=0;j<=s2.size();j++)
            dp[i][j].first=-1;
        for(int i=0;i<=s1.size();i++) for(int j=0;j<=s2.size();j++)
            dp[i][j].second=0;
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=0;j<26;j++){
                aRight[i][j]=aRight[i+1][j];
            }
            aRight[i][s1[i]-'a']=i;
        }
        for(int i=s2.size()-1;i>=0;i--){
            for(int j=0;j<26;j++){
                bRight[i][j]=bRight[i+1][j];
            }
            bRight[i][s2[i]-'a']=i;
        }
        int ans = func(0,0).second;
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/*
Input:

Output:

*/














































































///Solution using Table
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define mod 1000007
//#define inf 0x3f3f3f3f
//int dp[1010][1010];
//int f[1010][1010];
//char s1[1010],s2[1010];
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    for(int cas=1;cas<=t;cas++)
//    {
//        scanf("%s %s",s1+1,s2+1);
//        int lena=strlen(s1+1);
//        int lenb=strlen(s2+1);
//        memset(dp,0,sizeof(dp));
//        memset(f,0,sizeof(f));
//        for(int i=0;i<=lena;i++) f[i][0]=1;
//        for(int i=0;i<=lenb;i++) f[0][i]=1;
//        for(int i=1;i<=lena;i++)
//        {
//            for(int j=1;j<=lenb;j++)
//            {
//                if(s1[i]==s2[j])
//                {
//                    dp[i][j]=dp[i-1][j-1]+1;
//                    f[i][j]=f[i-1][j-1];
//                }
//                else if(dp[i][j-1]>dp[i-1][j])
//                {
//                    dp[i][j]=dp[i][j-1];
//                    f[i][j]=f[i][j-1];
//                }
//                else if(dp[i][j-1]<dp[i-1][j])
//                {
//                    dp[i][j]=dp[i-1][j];
//                    f[i][j]=f[i-1][j];
//                }
//                else
//                {
//                    dp[i][j]=dp[i-1][j];
//                    f[i][j]=(f[i-1][j]+f[i][j-1]-(dp[i][j]==dp[i-1][j-1]?f[i-1][j-1]:0)%mod+2*mod)%mod;
//
//                }
////                cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<f[i][j]<<endl;
//
//            }
//        }
//        printf("Case %d: %d\n",cas,f[lena][lenb]);
//    }
//    return 0;
//}

