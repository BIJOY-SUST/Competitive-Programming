#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void printDivisors(int n){
    for (int i=1; i<=sqrt(n); i++){
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
    int n;
    cin>>n;
    printDivisors(n);
    sort(v.begin(),v.end());
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    return 0;
}
