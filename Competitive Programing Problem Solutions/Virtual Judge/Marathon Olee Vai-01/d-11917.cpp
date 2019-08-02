#include<bits/stdc++.h>
using namespace std;
map<string,int>store;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n;
        cin>>n;
        for(int j=1;j<=n;j++){
            int k;
            string s;
            cin>>s>>k;
            store[s]=k;
        }
        int h;
        cin>>h;
        string s1;
        cin>>s1;
        int m=store[s1];
        if(m!=0&&m<=h) cout<<"Case "<<i<<": Yesss\n";
        else if(m!=0&&m<=h+5) cout<<"Case "<<i<<": Late\n";
        else cout<<"Case "<<i<<": Do your own homework!\n";
        store.clear();
    }
    return 0;
}
