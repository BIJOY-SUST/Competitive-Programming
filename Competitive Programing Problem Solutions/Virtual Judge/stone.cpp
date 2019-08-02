#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
    string s ;
    int count= 0;
    int n;
    cin>>n>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])
            count++;
    }
    cout<<count<<endl;
    return 0;
}
