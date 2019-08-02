#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n){
    if(n<=2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    char s[25];
    while(scanf("%s",s)==1){
        int n=0,l=strlen(s);
        for(int i=0;i<l;i++){
            if(s[i]>='a'&&s[i]<='z'){
                n+=s[i]-'a'+1;
            }
            if(s[i]>='A'&&s[i]<='Z'){
                n+=s[i]-'A'+27;
            }
        }
        puts(is_prime(n)? "It is a prime word." : "It is not a prime word.");
    }
    return 0;
}

