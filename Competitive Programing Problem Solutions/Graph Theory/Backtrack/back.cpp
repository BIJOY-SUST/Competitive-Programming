#include<bits/stdc++.h>
using namespace std;
string s;
bool flag[3];
vector<char>v;
void rec(int len){
    //cout<<s[len]<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i];
    cout<<endl;
    if(len==s.length()){
//        //for(int i=0;i<v.size();i++) cout<<v[i];
//        cout<<endl;
        return;
    }
    for(int i=len;i<s.size();i++){
        if(flag[s[i]]==0){
            flag[s[i]]=1;
            v.push_back(s[i]);
            rec(i+1);
            flag[s[i]]=0;
            v.pop_back();
        }
    }
}
int main(){
    cin>>s;
    cout<<"The combination:\n";
    rec(0);
    return 0;
}
