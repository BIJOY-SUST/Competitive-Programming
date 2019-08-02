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
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<i;j++){
                if(v[j]<=v[i]){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

