#include<bits/stdc++.h>
using namespace std;
int cal(int N,int x){
    int counter=0;
    while(x<=N){
        counter+=N/x;
        x*=2;

    }
    return counter;
}
int main(){
    ///ios_base::sync_with_stdio(false);
    ///cin.tie(NULL);
    int t;
    cin>>t;
    for(int h=1;h<=t;h++){
        int n;
        cin>>n;
        int ans = cal(n, 2);
//        int ans = min(i-k-m+px,j-l-mm+py);
        cout<<"Case "<<h<<": "<<ans/4<<"\n";
    }
    return 0;
}

