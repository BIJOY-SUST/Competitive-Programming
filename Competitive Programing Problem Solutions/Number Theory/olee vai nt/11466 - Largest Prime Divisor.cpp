#include<bits/stdc++.h>
//#define mx 1000001
using namespace std;
//bool mark[mx];
//vector<int>prime;
//void sieve(){
//    memset(mark,true,sizeof(mark));
//    mark[0]=mark[1]=false;
//    for(int i=4;i<=mx;i+=2) mark[i]=false;
//    for(int i=3;i*i<=mx;i+=2){
//        if(mark[i]){
//            for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
//        }
//    }
//    prime.push_back(2);
//    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
//}
int main(){
//    sieve();
    long long n;
    while(scanf("%lld",&n)){
        if(n==0) break;
        if(n<0) n*=-1;
        bool flag=false;
        int c=0;
        long long ans=-1;
        for(long long i=2;i*i<=n&&n!=1;i++){
            if(n%i==0){
                c++;
                flag=true;
                while(n%i==0){
                    n/=i;
                    ans=i;
                }
            }
        }
        if(n!=1&&flag==true) ans=n;
        else if(c==1) ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}

