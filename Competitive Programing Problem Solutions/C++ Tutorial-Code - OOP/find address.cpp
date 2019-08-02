#include<bits/stdc++.h>
using namespace std;
int f(int a,int b){
    return a+b;
}
void f(int n){
    cout<<n<<endl;
}
int main(){
   /* int (*p)(int,int);
    p=f;
    int (*o)(int);
    o=a;
    cout<<p<<endl;
    cout<<p(5,6)<<endl;
    cout<<o<<endl;*/
    int (*p1)(int,int);
    p1 = f;
    cout<<p1<<endl;
    cout<<p1(5,6)<<endl;

    void (*p2)(int);
    cout<<p2<<endl;
    p2 = f;
    p2(5);

    return 0;
}

