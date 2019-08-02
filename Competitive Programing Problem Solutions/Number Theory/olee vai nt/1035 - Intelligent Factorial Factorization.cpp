#include<bits/stdc++.h>
#define mx 1001
using namespace std;
bool mark[mx];
vector<int>prime;
//vector<int>factor;
map<int,int>factor;
void sieve(){
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    for(int i=4;i<=mx;i+=2) mark[i]=false;
    for(int i=3;i*i<=mx;i+=2){
        if(mark[i]){
            for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
void prime_factor(int n){
    int sqrtn=sqrt(n);
    for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                factor[prime[i]]++;
            }
            sqrtn=sqrt(n);
        }
    }
    if(n!=1) factor[n]++;
}
void fact_factor(int n){
    for(int i=2;i<=n;i++) prime_factor(i);
    for(int i=0;prime[i]<=n;i++){
        printf("%d (%d)",prime[i],factor[prime[i]]);
        if(i!=prime.size()-1&&prime[i+1]<=n) printf(" * ");
    }
    printf("\n");
}
int main(){
    sieve();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %d = ",i,n);
        fact_factor(n);
        factor.clear();
    }
    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//void res(int a,int b){
//    int q,sum=0;
//    while(b>0){
//        q=b/a;
//        sum=sum+q;
//        b=q;
//    }
//    printf(" %d (%d)",a,sum);
// }
//int main(){
//    int ara[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };
//    int i,l,num,T,sum=0,n;
//    scanf("%d",&T);
//    for(n=1;n<=T;n++){
//        scanf("%d",&num);
//        printf("Case %d: %d =",n,num);
//        for(i=0;ara[i]<=num;i++){
//            l=ara[i];
//            if(i!=0) printf(" *");
//            res(l,num);
//        }
//        printf("\n");
//    }
//    return 0;
//}
