#include<bits/stdc++.h>
using namespace std;
int zero_factorial(int N,int x){
    int counter=0;
    while(N>=1){
        counter+=N/x;
        N=N/x;
    }
    return counter;
}
int zero_pow(int N,int x){
    int counter = 0;
    while(N%x==0){
        counter++;
        N=N/x;
    }
    return counter;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int T,h=0;
    cin>>T;
    while(T--){
    int n,r,p,q;
    cin>>n>>r>>p>>q;
    int i = zero_factorial(n, 2);
    int j = zero_factorial(n, 5);
    int k = zero_factorial(r, 2);
    int l = zero_factorial(r, 5);
    int m = zero_factorial(n-r, 2);
    int mm = zero_factorial(n-r, 5);
    int px = q*zero_pow(p, 2);
    int py = q*zero_pow(p, 5);
    int ans = min(i-k-m+px,j-l-mm+py);
    cout<<"Case "<<++h<<": "<<ans<<"\n";
    }
    return 0;
}

