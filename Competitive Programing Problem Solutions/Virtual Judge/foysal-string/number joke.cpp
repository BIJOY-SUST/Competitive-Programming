#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int ans = (int)pow(3,a);
    if(a==1){
        ans = pow(3,a)+1;
    }

    cout<<ans<<endl;
    return 0;
}
