#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
long long n,a1[10000000],a2[10000000];
int main(){
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a1[i];
    }
    a2[0]=a1[0];
    bool flag = true;
    for(long long i=0;i<n-1;i++){
        if(a1[i]<a1[i+1]){
            a2[i+1] = a1[i+1]-a1[i];
            flag = false;
        }
    }
    sort(a2,a2+n);
    if(flag==false){
        for(long long i=0;i<n;i++){
            if(a2[i])
        }
        cout<<s<<endl;
    }
    sort(a1,a1+n);
    else{
        for(long long i=0;i<n;i++){
            s+=a1[i];
        }
        cout<<s<<endl;
    }
    return 0;
}
