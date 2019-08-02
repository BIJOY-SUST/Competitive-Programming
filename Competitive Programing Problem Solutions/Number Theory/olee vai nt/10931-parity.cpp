#include<bits/stdc++.h>
using namespace std;

int main(){
//    freopen("aa.txt","r",stdin);
//    freopen("aab.txt","w",stdout);
    long long int n;
    while(scanf("%lld",&n)&&n){
        int c=0,k=0;
        int bit[105];
        while(n>0){
            bit[k]=n%2;
            n=n/2;
            if(bit[k]==1) c++;
            k++;
        }
        printf("The parity of ");
        for(int i=k-1;i>=0;i--){
            printf("%d",bit[i]);
        }
        printf(" is %d (mod 2).\n",c);
    }
    return 0;
}
