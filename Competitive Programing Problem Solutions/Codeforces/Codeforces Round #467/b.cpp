#include<bits/stdc++.h>
#define mx             1000000010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
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
vector<ll>ans;
bool mark[mx];

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll p,y;
    scanf("%lld%lld",&p,&y);
    mem(mark,false);

    for(int i=3;i<=p;i+=2){
        if(!mark[i])
        for(int j=i*i;j<=sqrt(y);j+=2*i){
            mark[j]=true;
        }
    }
    mark[p]=true;
    if(y%2==0) y--;
    for(int i=y;i>p;i-=2){
        if(!mark[i]) ans.push_back(i);
    }
    if(ans.size()){
//        reverse(ans.begin(),ans.end());
        printf("%lld\n",ans[0]);
    }
    else{
        printf("-1\n");
    }
    return 0;
}
/**
Input:

Output:

**/
