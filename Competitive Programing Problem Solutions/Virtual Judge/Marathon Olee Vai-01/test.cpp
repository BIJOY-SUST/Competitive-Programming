#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node(){}
    node(int v){
        val=v;
    }
    bool operator <(const node& p)const{
        return val>p.val;
    }
};
int main(){
    priority_queue<node>q;
    node m;
    for(int i=0;i<10;i++){
        int k;
        cin>>k;
        m.val=k;
        q.push(m);
    }
    for(int i=0;i<10;i++){
        node h;
        h=q.top();
        q.pop();
        cout<<h.val<<endl;
    }
    return 0;
}
