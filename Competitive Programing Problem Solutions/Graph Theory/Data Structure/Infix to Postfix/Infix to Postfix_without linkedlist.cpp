///Infix to Postfix-Algorithm:
///1. Scan the infix expression from left to right.
///2. If the scanned character is an operand, output it.
///3. Else,
///…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty), push it.
///…..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator is less-equal to the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
///4. If the scanned character is an ‘(‘, push it to the stack.
///5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
///6. Repeat steps 2-6 until infix expression is scanned.
///7. Pop and output from the stack until it is not empty.
#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='+'||ch=='-') return 1;
    else return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        string ans="";
        stack<char>st;
        for(int i=0;i<s.length();i++){
            //if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
            if(s[i]>='0'&&s[i]<='9'){
                ans+=s[i];
            }
            else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty()&&st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty()&&(precedence(st.top())>=precedence(s[i]))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        //printf("%s\n",ans.c_str());
        cout<<ans<<endl;
    }
    return 0;
}
