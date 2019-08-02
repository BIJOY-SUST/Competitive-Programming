#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
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
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
vector<ll>v,v1,v2,ans;
void bijoy(ll cnt,ll n,ll sum){
    if(cnt==n){
        ans.push_back(sum);
//        cout<<sum<<endl;
        return;
    }
    bijoy(cnt+1,n,sum+v[cnt]);
    bijoy(cnt+1,n,sum);
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        v.clear();
        v1.clear();
        v2.clear();
        ans.clear();
        ll n,w,k;
        scanf("%lld%lld",&n,&w);
        for(ll i=0;i<n/2;i++){
            scanf("%lld",&k);
            v.push_back(k);
//            cout<<k<<endl;
        }
//        cout<<"BJIOY"<<endl;
        bijoy(0,v.size(),0);
//        cout<<"BJIOY"<<endl;
        sort(ans.begin(),ans.end());
        v1=ans;
        ans.clear();
        v.clear();
//        cout<<"BIJOY"<<endl;
        for(ll i=n/2;i<n;i++){
            scanf("%lld",&k);
            v.push_back(k);
        }
        bijoy(0,v.size(),0);
        sort(ans.begin(),ans.end());
        v2=ans;
        ans.clear();
        ll boss=0;
        for(int i=0;i<v1.size();i++){
            ll d=w-v1[i];
            ll temp=upper_bound(v2.begin(),v2.end(),d)-v2.begin();
            boss+=temp;
        }
        printf("Case %d: %lld\n",cs,boss);
    }
    return 0;
}
/**
Input:

Output:

**/
