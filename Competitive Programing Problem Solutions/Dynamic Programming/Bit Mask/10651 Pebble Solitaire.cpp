#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
int biton(int n,int pos){return n=n|(1<<pos);}
int bitoff(int n,int pos){return n=n&~(1<<pos);}
bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;
//int dp[(1<<12)+5];
int bit_mask(int sum){
//    int &ret=dp[sum];
//    if(ret!=-1) return ret;
    int ret=__builtin_popcount(sum);
    int temp;
    for(int i=0;i<11;i++){
        if(bitcheck(sum,i)&&bitcheck(sum,i+1)){
            if(i>0&&!bitcheck(sum,i+2)&&!bitcheck(sum,i-1)&&i<10){
                temp=bitoff(sum,i);
                temp=bitoff(temp,i+1);
                ret=min(ret,bit_mask(biton(temp,i-1)));
                ret=min(ret,bit_mask(biton(temp,i+2)));
            }
            else if(i>0&&!bitcheck(sum,i-1)){
                temp=bitoff(sum,i);
                temp=bitoff(temp,i+1);
                ret=min(ret,bit_mask(biton(temp,i-1)));
            }
            else if(!bitcheck(sum,i+2)&&i<10){
                temp=bitoff(sum,i);
                temp=bitoff(temp,i+1);
                ret=min(ret,bit_mask(biton(temp,i+2)));
            }
        }
    }
    return ret;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
//        memset(dp,-1,sizeof(dp));
        int sum=0;
        string s;
        cin>>s;
        for(int i=0;i<12;i++){
            if(s[i]=='o') sum=biton(sum,i);
        }
//        cout<<sum<<endl;
        int ans=bit_mask(sum);
        printf("%d\n",ans);
    }
    return 0;
}
/*
5
---oo-------
-o--o-oo----
-o----ooo---
oooooooooooo
oooooooooo-o
Sample Output
1
2
3
12
1
*/
