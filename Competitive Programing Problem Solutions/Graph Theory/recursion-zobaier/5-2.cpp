#include<bits/stdc++.h>
using namespace std;
int x,n,ans=0;
int print(int i){
    if(n==0)
    return 1;
    if(i<n)
        return (int)pow(x,i)+print(i+1);
    return 0;
}
int main(){
    cin>>x>>n;

    cout<<print(0)<<endl;
    return 0;
}


