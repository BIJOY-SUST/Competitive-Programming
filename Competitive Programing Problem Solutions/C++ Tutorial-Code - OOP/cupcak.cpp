#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
    long long T,N,d;
    cin>>T;
    while(T--){
        cin>>N;
        long long d=1000000000;
        long long y=sqrt(N);
        for(long long i=y;i>0;i--){
            if(N%i==0){
                long long m=abs(N/i-i);
                d=min(d,m);
                break;
            }
        }
        cout<<d<<endl;
    }
    return 0;
}
