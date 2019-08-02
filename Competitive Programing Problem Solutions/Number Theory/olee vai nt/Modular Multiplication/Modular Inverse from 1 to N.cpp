///Problem
///Given N and M ( N<M and M is prime ).
///Find modular inverse of all numbers between 1 to N with respect to M.
#include<bits/stdc++.h>
#define mx 10000001
using namespace std;
int m_inverse[mx];
int main(){
    int N,M;
    cin>>N>>M;
    m_inverse[1]=1;
    for(int i=2;i<=N;i++){
        m_inverse[i]=(-(M/i)*m_inverse[M%i])%M;
        m_inverse[i]=m_inverse[i]+M;
    }
    for(int i=1;i<=N;i++){
        cout<<m_inverse[i]<<'\n';
    }
    return 0;
}
