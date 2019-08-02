#include<bits/stdc++.h>
//#define mx 10000001
using namespace std;
vector<int>prime;
void sieve(int mx){
    if(mx==1) prime.push_back(1);
    else if(mx==2){
        prime.push_back(1);
        prime.push_back(2);
    }
    else{
    bool mark[mx+1];
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    for(int i=4;i<=mx;i+=2) mark[i]=false;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(mark[i]){
            for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
        }
    }
    prime.push_back(1);
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
    }
}
int main(){
//    freopen("111.txt","r",stdin);
//    freopen("112.txt","w",stdout);
    int n,c;
    while(scanf("%d %d",&n,&c)==2){
        sieve(n);
        int s=prime.size();
        if(s%2){
            int cc=c*2-1;
            if(cc>=s){
                printf("%d %d:",n,c);
                for(int i=0;i<s;i++){
                    printf(" %d",prime[i]);
                }
                printf("\n");
            }
            else{
                int L1=s/2-cc/2;
                int L2=s/2+cc/2;
                printf("%d %d:",n,c);
                for(int i=L1;i<=L2;i++){
                    printf(" %d",prime[i]);
                }
                printf("\n");
            }
        }
        else{
            int cc=c*2;
            if(cc>=s){
                printf("%d %d:",n,c);
                for(int i=0;i<s;i++){
                    printf(" %d",prime[i]);
                }
                printf("\n");
            }
            else{
                int L1=s/2-c;
                int L2=s/2+c;
                printf("%d %d:",n,c);
                for(int i=L1;i<L2;i++){
                    printf(" %d",prime[i]);
                }
                printf("\n");
            }
        }
        printf("\n");
        prime.clear();
    }
    return 0;
}
//    for(int i=0;i<=28;i++){
//        cout<<i+1<<" "<<prime[i]<<endl;
//    }

