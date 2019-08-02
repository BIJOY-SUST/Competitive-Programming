#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int k=0;
        string s;
        char ss[100001];
        cin>>s;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(i==0){
                ss[k++]=s[i];
            }
          else if(tolower(s[i])==tolower(s[i-1])){
                ss[k++]='#';
           }
           else{
                ss[k++]=s[i];
           }
        }
        ss[k]='\0';
        cout<<ss<<'\n';
        s.clear();
    }
    return 0;
}
