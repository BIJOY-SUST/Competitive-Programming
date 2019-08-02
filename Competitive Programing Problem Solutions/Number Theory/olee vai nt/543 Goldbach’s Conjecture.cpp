#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n<2) return false;
    for(int i=2;i<=(int)sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
        if(n==0) break;
        bool flag=true;
        int a=3;
        int b=n;
        while(a<b){
            b=n-a;
            if(isprime(a)&&isprime(b)){
                cout<<n<<" = "<<a<<" + "<<b<<'\n';
                flag=false;
                break;
            }
            a+=2;
        }
        if(flag==true) cout<<"Goldbach's conjecture is wrong."<<'\n';
    }
    return 0;
}
