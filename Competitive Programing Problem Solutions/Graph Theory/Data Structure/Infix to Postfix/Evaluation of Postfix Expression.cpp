///Following is algorithm for evaluation postfix expressions.
//1) Create a stack to store operands (or values).
//2) Scan the given expression and do following for every scanned element.
//…..a) If the element is a number, push it into the stack
//…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
//3) When the expression is ended, the number in the stack is the final answer
#include<bits/stdc++.h>
using namespace std;
bool isOperand(char ch){
    return ch>='0'&&ch<='9'?true:false;
}
int calculate(int x,char ch,int y){
    switch(ch){
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': return x/y;
        case '^': return pow(x,y);
    }
    return 0;
}
int postfix_Evaluation(string s){
    stack<int>st;
    char ch;
    int x,y;
    for(int i=0;i<s.length();i++){
        ch=s[i];
        if(isOperand(ch)) st.push(ch-'0');
        else{
            y=st.top();
            st.pop();
            x=st.top();
            st.pop();
            st.push(calculate(x,ch,y));
        }
    }
    return st.top();
}
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<postfix_Evaluation(s)<<'\n';
    }
    return 0;
}


























/////Following is algorithm for evaluation postfix expressions.
////1) Create a stack to store operands (or values).
////2) Scan the given expression and do following for every scanned element.
////…..a) If the element is a number, push it into the stack
////…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
////3) When the expression is ended, the number in the stack is the final answer
//#include<bits/stdc++.h>
//using namespace std;
//bool isOperand(char ch){
//    return ch>='0'&&ch<='9'?true:false;
//}
//int calculate(int x,char ch,int y){
//    switch(ch){
//        case '+': return x+y;
//        case '-': return x-y;
//        case '*': return x*y;
//        case '/': return x/y;
//        case '^': return pow(x,y);
//    }
//    return 0;
//}
//int postfix_Evaluation(string s){
//    vector<int>st;
//    char ch;
//    int x,y;
//    for(int i=0;i<s.length();i++){
//        ch=s[i];
//        if(isOperand(ch)) st.push_back(ch-'0');
//        else{
//            y=st.back();
//            st.pop_back();
//            x=st.back();
//            st.pop_back();
//            st.push_back(calculate(x,ch,y));
//        }
//    }
//    return st.back();
//}
//int main(){
////    ios_base::sync_with_stdio(false);
////    cin.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--){
//        string s;
//        cin>>s;
//        cout<<postfix_Evaluation(s)<<'\n';
//    }
//    return 0;
//}
