#include<bits/stdc++.h>
using namespace std;
const double eps=.000000001;
int leadingDigitFact(int n,int k){
    double fact=0;
    for(int i=1;i<=n;i++){
        fact+=log10(i);
    }
    double q=fact-floor(fact+eps);
    double b=pow(10,q);
    for(int i=0;i<k-1;i++){
        b*=10;
    }
    return floor(b+eps);
}
int main(){
    int n,k;
    cin>>n>>k;
    int ans=leadingDigitFact(n,k);
    cout<<ans<<'\n';
    return 0;
}
