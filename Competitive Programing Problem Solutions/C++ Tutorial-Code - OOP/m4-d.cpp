#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
  return (n == 1 || n == 0) ? 1 : factorial(n - 1)*n;
}
int main(){
    int T,N,M;
    cin>>T;
    while(T--){
        int ans;
        cin>>N>>M;
        ans = factorial(N+M-1)/(factorial(N)*factorial(M-1));
        cout<<ans<<endl;
    }
    return 0;
}
