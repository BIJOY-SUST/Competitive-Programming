#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,x,y;
    vector<int>a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long k = a[n-1]-a[0], l = b[n-1]-b[0];
    if(k>l){
        cout<<k*k<<endl;
    }
    else{
        cout<<l*l<<endl;
    }
    return 0;
}

