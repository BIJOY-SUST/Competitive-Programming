#include<bits/stdc++.h>
using namespace std;
vector<string>v;
string s,ss;
int main(){
    while(cin>>s){
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            ss = v[i]+v[j];
            for(int k=0;k<v.size();k++){
                if(ss == v[k]){
                    cout<<v[k]<<endl;
                    v[k] = "0";
                    break;
                }
            }
        }
    }
    return 0;
}
