#include<bits/stdc++.h>
using namespace std;
//string symbol={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int baseToDecimal(string s,int base){
    int ans=0,c=1;
    for(int i=s.size()-1;i>=0;i--){
        if(isalpha(s[i])) ans+=(s[i]-'0'-7)*c;
        else ans+=(s[i]-'0')*c;
        c*=base;
    }
    return ans;
}
//string decimalToBase(int x,int base){
//    string ans="";
//    while(x){
//        int r=x%base;
//        ans=ans+symbol[r];
//        x/=base;
//    }
//    if(ans=="") ans=symbol[0];
//    reverse(ans.begin(),ans.end());
//    return ans;
//}
int main(){
    string s;
    int base;
    cin>>s>>base;
    cout<<baseToDecimal(s,base)<<'\n';
//    int n;
//    cin>>n>>base;
//    cout<<decimalToBase(n,base)<<'\n';
    return 0;
}
