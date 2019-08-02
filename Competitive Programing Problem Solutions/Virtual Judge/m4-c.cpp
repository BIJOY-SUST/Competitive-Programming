#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int T,N;
    cin>>T;
    while(T--){
        long long int i, c=0;
        cin>>N;
        for(i=1;i<=N;i++){
            if(N%i==0&&i%2==0){
                c++;
                cout<<i<<endl;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
