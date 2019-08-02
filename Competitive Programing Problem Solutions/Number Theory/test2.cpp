#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
bool arr[mx];
long long int k=1;
long long int twin[mx];

void sieve(){
    long long int i,j;
    arr[0]=arr[1]=1;
    for(i=4;i<=mx;i=i+2) arr[i]=1;
    for(i=3;i<=sqrt(mx);i=i+2){
        for(j=i*i;j<=mx;j=j+2*i){
            arr[j]=1;
        }
    }
    for(i=2;i<=mx;i++){
        if(arr[i]==0){
            twin[k]=i;
            k++;
        }
    }
}

int main(){
    long long int t,h,m,r,g,c,s;
    cin>>t;
    sieve();
    for(h=1;h<=t;h++){
        cin>>m;
        r=1;
        for(g=1;g<=k&&twin[g]<=sqrt(m);g++){
            c=0;
            if(m%twin[g]==0){
                while(m%twin[g]==0){
                    c++;
                    m=m/twin[g];
                    if(m==0||m==1){
                        break;
                    }
                }
                s = c+1;
                r = r*s;
            }
        }
        if(m!=1) r=r*2;
        printf("Case %lld: %lld\n",h,r-1);
    }
    return 0;
}


