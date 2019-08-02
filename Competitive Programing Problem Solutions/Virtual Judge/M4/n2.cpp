#include<bits/stdc++.h>
using namespace std;
long long int a[2000001];
int main(){
    int n,m,c = 0;
    cin>>n>>m;
    for(int j=0;j<2*m*n-1;j=j+2){
        cin>>a[j]>>a[j+1];
        if(a[j]==1||a[j+1]==1){
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}

