#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
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
int dp[101][101];
string str1,str2;
void print_path(){
    int i=str1.length();
    int j=str2.length();
    while(i>0||j>0){
        if(str1[i-1]==str2[j-1]){
            i--;
            j--;
        }
        else if(j>0&&dp[i][j]==dp[i][j-1]+1){
            cout<<"I"<<str2[j-1];
            if(i<=8) cout<<"0";
            cout<<i+1;
            j--;
        }
        else if(i>0&&j>0&&dp[i][j]==dp[i-1][j-1]+1){
            cout<<"C"<<str2[j-1];
            if(i<=9) cout<<"0";
            cout<<i;
            i--;
            j--;
        }

        else if(i>0&&dp[i][j]==dp[i-1][j]+1){
            cout<<"D"<<str1[i-1];
            if(i<=9) cout<<"0";
            cout<<i;
            i--;
        }
    }
    cout<<"E\n";
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>str1){
        if(str1[0]=='#') break;
        cin>>str2;
        mem(dp,0);
        for(int i=0;i<=str1.length();i++){
            for(int j=0;j<=str2.length();j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
            }
        }
        print_path();
    }
    return 0;
}
/**
Sample Input
abcde bcgfe
#
Sample Output
Da01Cg03If04E
**/
