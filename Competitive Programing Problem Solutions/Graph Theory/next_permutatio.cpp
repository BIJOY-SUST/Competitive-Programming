#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<string>v;
    for(int i=0;i<3;i++){
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    do{
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    }while(next_permutation(v.begin(),v.end()));

    cout<<"After Loop:"<<endl;
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    return 0;
}
