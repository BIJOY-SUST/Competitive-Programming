#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K,A[10000];
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        cin>>K;
        int m = A[K-1];
        sort(A,A+N);
        for(int j=0;j<N;j++){
            if(m==A[j]){
                cout<<j+1<<endl;
            }
        }
    }

    return 0;
}
