#include<bits/stdc++.h>

using namespace std;
queue<int>b;
 int main(){

    int k,l;
    while(cin>>k){
        switch(k){
          case 1:
            cin>>l;
            b.push(l);
            cout<<"Queue size = "<<b.size()<<endl;
            break;
          case 2:
              cout<<"Delete = "<<b.front()<<endl;
            b.pop();
                cout<<"Now front= "<<b.front()<<endl;
                //cout<<"Delete = "<<b.back()<<endl;
                cout<<"Queue size = "<<b.size()<<endl;
            break;
          default:
            cout<<"Queue size = "<<b.size()<<endl;
        }
    }

    return 0;
 }
