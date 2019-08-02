#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int g,l;
        cin>>g>>l;
        int a=g;
        int b=l;
        if(l%g!=0) cout<<"-1\n";
        else{
            cout<<a<<" "<<b<<'\n';
        }
    }
    return 0;
}
