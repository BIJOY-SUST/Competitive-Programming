#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        long long n;
        int ans=1;
        scanf("%lld",&n);
        int h=sqrt(n);
        for(int i=2;i<=h;i++){
            if(h%i==0&&h/i!=i){
                ans=ans+2;
            }
            else if(h%i==0&&h/i==i){
                ans++;
            }
        }
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}
