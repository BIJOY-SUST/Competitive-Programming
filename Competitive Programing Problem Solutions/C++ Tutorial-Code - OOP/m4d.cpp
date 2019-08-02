#include<bits/stdc++.h>
#define p 1000000007
using namespace std;

unsigned long long int fact(unsigned long long int t){
    unsigned long long int i,temp=1;
    for(i=1;i<=t;i++){
        temp=((temp*i)%p);
    }
    return temp;
}
int main(){
    int t,i;
    cin>>t;
    unsigned long long int a,n,m;
    for(i=0;i<t;i++){
        cin>>n>>m;
        m=m-1;
        a = ((fact(n+m)%p)/((fact(n)%p)*(fact(m)%p))%p)%p;
        cout<<fact(n+m)%p<<endl;
        cout<<fact(n)%p<<endl;
        cout<<fact(m)%p<<endl;
        cout<<a<<endl;
    }
    return 0;
}
