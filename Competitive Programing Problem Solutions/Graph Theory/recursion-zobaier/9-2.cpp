#include<bits/stdc++.h>
using namespace std;
int a,b,i,j;
int gcd(int u,int v){
    if(v==0) return u;
    return gcd(v,u%v);
}
int main(){
    cin>>a>>b;
    (a<b)? i=a:i=b;
    (a>b)? j=a:j=b;
    cout<<gcd(i,j)<<endl;
    return 0;
}

