#include<bits/stdc++.h>
 using namespace std;
 string call(string s){
    stack<char>st;
    for(auto c:s){
        switch(c){
            case '[':
            case '(':
                st.push(c);
                break;
            case ')':
                if(st.empty()||st.top()!='('){
                    return "No";
                }
                st.pop();
                break;
            case ']':
                if(st.empty()||st.top()!='['){
                    return "No";
                }
                st.pop();
                break;
        }
    }
    return st.empty()?"Yes":"No";
 }
 int main(){
    int n;
    cin>>n;
    getchar();
    while(n--){
        string s;
        getline(cin,s);
        string ss = call(s);
        cout<<ss<<endl;
    }
    return 0;
 }
