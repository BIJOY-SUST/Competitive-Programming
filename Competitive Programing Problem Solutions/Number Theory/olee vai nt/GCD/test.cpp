#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    vector<string>v;
    istringstream ss(s);
    string sss;
    while(ss>>sss){
        v.push_back(sss);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}
