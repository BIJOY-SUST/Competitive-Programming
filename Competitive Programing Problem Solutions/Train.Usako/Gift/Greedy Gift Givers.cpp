/*
ID: bsbijoy1
LANG: C++
TASK: gift1
*/
#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);

    int n;
    cin>>n;
    vector<string>names;
    map<string,long long>value;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        names.push_back(s);
        value[s] = 0;
    }

    for(int j=0;j<n;j++){
        long long x,y;
        string ss;
        cin>>ss;
        cin>>x>>y;
        if(y==0){
            continue;
        }
        value[ss] = value[ss]-x+x%y;
        for(int i=0;i<y;i++){
            cin>>ss;
            value[ss] = value[ss] + x/y;
        }
    }
    for(int i=0;i<names.size();i++){
        cout<<names[i]<<" "<<value[names[i]]<<endl;
    }
    return 0;
}
