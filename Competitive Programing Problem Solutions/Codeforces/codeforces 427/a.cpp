#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int ans1,ans2;
    ans1=s*v1+2*t1;
    ans2=s*v2+2*t2;
    if(ans1<ans2) cout<<"First\n";
    else if(ans1>ans2) cout<<"Second\n";
    else cout<<"Friendship\n";
    return 0;
}
