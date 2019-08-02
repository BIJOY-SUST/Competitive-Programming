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
            int x,y;
            scanf("%d %d",&x,&y);
            vector<int>v(a,a+n);
            sort(v.begin(),v.end());
            vector<int>::iterator low,up;
            low=lower_bound(v.begin(),v.end(),x);
            up= upper_bound(v.begin(),v.end(),y);
            int m=(up-v.begin())-(low-v.begin());
            printf("%d\n",m) ;
        }
    }
    return 0 ;
}
