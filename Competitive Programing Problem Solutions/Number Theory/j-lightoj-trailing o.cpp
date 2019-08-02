#include<bits/stdc++.h>
using namespace std;
int cal(int N,int x){
    int counter=0;
    while(N>0){
        counter+=N/x;
        N=N/x;
    }
    return counter;
}
int cal_p(int N,int x){
    int counter=0;
    while(N>0&&N%x==0){
        N=N/x;
        counter++;
    }
    return counter;
}
int main(){
    ///ios_base::sync_with_stdio(false);
    ///cin.tie(NULL);
    int t;
    cin>>t;
    for(int h=1;h<=t;h++){
        int n,r,p,q;
        cin>>n>>r>>p>>q;
        int i = cal(n, 2);
        int j = cal(n, 5);
        int k = cal(r, 2);
        int l = cal(r, 5);
        int m = cal(n-r, 2);
        int mm = cal(n-r, 5);
        int px = q*cal(p, 2);
        int py = q*cal(p, 5);
        int ans = min(i-k-m+px,j-l-mm+py);
        cout<<"Case "<<h<<": "<<ans<<"\n";
    }
    return 0;
}
