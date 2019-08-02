#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int> >v;
    int t;
    cin>>t;
    for(int h=1;h<=t;h++){
        int n;
        cin>>n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                v.push_back(make_pair(i,n/i));
            }
        }
        cout<<"Case #"<<h<<": "<<n<<" = "<<v[0].first<<" * "<<v[0].second<<" = "<<v[1].first<<" * "<<v[1].second<<'\n';
        v.clear();
    }
    return 0;
}
