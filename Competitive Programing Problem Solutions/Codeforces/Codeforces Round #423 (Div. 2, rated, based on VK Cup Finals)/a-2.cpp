#include<bits/stdc++.h>
using namespace std;
int arr[2*100001];
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1&&a>=1){
            a-=1;
        }
        else if(arr[i]==1&&b>=1){
            b-=1;
            a+=1;
        }
        else if(arr[i]==2&&b>=1){
            b-=1;
        }
        else{
            ans +=arr[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
