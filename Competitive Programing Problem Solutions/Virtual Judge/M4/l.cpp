#include<bits/stdc++.h>
#define max 1000000
using namespace std;
long long int a[max];
int main(){
   long long int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n-1]<<endl;
    return 0;
}
