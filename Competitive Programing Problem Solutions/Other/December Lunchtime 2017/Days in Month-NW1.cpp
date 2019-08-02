#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
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
char ss[7][10]={"mon", "tues", "wed", "thurs", "fri", "sat" , "sun"};
int s[8];
map<string,int>no;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; scanf("%d",&t);
    while(t--){
        mem(s,0);
        for(int i=0;i<7;i++){
            no[ss[i]]=i+1;
            s[i+1]=4;
//            cout<<no[ss[i]]<<" "<<s[i+1]<<endl;
        }
        int n;
        string s1;
        cin>>n>>s1;
        int start=no[s1];
        int mm=n%7;
//        cout<<mm;
        int d=7-start+1;
//        cout<<mm<<" "<<d<<endl;
        if(d>=mm){
            for(int i=start;i<start+mm;i++){
                s[i]++;
            }
        }
        else{
            int k=mm-d;
            for(int i=start;i<=7;i++){
                s[i]++;
            }
            for(int i=1;i<=k;i++){
                s[i]++;
            }
        }
        printf("%d",s[1]);
        for(int i=2;i<=7;i++){
            printf(" %d",s[i]);
        }
        printf("\n");
    }
    return 0;
}
/*

*/
