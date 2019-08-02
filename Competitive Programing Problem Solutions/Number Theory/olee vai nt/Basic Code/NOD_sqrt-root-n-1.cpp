#include<bits/stdc++.h>
using namespace std;
int countDivisor(int n){
    int divisor=0;
    int sqrtn=sqrt(n);
    for(int i=1;i<sqrtn;i++){
        if(n%i==0){
            divisor+=2;
        }
        if(n%sqrtn==0){
            if(sqrtn*sqrtn==n) divisor++;
            else divisor+=2;
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

