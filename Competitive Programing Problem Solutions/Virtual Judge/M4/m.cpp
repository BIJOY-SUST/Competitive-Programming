#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int k;
    bool l = true;
    string s;
    cin>>s;
    for(long long int i=0;i<s.length();i=i+k){
        string sa = s.substr(i,i+1);
        string sb = s.substr(i,i+2);
        string sc = s.substr(i,i+3);
        cout<<i<<endl;
        if(sc=="144"){
            k=3;
        }
        else if(sb=="14"){
            k=2;
        }
        else if(sa=="1"){
            k=1;
        }
        else{
            l = false;
            break;
        }
    }
    if(l == true){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
