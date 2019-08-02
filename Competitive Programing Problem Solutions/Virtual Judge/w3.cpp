#include<bits/stdc++.h>
#include<stddef.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string S;
        int s[1001]={},ss[1001]={};
        cin>>S;
        int k=S.length();
        for(int i=0;i<k/2;i++){
            s[S[i]-'a']++;
            ss[S[k-1-i]-'a']++;
        }
        int h=memcmp(s,ss,sizeof(s));
        if(h==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
