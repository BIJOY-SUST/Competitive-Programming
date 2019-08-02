#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

int main(){
    int count = 0;
    string s;
    cin>>s;
    int r_cons = atoi(s.c_str());
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='4' || s[i]=='7'){
            count++;
        }
    }
    if(count==len){
        cout<<"YES"<<endl;
    }
    else if(r_cons%47==0){
        cout<<"YES"<<endl;
    }
    else if(r_cons%4==0||r_cons%7==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
