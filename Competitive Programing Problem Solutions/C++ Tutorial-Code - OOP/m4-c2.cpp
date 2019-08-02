#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int T,N;
    cin>>T;
    while(T--){
        long long int i, c=0;
        cin>>N;
        for(i=1;i<=sqrt(N);i++){
            if(N%i==0){
                if(i%2==0){
                    c++;
                }
                if((N/i)%2==0&&i!=N/i){
                    c++;
                }
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
