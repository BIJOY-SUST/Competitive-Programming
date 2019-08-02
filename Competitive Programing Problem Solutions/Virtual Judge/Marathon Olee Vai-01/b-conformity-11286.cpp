#include<bits/stdc++.h>
using namespace std;
map<vector<int>,int>mapping;
int main(){
    int n,k;
    while(cin>>n){
        if(n==0) break;
        for(int i=1;i<=n;i++){
            vector<int>v;
            for(int i=1;i<=5;i++){
                cin>>k;
                v.push_back(k);
            }
            sort(v.begin(),v.end());
            mapping[v]++;
            //cout<<mapping[v]<<endl;
        }
        int m=0;
        for(__typeof(mapping.begin()) it=mapping.begin();it!=mapping.end();it++){
            m=max(m,it->second);
        }
        int c=0;
        for(__typeof(mapping.begin()) it=mapping.begin();it!=mapping.end();it++){
            if(m==it->second) c++;
        }
        cout<<c*m<<"\n";
        mapping.clear();
    }
    return 0;
}
