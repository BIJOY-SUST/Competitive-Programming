#include<bits/stdc++.h>
using namespace std;
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        string s;
        long long int d,remin=0;
        cin>>s>>d;
        if(d<0) d=d*(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]!='-'){
                remin=((remin*10)+(s[i]-'0'))%d;
            }
        }
        remin==0?cout<<"Case "<<h<<": divisible"<<'\n':cout<<"Case "<<h<<": not divisible"<<'\n';
    }
    return 0;
}
