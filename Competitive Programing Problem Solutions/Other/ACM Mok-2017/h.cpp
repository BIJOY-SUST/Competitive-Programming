#include<bits/stdc++.h>
#define mx 100010
using namespace std;
int arr[mx];
void seive(){
    arr[0]=0;
    arr[1]=2;
    arr[2]=3;
    for(int i=3;i<mx;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
}
long long Big_Mod(long long a,long long p,long long m){
    long long ans=1%m,x=a%m;
    while(p){
        if(p&1) ans=(ans*x)%m;
        x=(x*x)%m;
        p=p>>1;
    }
    return ans;
}
//int main(){
//    long long a,p,m;
//    while(cin>>a>>p>>m){
//        cout<<Big_Mod(a,p,m)<<'\n';
//    }
//    return 0;
//}
int main(){
    seive();

//    for(int i=0;i<10;i++) printf("%d ",arr[i]);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        long long int n,k,m,ans;
        scanf("%lld %lld %lld",&n,&k,&m);
        ans=arr[n];
//        printf("%d\n",ans);
        ans=Big_Mod(k,ans,m);
        printf("Case %d: %lld\n",i,ans);
    }

}
