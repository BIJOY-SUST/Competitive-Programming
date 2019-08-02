#include<bits/stdc++.h>
using namespace std;
string prove(string ss){
    stack<char>s;
    for(auto c : ss){
        switch(c){
            case '[':
            case '{':
            case '(':
                s.push(c);
                break;
            case ')':
                if(s.empty()||s.top() != '('){
                    return "NO";
                }
                s.pop();
                break;
            case '}':
                if(s.empty()||s.top()!='{'){
                   return "NO";
                }
                s.pop();
                break;
            case ']':
                if(s.empty()||s.top()!='['){
                    return "NO";
                }
                s.pop();
                break;
        }
    }
    return s.empty()? "YES":"NO";
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<prove(s)<<endl;
    }
    return 0;
}
