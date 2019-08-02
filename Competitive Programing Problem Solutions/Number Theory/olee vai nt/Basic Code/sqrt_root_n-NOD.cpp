#include<bits/stdc++.h>
using namespace std;
int countDivisor(int n){
    int divisor=0;
    for(int i=1;i*i<=n;i++){
        if(i*i==n){
            divisor+=1;
        }
        else if(n%i==0){
            divisor+=2;
        }
    }
    return divisor;
}
int main(){
    int n;
    cin>>n;
    cout<<countDivisor(n)<<'\n';
    return 0;
}
