#include<bits/stdc++.h>

using namespace std;

int main(){
    int T,N;
    cin>>T;
    while(T--){
        int m,c=0;
        cin>>N;
        int a[100001];
        int b[100001]={};
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        for(int i=0;i<N;i++){
            if(!b[a[i]]){
                c++;
                b[a[i]]=1;
            }
        }
        cout<<c<<endl;
    }

    return 0;
}
