#include<bits/stdc++.h>

using namespace std;
int main(){
    int T;
    cin>>T;
    getchar();
    while(T--){
        long long n;
        int ara[100000];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ara[i];
        }
        long long  d1 = -99999999,d2 = -999999999;
        for(int j=0;j<n-1;j++){
            if(ara[j]>d1){
                d1 = ara[j];
            }
            if(d1-ara[j+1]>d2){
                d2 = d1-ara[j+1];
            }
        }
        cout<<d2<<endl;
    }
    return 0;
}
