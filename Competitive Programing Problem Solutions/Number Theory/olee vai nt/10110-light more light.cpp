#include<cstdio>
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    freopen("indev.txt","r",stdin);
//    freopen("outdev.txt","w",stdout);
    long long n;
    while(scanf("%lld",&n),n){
        //if(n==0) break;
        if(ceil(sqrt(n))==floor(sqrt(n))) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
