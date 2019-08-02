#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int d,h,ans=1000001;
        for(int i=1;i<n-1;i++){
            h=0;
            for(int j=0;j<n;j++){
                if(i==j){
                    d=a[j+1]-a[j-1];
                }
                else if(j+1==i){
                    d=a[j+2]-a[j];
                }
                else{
                    d=a[j+1]-a[j];
                }
                h=max(h,d);
            }
            ans=min(ans,h);
        }
        cout<<ans<<endl;
    }
    return 0;
}

