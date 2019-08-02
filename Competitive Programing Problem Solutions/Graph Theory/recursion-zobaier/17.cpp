#include<bits/stdc++.h>
using namespace std;
bool isvalid(char c){
    return (isalpha(c)||isdigit(c));
}
bool ispalin(int x,int y, string s){
    if(x>y) return true;
    if(!isvalid(s[x])) return ispalin(x+1,y,s);
    if(!isvalid(s[y])) return ispalin(x,y-1,s);
    if(s[x]==s[y]) return ispalin(x+1,y-1,s);
    return false;
}
int main(){
    string s;
    getline(cin,s);
    int l=s.length();
    ispalin(0,l-1,s)? cout<<"Palindrome"<<endl:cout<<"Not Palindrome"<<endl;

    return 0;
}
