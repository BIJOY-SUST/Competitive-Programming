#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int k, n, ans=0;
    pair <int, int> p[55];
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d%d", &p[i].first, &p[i].second);
        p[i].first *= -1;
        //printf("%d\n", p[i].first);
    }
    sort(p, p+n);

    for(int i=0; i<n; i++){
        printf("%d\n", p[i]);
        if(p[i]==p[k-1]){
            ans++;
        }
    }
    //printf("%d", ans);
    return 0;
}
