#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    char s[10000];
    cin>>s;
    int len = strlen(s);
    sort(s,s+len);
    int count =0;
    for(int i=0; i<len; i++){
        if(s[i] != s[i+1]){
            count++;
        }
    }
    if(count%2==0)
    {
        cout<<"CHAT WITH HER!"<<endl;
    }
    else
    {
        cout<<"IGNORE HIM!"<<endl;
    }

    return 0;
}
