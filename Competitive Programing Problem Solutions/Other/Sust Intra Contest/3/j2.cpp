#include<bits/stdc++.h>
using namespace std;
#define mx 1005
int arr[mx];

void sieve(){
    int i,j;
    memset(arr,1,sizeof(arr));
    arr[0]=arr[1]=1;
    for(i=4;i<=mx;i=i+2) arr[i]=0;
    for(i=3;i<=sqrt(mx);i=i+2){
        for(j=i*i;j<=mx;j=j+2*i){
            arr[j]=0;
        }
    }
}

int main(){
    int n,k,c=0;
    sieve();
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        if(arr[i]){
            for(int j=2;j<=i;j++){
                if(arr[j]){
                    for(int h=j+1;h<=i;h++){
                        if(arr[h]){
                            if(j+h+1==i){
                                c++;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    c<k?cout<<"NO"<<"\n":cout<<"YES"<<"\n";
    return 0;
}
