#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,h;
    bool flag=true;
    cin>>n>>k;
    int a[1001];
    int ans=0,rin=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
    	a[i]+=rin;
        if(a[i]>=8){
            ans+=8;
            rin=a[i]-8;
            if(ans>=k){
                h=i+1;
                flag=false;
                break;
            }
        }
        else{
            ans+=a[i];
            rin=0;
            if(ans>=k){
                h=i+1;
                flag=false;
                break;
            }
        }
    }
    if(flag==false){
        cout<<h<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }
    return 0;
}
