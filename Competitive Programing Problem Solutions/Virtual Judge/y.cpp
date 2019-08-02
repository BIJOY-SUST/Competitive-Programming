#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long N,i,j,c=0,a[100001],b[100001];
        cin>>N;
        for(i=0;i<N;i++){
            cin>>a[i];
        }
        for(i=0;i<100000;i++){
            b[i]=0;
        }
        for(j=0;j<N;j++){
            if(!b[a[j]]){
                c++;
                b[a[j]]=1;
            }
        }
        cout<<c<<endl;
    }

    return 0;
}
