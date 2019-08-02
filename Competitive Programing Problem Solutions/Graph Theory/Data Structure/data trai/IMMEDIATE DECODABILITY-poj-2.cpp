#include<bits/stdc++.h>
using namespace std;
int main(){
    int k=0,n;
    string s;
    vector<string>v;
    while(1){
        while(1){
            getline(cin,s);
            if(s.empty()) return 0;
            if(s=="9") break;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        bool flag = true;
        for(int i=0;i<v.size()-1;i++){
            //for(int j=i;j<n;j++){
                if(v[i].size()<=v[i+1].size()){
                    string ss=v[i+1].substr(0,v[i].size());
                    if(ss==v[i]){
                        flag=false;
                        break;
                    }
                }
        }

        flag==true?cout<<"Set "<<++k<<" is immediately decodable"<<endl:cout<<"Set "<<++k<<" is not immediately decodable"<<endl;
        v.clear();
        //if(flag) cout<<"NO"<<endl;
        //else cout<<"YES"<<endl;

    }
    return 0;
}
