#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        int  ans=0,k;
        cin>>n;
        for(int i=0;i<n;i++){
                cin>>k;
                ans = __gcd(ans,k);
        }
        ans==1?cout<<n<<"\n":cout<<-1<<"\n";
    }
    return 0;
}
