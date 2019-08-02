#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=0;
    char s[100000],ss[100000];
    cin>>s;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        s[i] = tolower(s[i]);
    }
    //cout<<s<<endl;
    for(int j=0;j<len;j++){
        if(s[j]=='a'||s[j]=='o'||s[j]=='y'||s[j]=='e'||s[j]=='u'||s[j]=='i'){
            continue;
        }
        else{
            ss[k++] = '.';
            ss[k++] = s[j];
        }
    }
    ss[k]='\0';
    cout<<ss<<endl;
    return 0;
}


