#include<bits/stdc++.h>
using namespace std;
int main (){
    int T,a[100001];
    scanf("%d",&T) ;
    for(int k=1;k<=T;k++){
        int n,q;
        scanf("%d %d",&n,&q);
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("Case %d:\n",k);
        for(int i=1;i<=q;i++){
            int x,y,low,up;
            scanf("%d %d",&x,&y);
            low=lower_bound(a,a+n,x)-a ;
            up=upper_bound(a,a+n,y)-a ;
            int m=up-low ;
            printf("%d\n",m) ;
        }
    }
    return 0 ;
}
