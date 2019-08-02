#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    set<string>v;
    while(cin>>s){
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string ss;
        bool let=false;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                ss+=s[i];
                let=true;
            }
            else if(let){
                v.insert(ss);
                ss.clear();
                let=false;
            }
        }
        if(!ss.empty()) v.insert(ss);
        s.clear();
        ss.clear();
    }
    for(__typeof(v.begin()) it=v.begin();it!=v.end();it++){
        cout<<*it<<'\n';
    }
    return 0;
}

