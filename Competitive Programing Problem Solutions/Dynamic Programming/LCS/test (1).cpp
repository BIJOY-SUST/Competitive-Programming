#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);

    return 0;
}
/*
Input:

Output:

*/
























#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000007
#define inf 0x3f3f3f3f
int dp[1010][1010];
int f[1010][1010];
char s1[1010],s2[1010];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%s %s",s1+1,s2+1);
        int lena=strlen(s1+1);
        int lenb=strlen(s2+1);
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        for(int i=0;i<=lena;i++) f[i][0]=1;
        for(int i=0;i<=lenb;i++) f[0][i]=1;
        for(int i=1;i<=lena;i++)
        {
            for(int j=1;j<=lenb;j++)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    f[i][j]=f[i-1][j-1];
                }
                else if(dp[i][j-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i][j-1];
                    f[i][j]=f[i][j-1];
                }
                else if(dp[i][j-1]<dp[i-1][j])
                {
                    dp[i][j]=dp[i-1][j];
                    f[i][j]=f[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    f[i][j]=(f[i-1][j]+f[i][j-1]-(dp[i][j]==dp[i-1][j-1]?f[i-1][j-1]:0)%mod+2*mod)%mod;

                }
//                cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<f[i][j]<<endl;

            }
        }
        printf("Case %d: %d\n",cas,f[lena][lenb]);
    }
    return 0;
}

