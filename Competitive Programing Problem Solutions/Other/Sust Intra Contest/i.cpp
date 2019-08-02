#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string t;
    getline(cin,s);
    getline(cin,t);
    reverse(t.begin(),t.end());
    s==t?cout<<"YES"<<"\n":cout<<"NO"<<"\n";
    return 0;
}
