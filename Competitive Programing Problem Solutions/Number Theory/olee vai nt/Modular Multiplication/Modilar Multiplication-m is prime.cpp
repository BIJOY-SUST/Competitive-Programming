///Modular Multiplication...
///If we know m is prime,
///then we can also use Fermats’s little theorem to find the inverse.
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int m){
    return a==0?abs(m):gcd(m%a,a);
//    int gcd(int a,int b){
/////    return b==0?a:gcd(b,a%b);
//    return (a%b==0)?abs(b):gcd(b,a%b);
}
int Big_Mod(int a,int p,int m){
    int ans=1%m,x=a%m;
    while(p){
        if(p&1) ans=(ans*x)%m;
        x=(x*x)%m;
        p>>=1;
    }
    return ans;
}
//int Big_Mod(int x, unsigned int y, unsigned int m)
//{
//    if (y == 0)
//        return 1;
//    int p = Big_Mod(x, y/2, m) % m;
//    p = (p * p) % m;
//
//    return (y%2 == 0)? p : (x * p) % m;
//}
void Modular_Inverse(int a,int m){
    int g=gcd(a,m);
    if(g!=1) cout<<"Inverse doesn't exist"<<'\n';
    else{
        cout<<"Modular multiplicative inverse: "<<Big_Mod(a,m-2,m)<<'\n';
    }
}
int main(){
    int a,m;
    while(cin>>a>>m){
        Modular_Inverse(a,m);
    }
    return 0;
}
