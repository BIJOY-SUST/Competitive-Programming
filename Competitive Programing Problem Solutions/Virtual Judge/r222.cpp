#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        char s[10001];
        cin>>s;
        int no=0;
        for(int i=0;i<strlen(s)-1;i++){
            no=no+((s[i+1]-s[i]+26)%26);
        }
        no=no+strlen(s)+1;
        cout<<no<<endl;
        if(no<=strlen(s)*11){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

