#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=0;
    char s[100000],ss[100000];
    cin>>s;
    int len = strlen(s);
    //s[0]=toupper(s[0]);
    bool flag = true;
    //ss[k++] = toupper(s[0]);
    for(int i=0;i<len;i++){
        if(i==0&&isupper(s[i])){
            ss[k++]=tolower(s[i]);
        }
        else if(i==0&&islower(s[i])){
            ss[k++]=toupper(s[i]);
        }
        else if(isupper(s[i])){
            ss[k++]=tolower(s[i]);
        }
        else{
            flag = false;
            break;
        }
    }
    ss[k]='\0';
    if(flag==true)cout<<ss<<endl;
    else cout<<s<<endl;
    return 0;
}
