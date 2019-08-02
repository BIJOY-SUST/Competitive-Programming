#include<bits/stdc++.h>
#define pi 3.1416
using namespace std;
int main(){
    int d,v,u;
    cin>>d>>v>>u;
    double p=d/u;
    double w=sqrt(u*u+v*v);
    double s=2*d/w;
    cout<<p<<" "<<s<<'\n';
    return 0;
}
