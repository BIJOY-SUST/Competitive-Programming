#include<bits/stdc++.h>
#define mx 1000003
using namespace std;
double arr[mx];
int main(){
    int t,n,b;
    arr[1]=log10((double)1);
    for(int i=2;i<mx;i++){
        arr[i]=arr[i-1]+log10((double)i);
    }
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d %d", &n, &b);
        long long cnt=arr[n]/log10(b)+1;
        printf("Case %d: %lld\n", i, cnt);
    }
    return 0;
}
