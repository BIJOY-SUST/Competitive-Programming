#include<bits/stdc++.h>
#define mx 5000000001
using namespace std;
vector<int>divisor;
void Copy_Divisor(long long int n){
    int sqrtn=sqrt(n);
    for(int i=1;i<=sqrtn;i++){
        if(n%i==0){
            if(i*i==n){
                divisor.push_back(i);
            }
            else{
                divisor.push_back(i);
                divisor.push_back(n/i);
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        long long int P,L,n;
        scanf("%lld %lld",&P,&L);
        n=P-L;
        if(n<=L){
            printf("Case %d: impossible\n",i);
            continue;
        }
        Copy_Divisor(n);
        sort(divisor.begin(),divisor.end());
//        for(int j=0;j<divisor.size();j++){
//            if(P%divisor[j]!=L){
//                divisor.erase(divisor.begin()+j);
//            }
//        }
        printf("Case %d:",i);
        for(int j=0;j<divisor.size();j++){
            if(divisor[j]>L) printf(" %d",divisor[j]);
        }
        printf("\n");
        divisor.clear();
    }
    return 0;
}


