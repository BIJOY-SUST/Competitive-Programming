///Using Extended Euclidean Algorithm
///Works when a and m are coprime and m is not prime
//We are trying to solve the congruence, AX≡1(mod M).
//We can convert this to an equation.
//
//AX≡1(mod M)
//AX+MY=1
//
//Here, both X and Y are unknown.
//This is a linear equation and we want to find integer solution for it.
//Which means, this is a Linear Diophantine Equation.
#include<bits/stdc++.h>
using namespace std;
int Ext_GCD(int a,int m,int *x,int *y){
    if(a==0){///Base case
        *x=0;
        *y=1;
        return m;
    }
    int x1,y1;
    int gcd=Ext_GCD(m%a,a,&x1,&y1);
    *x=y1-(m/a)*x1;
    *y=x1;
    return gcd;
}
void Modular_Inverse(int a,int m){
    int x,y;
    int g=Ext_GCD(a,m,&x,&y);

    if(g!=1) cout<<"Inverse doesn't exist"<<'\n';
    else{
        int ans=(x%m+m)%m;
        cout<<"Modular Multiplicative Inverse is: "<<ans<<'\n';
    }
}
int main(){
    int a,m;
//    cin>>a>>m;
    while(cin>>a>>m){
        Modular_Inverse(a,m);
    }
    return 0;
}
