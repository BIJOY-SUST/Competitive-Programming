#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        int g=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                g+=__gcd(i,j);
            }
        }
        cout<<g<<'\n';
    }
    return 0;
}
