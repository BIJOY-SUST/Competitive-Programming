#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        vector<pair<int,int> >v;
        for(int j=0;j<n;j++){
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());
        int ans=(int)sqrt(pow(abs(v[n-1].first-v[0].first),2)+pow(abs(v[n-1].second-v[0].second),2));
        cout<<ans<<endl;
    }
    return 0;
}



