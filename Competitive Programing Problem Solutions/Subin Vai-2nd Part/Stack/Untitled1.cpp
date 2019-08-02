#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
stack<int>s;
int main(){

    int n,m;
    while(cin>>n){
        if(n==1){
            cin>>m;
            s.push(m);
        }
        else if(n==2){
            if(s.empty()){
                cout<<"UnderFlow"<<endl;
            }
            else{
                cout<<s.top()<<endl;
                s.pop();

            }
        }
        else{
            cout<<s.size()<<endl;
        }
    }
    return 0;
}
