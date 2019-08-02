#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    int nn=0,nm=0,mm=0;
    cin>>n>>m;
    for(int i=1;i<=6;i++){
        if(abs(n-i)<abs(m-i)) nn++;
        else if(abs(n-i)>abs(m-i)) mm++;
        else
            nm++;
    }
    cout<<nn<<" "<<nm<<" "<<mm<<"\n";
    return 0;
}
