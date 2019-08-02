#include<bits/stdc++.h>
using namespace std;
int check(long long int mid){
    long long int c=0,i=5;
    while(i<=mid){
        c+=mid/i;
        i*=5;
    }
    return c;
}
long long int findnum(long long int n){
    if(n==1) return 5;
    long long int low = 0,high = 5*n,ans=0,temp;
    while(low<=high){
        long long int mid = (low+high)/2;
        temp = check(mid);
        if(temp<n) low=mid+1;
        else if(temp>n) high=mid-1;
        else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    ///ios_base::sync_with_stdio(false);
    ///cin.tie(NULL);
    long long int t,n,k;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        k = findnum(n);
        if(k==0) cout<<"Case "<<i<<": impossible"<<"\n";
        else cout<<"Case "<<i<<": "<<k<<"\n";
    }
    return 0;
}
