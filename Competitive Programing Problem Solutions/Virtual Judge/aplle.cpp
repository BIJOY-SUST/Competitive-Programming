#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    long long i,j,n,sum=0;
    long long a[10000];
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){

        for(j=i;j<n;j++){
            sum = sum + a[j];
        }
        sum = sum + a[i];
    }
    sum = sum -a[i-1];
    cout<<sum;

    return 0;
}

