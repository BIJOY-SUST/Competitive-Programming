#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    string s3="";
    string s4="";
    int c=0;
    bool flag=true;
    if(s1.length()!=s2.length()){
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<s1.length();i++){
        if(s1.at(i)!=s2.at(i)){
            c++;
            s3+=s1.at(i);
            s4+=s2.at(i);
        }
    }
    if(s3.length()==2){
        if(s3.at(0)==s4.at(1)&&s3.at(1)==s4.at(0)){
            flag=false;
        }
    }
    if(!flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
