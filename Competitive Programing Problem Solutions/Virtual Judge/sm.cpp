#include<bits/stdc++.h>

using namespace std;
int main() {
    long long int T,n,s;
    cin>>T;
    while(T--){
        cin>>n;
        s=0;
        n = n%1000000007;
        s = (n*n)%1000000007;
        cout<<s<<endl;
    }
    return 0;
}
