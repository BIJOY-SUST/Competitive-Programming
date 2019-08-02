#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int sum=0, N;
        cin>>N;
        vector<int>v;
        for(int i=0;i<N;i++){
            int k;
            cin>>k;
            v.push_back(k);
            vector<int>::iterator low;
            low = lower_bound(v.begin(),v.end(),k);
            cout<<(low - v.begin())<<endl;
            sum+=(low - v.begin());
        }
        cout<<sum<<endl;
    }
    return 0;
}
