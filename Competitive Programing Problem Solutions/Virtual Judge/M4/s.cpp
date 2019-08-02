#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i;
    for(i=0;i<n-1;i++){
        cout<<a[i]+a[i+1]<<" ";
    }
    cout<<a[i]<<endl;
    return 0;
}

