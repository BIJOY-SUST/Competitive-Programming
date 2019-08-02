#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n;
    string s;
    vector<string>v;
    cin>>T;
    while(T--){
        cin>>n;

        for(int i=0;i<n;i++){
            //getline(cin,s);
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        bool flag = true;
        for(int i=0;i<n-1;i++){
            //for(int j=i;j<n;j++){
                if(v[i].size()<=v[i+1].size()){
                    string ss=v[i+1].substr(0,v[i].size());
                    if(ss==v[i]){
                        flag=false;
                        break;
                    }
                }
        }

        flag==true?cout<<"YES"<<endl:cout<<"NO"<<endl;
        v.clear();
        //if(flag) cout<<"NO"<<endl;
        //else cout<<"YES"<<endl;

    }
    return 0;
}

