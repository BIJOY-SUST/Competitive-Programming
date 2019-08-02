#include<bits/stdc++.h>
using namespace std;
int main(){
    int i=0;
    long long int n;
    while(scanf("%lld",&n)&&n){
        int ans=ceil((3+sqrt(9+8*n))/2);
        printf("Case %d: %d\n",++i,ans);
    }
    return 0;
}
///The number of diagonals in a polygon = n(n-3)/2,
///where n is the number of polygon sides.
