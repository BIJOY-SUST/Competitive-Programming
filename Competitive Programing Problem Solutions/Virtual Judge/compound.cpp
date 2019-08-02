#include<bits/stdc++.h>

using namespace std;
vector<string> v;
map<string,int> v_test;
int main() {
    string s,ss,sss;
    while(cin>>s){
        v.push_back(s);
        v_test[s] = 1;
    }
    for(int i=0;i<v.size();i++) {
        int len = v[i].length();
        for(int j=1;j<len;j++) {
            ss = v[i].substr(0, j);
            sss = v[i].substr(j, len);
            if (v_test[ss] &&v_test[sss]) {
                cout<<v[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
