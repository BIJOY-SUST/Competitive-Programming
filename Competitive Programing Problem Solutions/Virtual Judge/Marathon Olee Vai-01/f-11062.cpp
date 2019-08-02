#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    string s;
    string ss;
    set<string>v;
    while(1){
        x:
        cin>>s;
        if(!s.length()) break;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        //cout<<s<<endl;
        bool let=false;
        for(int i=0;i<s.length();i++){
            if(islower(s[i])){
                //cout<<s[i]<<endl;
                ss+=s[i];
                let=true;
            }

            else if(s[i]=='-'&&i+1>=s.length()){
                goto x;
            }
            else if(s[i]=='-'&&i+1<=s.length()){
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
