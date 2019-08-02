#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 0.000000001;
int Leading_Digits(int n,int k){
    double x = k*log10(n);
    x-=floor(x+eps);
    x=pow(10.0,x)*100;
    return floor(x+eps);
}
ll Trailing_Digits(ll a,ll p,ll m){
    ll ans=1%m,x=a%m;
    while(p){
        if(p&1) ans=(ans*x)%m;
        x=(x*x)%m;
        p=p>>1;
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,k;
        scanf("%d %d",&n,&k);
        int most=Leading_Digits(n,k);
        int lest=Trailing_Digits(n,k,1000);
        printf("Case %d: %3d %03d\n",i,most,lest);
//        printf("Case %d: %3d %3d\n",i,most,lest);
    }
    return 0;
}
