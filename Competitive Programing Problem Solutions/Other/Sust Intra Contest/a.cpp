#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        s.insert(k);

    }
    int a=n-s.size()+1;
    int b=n-a+1;
    cout<<a<<" "<<b<<"\n";
    return 0;
}
