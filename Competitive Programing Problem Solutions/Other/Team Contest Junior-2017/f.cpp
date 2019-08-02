#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n,m;
    scanf("%d %d",&n,&m);
    int c=0;
    //if(n>m) swap(n,m);
    for(int i=1;i<=n;i++){
        int h=1;
        while(m>=(5*h)-i){
            c++;
            h++;
            if(m<(5*h)-i) break;
        }
    }
    printf("%d\n",c);
    return 0;
}
