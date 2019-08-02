#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[100];
    while(gets(s)){
        int f = 0;
        int len = strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]>='A'&&s[i]<='Z'){
                f += s[i] - 'A'+27;
            }
            if(s[i]>='a'&&s[i]<='z'){
                f += s[i] - 'a'+1;
            }
        }
        //cout<<f<<endl;
        bool flag = true;
        for(int i=2;i<=sqrt(f);i++){
            if(f%i==0){
                flag = false;
                break;
            }
        }
        if(flag==true){
            cout<<"It is a prime word."<<endl;
        }
        else{
            cout<<"It is not a prime word."<<endl;
        }
    }
    return 0;
}
