#include<bits/stdc++.h>

using namespace std;
int main(){
    int t,a;
    int count = 0;
    cin>>t;
    while(t--){
        cin>>a;

        if(360%(180-a)==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

