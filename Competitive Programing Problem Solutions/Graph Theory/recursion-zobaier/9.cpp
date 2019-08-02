#include<bits/stdc++.h>
using namespace std;
int a,b,i;
int gcd(int j){
    if(a%j==0&&b%j==0){
        cout<<j<<endl;
        return 0;
    }
    return gcd(j+1);
}
int main(){
    cin>>a>>b;
    ///(a<b)? i=a:i=b;
    gcd(2);

    return 0;
}
