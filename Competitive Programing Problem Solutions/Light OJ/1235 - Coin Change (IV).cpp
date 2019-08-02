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
vector<ll>v,ans,v1,v2;
void bijoy(ll cnt,ll n,ll sum){
    if(cnt==n){
        ans.push_back(sum);
//        cout<<sum<<endl;
        return;
    }
    bijoy(cnt+1,n,sum+v[cnt]+v[cnt]);
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
        }
        bijoy(0,v.size(),0);
        sort(ans.begin(),ans.end());
        v1=ans;
        ans.clear();
        v.clear();
        for(ll i=n/2;i<n;i++){
            scanf("%lld",&k);
            v.push_back(k);
        }
        bijoy(0,v.size(),0);
        sort(ans.begin(),ans.end());
        v2=ans;
        ans.clear();
        bool flag=false;
        for(int i=0;i<v2.size();i++){
            ll d=w-v2[i];
            if(binary_search(v1.begin(),v1.end(),d)){
                flag=true;
                break;
            }
        }
        if(flag){
            printf("Case %d: Yes\n",cs);
        }
        else{
            printf("Case %d: No\n",cs);
        }
    }
    return 0;
}
/**
Input:

Output:

**/
/*
You generate all possible combinations for the left half and right half, and then sort one side,
and for each element on the other side, search its corresponding one in the sorted side using binary search.

However, you have 3 choices for each item, i.e. take 0, 1, or 2 of it. So, if we try to calculate exactly,
generating all possible combination for each side should take 3^(n/2) operations which is 3^9 in the worst case.
let m = 3^(n/2),  then the rest of the thing can be done in O(m lg m)
*/
