#include<bits/stdc++.h>
using namespace std;
int main(){
    long int t,n;
    scanf("%ld",&t);
    for(int i=1;i<=t;i++){
        scanf("%ld",&n);
        long int ans = (1/6)*n*(n+1)*(2*n+1);
        printf("%ld\n",ans);
    }
    return 0;
}
