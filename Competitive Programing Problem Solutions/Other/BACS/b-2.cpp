#include <bits/stdc++.h>
using namespace std;

long long int countWays(long long int n,long long int m){
    int count[n+1];
    count[0] = 0;
    for (long long int i = 1; i<= n; i++){
        if (i > m)
            count[i] = count[i-1] + count[i-m];
        else if (i < m)
            count[i] = 1;
        else
            count[i] = 2;
    }
    return count[n];
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    long long int n,m;
    cin>>m>>n;
    printf("Case %d: %d\n",i,countWays(n, m));//cout<<"Case "<<i<<": "<<countWays(n, m)%1000000007<<endl;
    //else cout<<"Case "<<i<<": "<<countWays(n, m)<<endl;
    }
    return 0;
}
