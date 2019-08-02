#include<bits/stdc++.h>
#define mx 10000001
using namespace std;
bool mark[mx];
vector<int>prime;
void sieve(){
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    for(int i=4;i<=mx;i+=2) mark[i]=false;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(mark[i]){
            for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
int main(){
    sieve();
    int n;
    while(scanf("%d",&n)&&n){
        bool flag=true;
        int a,b;
        for(int i=2;i<n;i++){
            if(mark[i]&&mark[n-i]){
                a=i;
                b=n-i;
                flag=false;

                break;
            }
        }
        if(flag) printf("%d:\nNO WAY!\n",n);
        else printf("%d:\n%d+%d\n",n,a,b);
    }
    return 0;
}
