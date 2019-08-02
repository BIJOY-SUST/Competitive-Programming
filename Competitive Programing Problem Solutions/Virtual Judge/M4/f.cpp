#include<bits/stdc++.h>
#define max 1000000
using namespace std;
long long int A[max];
find(int x,int y){
    if(x>y) return 1;
    int ans = pow(A[x-1],find(x+1,y));
    return ans;
}
int main(){
   long long int n,c,x,y,d;
   cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cin>>c;
    while(c--){
        cin>>x>>y;
        d = (int)find(x,y);
        if(d&1){
            cout<<"Odd"<<endl;
        }
        else{
            cout<<"Even"<<endl;
        }
    }
    return 0;
}



