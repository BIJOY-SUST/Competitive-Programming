#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    vector<int>a,b;
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>m;
        a.push_back(m);
        b.push_back(m);
    }
    sort(a.begin(),a.end());
    /*for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }*/
    int c = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            c++;
        }
        if(c>2){
            break;
        }
    }
    if(c<=2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
