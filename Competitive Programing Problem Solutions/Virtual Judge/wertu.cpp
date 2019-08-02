#include<bits/stdc++.h>
using namespace std;
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//for \ we must type double "\"

char func(char k){
    for(int i=0;i<47;i++){
        if(s[i] == k){
            return s[i-1];
        }
    }
    return k;
}
int main(){
    char ss[100001];
    while(gets(ss)){//cin>>ss;
    for(int i=0;i<strlen(ss);i++){
        ss[i] = func(ss[i]);
    }
    cout<<ss<<endl;
}
}
