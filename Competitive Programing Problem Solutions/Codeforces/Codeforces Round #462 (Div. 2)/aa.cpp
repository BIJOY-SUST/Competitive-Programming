#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define ll             long long int
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
vector<ll>a,b;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++){
        ll k; scanf("%lld",&k);
        a.push_back(k);
    }
    bool f=false;
    for(int i=0;i<m;i++){
        ll k; scanf("%lld",&k);
        b.push_back(k);
        if(k>0){
            f=true;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<ll>vv;
//    if(f){
        vector<ll>vvv;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll temp=a[i]*b[j];
    //            cout<<a[i]<<" "<<b[j]<<" "<<temp<<endl;
                vv.push_back(temp);
            }
            sort(vv.rbegin(),vv.rend());
            vvv.push_back(vv[0]);
            vv.clear();
        }
            sort(vvv.rbegin(),vvv.rend());

        printf("%lld\n",vvv[1]);
//    }
//    else{
//        for(int i=1;i<n;i++){
//            for(int j=0;j<m;j++){
//                ll temp=a[i]*b[j];
//    //            cout<<a[i]<<" "<<b[j]<<" "<<temp<<endl;
//                vv.push_back(temp);
//            }
//        }
//        sort(vv.rbegin(),vv.rend());
//        printf("%lld\n",vv[0]);
//    }
}
/*
Input:
5 6
-5 -4 -5 -6 -9
-1 -0 -1 -5 -6 -8
Output:

*/
