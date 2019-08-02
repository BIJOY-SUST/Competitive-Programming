#include<bits/stdc++.h>
using namespace std;
int main(){
    //char s[100];
    string s;
    //while(gets(s)){
    while(getline(cin,s)){
        stringstream ss(s);
        int num;
        vector<int>v;
        while(ss>>num){
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
