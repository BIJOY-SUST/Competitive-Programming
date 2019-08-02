#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,s=0;
        int arr[100005];
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",arr[i]);
        }
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++){
            s+=arr[i];
        }
        int m=n-1;
        x:
        if(m<=1){
            cout<<"IMPOSSIBLE"<<"\n";
        }
        else if(s>arr[m]){
            cout<<m+1<<"\n";
        }
        else{

            m--;
            s=s-arr[m];
            goto x;
        }
    }
    return 0;
}

