#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N,M,k;
    map<long long,long long>m;
    while(cin>>N>>M){
        if(N==0&&M==0){
            break;
        }
        long long sum=0;
        for(long long i=0;i<N;i++){
            cin>>k;
            m[k]=1;
        }
        for(long long i=0;i<M;i++){
            cin>>k;
            if(m[k]==1){
                sum++;
            }
        }
        m.clear();
        cout<<sum<<endl;

    }
    return 0;
}
