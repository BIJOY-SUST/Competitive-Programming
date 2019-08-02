#include<bits/stdc++.h>
using namespace std;
char* fnc(char* s,int n){
    int i,p=0;
    int len = strlen(s);
    for(i=0;i<len-1;i++){
        if(s[i]!=s[i+1]){
            s[p++]=s[i];                                ///aaabccddd
        }
        if(s[i]==s[i+1]){
            i++;
        }
    }
    s[p++]=s[i];
    s[p]='\0';
    if(p!=n){
        fnc(s,p);
    }
    return s;
}
int main(){
    char s[101];
    cin>>s;
    string ss;
    ss = fnc(s,strlen(s));
    if(!ss.empty()){
        cout<<ss<<endl;
    }
    else{
        cout<<"Empty String"<<endl;
    }
    return 0;
}
