#include<bits/stdc++.h>
using namespace std;
int main(){
//    freopen("01.txt","r",stdin);
//    freopen("02.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1&&n!=0){
        list<int>L;
        for(int i=1;i<=n;i++){
            L.push_back(i);
        }
        if(L.size()!=1){
                cout<<"Discarded cards: "<<L.front();
            L.pop_front();
            while(L.size()>1){
                int k=L.front();
                L.pop_front();
                L.push_back(k);
                cout<<", "<<L.front();
                L.pop_front();
            }
            cout<<'\n';
            cout<<"Remaining card: "<<L.front()<<'\n';
        }
        else{
            cout<<"Discarded cards:\n";
            cout<<"Remaining card: "<<L.front()<<'\n';
        }
        L.clear();
    }
    return 0;
}

