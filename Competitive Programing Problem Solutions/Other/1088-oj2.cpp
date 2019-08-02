#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    long long int n,q,T;
    cin>>T;
    for(int k=1;k<=T;k++){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Case "<<k<<":"<<endl;
    for(long long int i=0;i<q;i++){
        long long int x,y,c=0;
        cin>>x>>y;
        vector<int>v(a,a+n);
        sort(v.begin(),v.end());
        vector<int>::iterator low,up;
        low=lower_bound(v.begin(),v.end(),x);
        up= upper_bound(v.begin(),v.end(),y);
        cout<<up-low<<endl;
    }
    }
    return 0;
}

