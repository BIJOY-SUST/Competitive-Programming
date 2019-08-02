#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>

using namespace std;
int a[10001];
int main(){
    int n,s;
    cin>>n>>s;

    for(int i=1;i<=n;i++){
        int f,t;
        cin>>f>>t;
        a[f] =max(t,a[f]);
    }
    int ans = 0;
    for(int i=s;i>=0;i--){
        ans = max(ans,a[i]);
        ans++;
    }

    cout<<ans-1<<endl;

    return 0;
}
