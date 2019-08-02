#include<bits/stdc++.h>
#define max 1000000
using namespace std;
long long int a[max];
int main(){
   long long int n,c=1,d=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i+1]>a[i]){
            c++;
            if(c>d){
                d=c;
            }
            else{
                continue;
            }
        }
        else{
            c=1;
        }
    }
    cout<<d<<endl;
    return 0;

}
