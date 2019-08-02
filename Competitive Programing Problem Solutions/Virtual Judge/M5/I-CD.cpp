#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N,M,k;
    set<long long>s;
    while(cin>>N>>M){
        if(N==0&&M==0){
            break;
        }

        for(long long i=0;i<N+M;i++){
            cin>>k;
            s.insert(k);
        }
        long long ans = s.size();
        ans = N+M-ans;
        s.clear();
        cout<<ans<<endl;

    }
    return 0;
}
