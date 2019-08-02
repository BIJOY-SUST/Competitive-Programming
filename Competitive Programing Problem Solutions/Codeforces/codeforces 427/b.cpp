#include<bits/stdc++.h>
using namespace std;
int main(){
    long long i,c=0,k,h=0;
    string n;
    cin>>k>>n;
    for(int i=0;i<n.length();i++){
        c+=n[i]-'0';
    }
    if(c>=k) cout<<"0"<<'\n';
    else{
        sort(n.begin(),n.end());
        for(int i=0;i<n.length();i++){
            c-=n[i]-'0';
            c+=9;
            h++;
            if(c>=k) break;
        }
        cout<<h<<'\n';
    }
    return 0;
}
