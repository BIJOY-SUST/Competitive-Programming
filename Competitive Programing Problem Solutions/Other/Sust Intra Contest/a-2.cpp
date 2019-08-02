#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    map<int,int>m;
    set<int>s;
    int x=0,y=0;
    cin>>n;
    for(int i=0;i<n;i++){
        m[i]=0;
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        s.insert(k);
        m[k]++;
        y=max(y,m[k]);

    }
    cout<<y<<" "<<s.size()<<"\n";
    return 0;
}

