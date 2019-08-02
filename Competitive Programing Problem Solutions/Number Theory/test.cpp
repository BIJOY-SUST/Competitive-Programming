#include<bits/stdc++.h>
using namespace std;
list<int>v;
void printDivisors(long long int n){
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,h=0;
    cin>>t;
    while(t--){
    long long int n;
    cin>>n;
    printDivisors(n);
    v.sort();
    v.unique();
    cout<<"Case "<<++h<<": "<<v.size()-1<<"\n";
    v.clear();
    }
    return 0;
}



