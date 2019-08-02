#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
pair<int,int>p[55];
int main() {
    int k, n,ans=0;

    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d %d", &p[i].first, &p[i].second);
    }

    sort(p,p+n);
    reverse(p,p+n);
    int x1 = p[k-1].first, y1 = p[k-1].second;
    for(int i=0;i<n;i++){
        int x2 = p[i].first, y2 = p[i].second;
        if(x1 == x2 && y1 == y2){
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
