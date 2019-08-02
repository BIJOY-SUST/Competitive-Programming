#include<bits/stdc++.h>
using namespace std;
int main(){
    long long T,N;
    cin>>T;
    while(T--){
        cin>>N;
        long long ans = ((int) (pow(2,N))-1)%100000;//ketab uddin 128 page..............
        cout<<ans<<endl;
    }
    return 0;
}
