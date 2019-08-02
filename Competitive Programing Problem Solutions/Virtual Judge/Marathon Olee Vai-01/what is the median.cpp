#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int i=0,a[10001];
    while(cin>>a[i]){
        sort(a,a+i+1);
        if(i%2==0){
            printf("%lld\n",a[i/2]);
        }
        else if(i%2!=0){
            printf("%lld\n",(a[(i-1)/2]+a[(i+1)/2])/2);
        }
        i++;
    }
    return 0;
}
