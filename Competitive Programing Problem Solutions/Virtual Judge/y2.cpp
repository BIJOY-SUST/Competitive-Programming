#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long int n,c,i,a[100000];
    cin>>t;
    while(t--){
        cin>>n;
        c=0;
        long int flag[n];
        for(i=0;i<=n;i++){
                flag[i]=0;
        }
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            if(flag[a[i]]==0){
                c=c+1;
                flag[a[i]]=1;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
