#include<bits/stdc++.h>
#define pi 2*acos(0.0)

using namespace std;

int main(){
    int T,n;
    double R,r;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>R>>n;
        r = R*(sin(pi/n)/(1+sin(pi/n)));
        printf("Case %d: %.10f\n",i,r);
    }

    return 0;
}

