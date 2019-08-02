#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int id,period,next;
    node(){}
    node(int _id,int _period,int _next):id(_id),period(_period),next(_next){}
    bool operator<(const node &p)const{
        return next==p.next?(id>p.id):(next>p.next);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<node>q;
    string s;
    while(cin>>s){
        if(s=="#") break;
        node obj;
        cin>>obj.id>>obj.period;
        obj.next=obj.period;
        q.push(obj);
    }
    int n;
    cin>>n;
    while(n--){
        node obj2;
        obj2 = q.top();q.pop();
        cout<<obj2.id<<'\n';
        obj2.next+=obj2.period;
        q.push(obj2);
    }
    return 0;
}
