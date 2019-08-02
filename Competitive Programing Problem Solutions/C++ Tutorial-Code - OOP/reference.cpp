#include<bits/stdc++.h>
using namespace std;
int& f(int a){
    return a;
}
int main(){
    int a;
    a=5;
    int *p;
    p=&a;

    int& r = *p;
    r=6;
    f(a)=7;
    //cout<<f(a)<<endl;
    return 0;
}
