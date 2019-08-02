#include<bits/stdc++.h>
using namespace std;
bool check(long long int mid,long long int n){
    long long int c=0,i=5;
    while(i<=mid){
        c+=mid/i;
        i*=5;
    }
    return (c==n);
}
long long int findnum(long long int n){
    if(n==1) return 5;
    long long int low = 0;
    long long int high = 5*n;
    while(low<high){
        long long int mid = (low+high)>>1;
        if(check(mid,n)) high = mid;
        else low=mid+1;
    }
    return low;
}
int main(){
    ///ios_base::sync_with_stdio(false);
    ///cin.tie(NULL);
    long long int t,n;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        ///findnum(n);
        cout<<findnum(n)<<"\n";
    }
    return 0;
}
