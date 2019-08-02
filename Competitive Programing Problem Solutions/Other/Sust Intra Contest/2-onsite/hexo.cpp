#include<bits/stdc++.h>
using namespace std;
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t,n,c=0,k;
    int arr[100001];
    map<int,int>m;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>arr[j];
            m[arr[j]]++;
            if(arr[j]==0){
                c++;
            }
        }
        for(int h=0;h<n;h++){
            if(arr[h]!=0&&m[arr[h]]>c){
                k=arr[h];
                c=m[arr[h]];
                cout<<"man"<<endl;
            }
        }
        cout<<"Case "<<i<<":"<<" "<<k+c<<"\n";
    }
    return 0;
}
