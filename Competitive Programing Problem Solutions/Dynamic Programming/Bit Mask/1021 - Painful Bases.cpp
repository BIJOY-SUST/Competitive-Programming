#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
#define ll             long long int
#define one(n)         __builtin_popcount(n)
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
int arr[101];
ll dp[20][(1<<16)+5];
int base,k;
string s;
ll sieve(int value,int num){
//    cout<<s.length()<<endl;
    ll &ret=dp[value][num];
    if(one(num)==s.length()){//return value==0;
        if(value==0) return 1;///মানে সংখ্যাটা K দ্বারা বিভাজ্য কি না,হলে count ১ করে পাঠাবে...!
        else return 0;
    }
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<s.length();i++){
        if(!bitcheck(num,i)){
//            cout<<"Before "<<ret<<" "<<arr[i]<<" "<<value<<" "<<num<<" "<<i<<endl;
            ret+=sieve((value*base+arr[i])%k,biton(num,i));
//            cout<<"   After "<<ret<<" "<<arr[i]<<" "<<value<<" "<<num<<" "<<i<<endl;

        }
    }
//    cout<<ret<<endl;
    return dp[value][num]=ret;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%d %d",&base,&k);
        s.clear();
        cin>>s;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.length();i++){
            if(s[i]>='0'&&s[i]<='9') arr[i]=s[i]-'0';
            else arr[i]=s[i]-'A'+10;
        }
//        for(int i=0;i<s.length();i++) cout<<arr[i]<<endl;
        ll ans=sieve(0,0);
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
/*
Input:
3

2 2
10

10 2
5681

16 1
ABCDEF0123456789
Output:
Case 1: 1
Case 2: 12
Case 3: 20922789888000
*/
