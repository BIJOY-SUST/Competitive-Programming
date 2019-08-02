#include<bits/stdc++.h>
#define max 1000000
using namespace std;
long long int a[max];
int main(){
   long long int n,c,ans = 0;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]&&(a[i]-a[i+1]-c)>ans){
            ans =(a[i]-a[i+1]-c);
        }
    }
    cout<<ans<<endl;
    return 0;
}

