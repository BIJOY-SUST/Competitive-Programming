#include<iostream>
#include<cstdio>

using namespace std;
long long n,x,ara[500005];
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&x);
        if(i==1){
            ara[i] = x;
        }
        else{
            ara[i] = ara[i-1] + x;
        }
    }
    long long n_ways=0;
    if(ara[n]%3==0){
        long long t=0;

        for(long long i=1;i<n;i++){
            long long u = ara[n]/3;
            long long v = 2*u;
            if(ara[i] == v){
                n_ways += t;
            }
            if(ara[i] == u){
                t++;
            }
        }
    }

    printf("%lld\n",n_ways);

    return 0;
}

