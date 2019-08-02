#include<bits/stdc++.h>
using namespace std;
int abc(int a,int b){
    return a+b;
}
void abc(int a){
    cout<<a<<endl;
}
int main(){
    int (*p2)(int,int);
    p2=abc;
    cout<<p2<<endl;
    cout<<p2(4,5)<<endl;
    void (*p1)(int);
    cout<<p1<<endl;
    p1=abc;
    p1(6);
    abc(5);
    //cout<<p<<endl;
    return 0;
}
