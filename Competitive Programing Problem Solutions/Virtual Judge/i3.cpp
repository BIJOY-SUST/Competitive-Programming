#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    long long n,d;
    int a[100];
    cin>>n>>d;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<d;i++){
        int swap = a[0];
        long long j;
        for(j=0;j<n-1;j++){
            a[j] = a[j+1];
        }
        a[j] = swap;
    }
    long long i;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
