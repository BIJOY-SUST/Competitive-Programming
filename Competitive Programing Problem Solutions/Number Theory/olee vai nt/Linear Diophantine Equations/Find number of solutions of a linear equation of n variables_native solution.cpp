#include<bits/stdc++.h>
using namespace std;
//int coefficient[5];
vector<int>v;
int count_sol(int start,int end,int rhs){
    if(rhs==0) return 1;
    int result=0;
    for(int i=start;i<=end;i++){
        if(v[i]<=rhs){
            result+=count_sol(i,end,rhs-v[i]);
        }
    }
    return result;
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int a,k=3,rhs;
        while(k--){
            cin>>a;
            v.push_back(a);
        }
        cin>>rhs;
        int n=v.size();
        cout<<count_sol(0,n-1,rhs);
    }
//    int n=sizeof(coefficient)/sizeof(coefficient[0]);
    return 0;
}
