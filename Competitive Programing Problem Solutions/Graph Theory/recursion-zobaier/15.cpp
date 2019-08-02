#include<bits/stdc++.h>
using namespace std;
int n;
int rev(int x,int y){
    if(y==0) return x;
    x=x*10+y%10;
    return rev(x,y/10);
}
int main(){
    cin>>n;
    cout<<rev(0,n)<<endl;
}
