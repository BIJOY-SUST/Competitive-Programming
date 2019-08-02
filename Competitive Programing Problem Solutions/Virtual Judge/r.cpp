#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int no=2;
        for(int i=0;i<s.length()-1;i++){
            //cout<<"A= "<<str[i+1]-str[i]<<" ";
            //cout<<"B= "<<((str[i+1]-str[i]+26)%26) + 1<<" ";
            no=no+((s[i+1]-s[i]+26)%26) + 1;
        }
        cout<<no<<endl;
        if(no<=s.length()*11){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}



