#include<bits/stdc++.h>
//#define M_E 2.718281828
//#define M_PI 22/7
using namespace std;
//int num_digit_fac(int n,int base){
//    double x=0;
//    for(int i=1;i<=n;i++){
//        x+=log10(i)/log10(base);
//    }
//    int ans=((int)x)+1;
//    return ans;
//}
//int digit(int n,int base){
//    if(n<0) return 0;
//    if(n<=1) return 1;
//    double x=((n*log10(n/M_E)+log10(2*M_PI*n)/2.0))/log10(base);
//    return floor(x)+1;
//}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,base;
        scanf("%d %d",&n,&base);
        int ans=digit(n,base);
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}

