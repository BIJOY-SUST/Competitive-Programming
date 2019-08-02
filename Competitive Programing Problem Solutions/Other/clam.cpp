#include<bits/stdc++.h>
#define PI 2*acos(0.0)
using namespace std;
int main(){
    int T,n;
    double R,r;
    cin>>T;
    for(int i=1;i<=T;i++){
        scanf("%lf %d",&R,&n);
        r = R*(sin(PI/n)/(1+sin(PI/n)));
        printf("Case %d: %.10f\n",i,r);
    }
    return 0;
}
