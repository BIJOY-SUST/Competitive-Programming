#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        long long int n,m;
        //double ans;
        scanf("%lld",&n);
        m=(n-26)*20;
        m=(int)(((double)m/49.0)+.5)+1;
        printf("TEST #%d: %lld\n",i,m);
    }
    return 0;
}


