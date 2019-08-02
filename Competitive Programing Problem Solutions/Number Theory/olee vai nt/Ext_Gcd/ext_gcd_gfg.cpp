#include<bits/stdc++.h>
using namespace std;
int ext_gcd(int a,int b,int *x,int *y){
    if(a==0){
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int gcd = ext_gcd(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,x,y;
    cin>>a>>b;
    int ans=ext_gcd(a,b,&x,&y);
    printf("gcd(%d, %d) = %d, x = %d, y= %d",a,b,ans,x,y);
    return 0;
}
