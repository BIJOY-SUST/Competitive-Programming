#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    string s;
    cin>>T;
    while(T--){
        int c=0;
        cin>>s;
        int len = s.length();
        for(int i=0;i<len-1;i++){
            if(s[i+1]==s[i]){
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}

