#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int gcd(int a, int b){
    while (b){
        int test = a%b;
        a = b;
        b = test;
    }
    return a;
}

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
        int  mgcd=1;
        for(int i=0;i<M-1;i++){
            for(int j=i+1;j<M;j++){
                int y = gcd(a[i], a[j]);
                if(y>mgcd){
                    mgcd = y;
                }
            }
        }
        cout<<gcd<<endl;
    }
    return 0;
}
