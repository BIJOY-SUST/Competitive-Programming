#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,x,y;
    vector<int>v;
    cin>>x>>y;
    v.push_back(y);
    while(y>x){
        if(y==x){
            break;
        }
        if(y%2==0){
            y/=2;
            v.push_back(y);

        }
        else if(y%10==1){
            y/=10;
            v.push_back(y);
        }
        else{
            break;
        }
    }
    if(y!=x){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<v.size()<<endl;
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
    }
    return 0;
}


