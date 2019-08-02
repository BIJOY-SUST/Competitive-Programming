#include<bits/stdc++.h>
using namespace std;
list<int>v;
void printDivisors(int n){
    for (int i=1; i<=sqrt(n)+1; i++){
        if (n%i==0){
            if (n/i == i) v.push_back(i);
            else{
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
}
int main(){
    int t,h=0;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    printDivisors(n);
    v.sort();
    v.remove(1);
    v.unique();
    cout<<"Case "<<++h<<": "<<v.size()<<"\n";
    v.clear();
    }
    return 0;
}



