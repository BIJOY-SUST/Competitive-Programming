#include<bits/stdc++.h>
using namespace std;
///NO: 01
//long long factorialPrimePower(long long n,long long p){
//    long long freq=0;
//    long long cur=p;
//    while(n/cur){
//        freq += n/cur;
//        cur*=p;
////        printf("%lld ",cur);
//    }
//    return freq;
//}
///NO: 02
//long long factorialPrimePower(long long n,long long p){
//    long long freq=0;
//    long long x=n;
//    while(x){
//        freq += x/p;
//        x=x/p;
////        printf("%lld ",cur);
//    }
//    return freq;
//}
///NO: 03
long long factorialPrimePower(long long n,long long p){
    long long freq=0;
    long long x=n;
    while(x/p){
        freq += x/p;
        x=x/p;
    }
    return freq;
}
int main(){
    long long int n,p;
    scanf("%lld %lld",&n,&p);
    printf("%lld Occures %lld times in %lld factorial.\n",p,factorialPrimePower(n,p),n);
    return 0;
}
