#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string t;
    int c=1;
    getline(cin,s);
    getline(cin,t);
    int lent=t.length();
    for(int i=0,j=0;i<lent;i++){
        if(t[i]==s[j]){
            c++;
            j++;
        }
    }
    cout<<c<<"\n";
    return 0;
}
