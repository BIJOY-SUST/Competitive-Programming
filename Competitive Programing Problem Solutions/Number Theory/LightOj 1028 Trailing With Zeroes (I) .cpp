#include<bits/stdc++.h>
#define mx 1000001
using namespace std;

bool arr[mx];
long long int k=1;
long long int twin[mx];

void sieve(){
    arr[0]=arr[1]=1;
    for(long long int i=4;i<=mx;i+=2) arr[i]=1;
    for(long long int i=3;i<sqrt(mx);i+=2){
        for(long long int j=i*i;j<=mx;j=j+2*i){
            arr[j]=1;
        }
    }
    for(long long int i=3;i<=mx;i+=2){
        if(arr[i]==0){
            twin[k]=i;
            k++;
        }
    }
}

int main(){
    long long int t;
    cin>>t;
    for(long long int h=1;h<=t;h++){
        long long int m;
        cin>>m;
        long long int r=1;
        for(long long int g=1;g<=k&&twin[g]<=sqrt(m);g++){
            long long int c=0;
            if(m%twin[g]==0){
                while(m%twin[g]==0){
                    c++;
                    m=m%twin[g];
                    if(m==0||m==1){
                        break;
                    }
                }
                long long int s = c+1;
                r = r*s;
            }
        }
        if(m!=1){
            r=r*2;
        }
        printf("Case %lld: %lld\n",h,r-1);
    }
    return 0;
}

