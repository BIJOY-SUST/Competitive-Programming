#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,px,py,qx,qy,rx,ry;
    cin>>n;
    while(n--){
        cin>>px>>py>>qx>>qy;
        int a,b;
        a=qx+qx-px;
        b=qy+qy-py;
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}
