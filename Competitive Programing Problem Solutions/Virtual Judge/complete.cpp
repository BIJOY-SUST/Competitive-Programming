#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    int len,count1=0;
    char s[500001];
    cin>>s;
    len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='A' && s[i]<='Z'){
            count1++;
        }
        else if(s[i]=='?'){
            count1++;
        }
    }
    char j;
    if(count1==len){
        for(int i=0,j='A';i<len;i++){
            if(s[i]>'A'&&s[i]<='Z'){
                s[i] = j;
                j++;
            }
            else if(s[i]=='?'){
                s[i]=j;
                j++;
            }
        }
        cout<<s<<endl;
    }
    else{
        cout<<-1<<endl;
    }


    return 0;

}
