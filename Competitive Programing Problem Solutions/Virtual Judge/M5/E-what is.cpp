#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i=0;
    vector<int>v;
    while(cin>>n&&n!=EOF){
        v.push_back(n);
        sort(v.begin(),v.end());
        if(i%2==0){
            int ans=v[i/2];
            cout<<ans<<endl;
        }
        if(i%2!=0){
            int ans=(v[(i-1)/2]+v[(i+1)/2])/2;
            cout<<ans<<endl;
        }
        i++;
    }

    //for(int i=0;i<v.size();i++){
        //cout<<v[i]<<" ";
    //}
    //cout<<endl;
    //for(int i=0;i<v.size();i++){
//
    //}
    return 0;
}
