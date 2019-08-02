#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main(){
    int N,M;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>M;
        int a[100000];
        for(int j=0;j<M;j++){
            cin>>a[j];
        }
        sort(a,a+M);
        int  gcd=1;
        for(int i=0;i<M-1;i++){
        for(int k=i+1;k<M;k++){
            for(int j=2;j<=a[i]&&j<=a[k];j++){
            if(a[i]%j==0 && a[k]%j == 0){
            if(j>gcd){
                gcd = j;
            }
            }
            }
        }
        }
        cout<<gcd<<endl;
    }

    return 0;
}
