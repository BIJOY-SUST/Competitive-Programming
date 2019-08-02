#include<bits/stdc++.h>
#define mx             1000010
#define mod            100000007
//#define pi             2*acos(0.0)
#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
ll fact[mx],p_num[mx],cnt=0;
void perfect_powers(){
    for(ll i=2;i<=1e5;i++){
        ll num=i*i;
        while(num<=1e10){
            p_num[cnt++]=num;
//            cout<<"BIJOY"<<endl;
            num*=i;
        }
    }
    sort(p_num,p_num+cnt);
    cnt=unique(p_num,p_num+cnt)-p_num;
    p_num[cnt++]=1e18;
}
void find_fact(){
    fact[0]=1;
    for(int i=1;i<mx;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    perfect_powers();
//    cout<<"BIJOY"<<endl;
    find_fact();
    ll t;
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        ll n=(upper_bound(p_num,p_num+cnt,b)-p_num)-(lower_bound(p_num,p_num+cnt,a)-p_num);
//        cout<<"BIJOY "<<n<<endl;
        if(n==0) printf("Case %lld: 0\n",cs);
        else{
            ll x=(fact[n+1]*fact[n])%mod;
    //        cout<<x<<endl;
            ll ans=ModInverse(x,mod);
    //        cout<<ans<<endl;
            ans=(fact[2*n]*ans)%mod;
    //        cout<<ans<<endl;
            printf("Case %lld: %lld\n",cs,ans);
        }
    }
    return 0;
}
/**
BIJOY 50694448
Input:
1
1 10
Output:
Case 3: 5
**/
