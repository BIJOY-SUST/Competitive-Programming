#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int main(){
    string s;
    cin >> s;
    long long  len = s.length();
    long long count =0;
    for(long long  i=0; i<len; i++){
        if(s[i]=='7'||s[i]=='4'){
            count++;
        }
    }
    if(count ==4||count==7){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}
