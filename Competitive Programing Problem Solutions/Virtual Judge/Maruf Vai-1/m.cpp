#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=0;
    char s[100000],ss[100000];
    cin>>s;
    cin>>ss;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        s[i] = tolower(s[i]);
    }
    for(int i=0;i<len;i++){
        ss[i] = tolower(ss[i]);
    }
    if(strcmp(s,ss)<0){
        cout<<"-1"<<endl;
    }
    else if(strcmp(s,ss)>0){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    return 0;
}

