#include<bits/stdc++.h>
using namespace std;
int x,n,ans=0;
void print(int i){
    if(i<n){
        if(i==0){
            ans+=1;
        }
        else{
            ans+=pow(x,i);
        }
        print(++i);
    }
}
int main(){
    cin>>x>>n;
    print(0);
    cout<<ans<<endl;
    return 0;
}

