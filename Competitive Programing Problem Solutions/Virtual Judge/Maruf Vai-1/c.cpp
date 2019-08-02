#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    char s[100001],ss[100001];
    cin>>T;
    while(T--){
    cin>>s;
    int len = strlen(s);
    //for(int i = len-1,j=0;i>=0;i--,j++){
       // ss[j]=s[i];
   // }
    strcpy(ss,s);
    reverse(ss,ss+len);
    ///cout<<s<<" "<<ss<<endl;
    int i;
    for(i=0;i<len-1;i++){
        if(abs(s[i+1]-s[i])==abs(ss[i+1]-ss[i])){
            continue;
        }
        else{
            break;
        }
    }
    if(i==len-1){
        cout<<"Funny"<<endl;
    }
    else{
        cout<<"Not Funny"<<endl;
    }
    }
    return 0;
}
