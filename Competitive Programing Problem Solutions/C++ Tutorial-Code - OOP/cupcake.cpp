#include<bits/stdc++.h>
#include<math.h>
using namespace std;

long long rec(long long N){
    long long d=100000000;
    for(long long i=1;i<=N;i++){
        for(long long j=1;j<=N;j++){
            if((i*j)==N&&d>abs(i-j)){
                d=abs(i-j);
            }
        }
    }
    return d;
}
int main(){
    long long T,N,d;
    cin>>T;
    while(T--){
        cin>>N;
        d=rec(y);
        cout<<d<<endl;
    }
    return 0;
}

