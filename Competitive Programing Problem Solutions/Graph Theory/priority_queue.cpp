#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int>q;
    q.push(10230);
    q.push(1021);
    q.push(102322);

    while(!q.empty()){
        cout<<q.top()<<endl;
        q.pop();
    }
    return 0;
}
