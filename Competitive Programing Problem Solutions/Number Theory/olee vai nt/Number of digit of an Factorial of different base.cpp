#include<bits/stdc++.h>
using namespace std;
int num_digit_fac(int n,int base){
    double x=0;
    for(int i=1;i<=n;i++){
        x+=log10(i)/log10(base);
    }
    int ans=((int)x)+1;
    return ans;
}
int main(){
    int n,base;
    cin>>n>>base;
    cout<<num_digit_fac(n,base)<<'\n';
    return 0;
}
