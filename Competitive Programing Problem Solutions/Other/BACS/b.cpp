#include <bits/stdc++.h>

using namespace std;
int cou[1000];
int countWays(int n, int m)
{
   //int count[n+1];
    cou[0] = 0;
    for (int i = 1; i<= n; i++){
        if (i > m)
            cou[i] = cou[i-1] + cou[i-m];
        else if (i < m)
            cou[i] = 1;
        else
            cou[i] = 2;
    }
    return cou[n];
}


int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    int n,m;
    cin>>m>>n;
    cout<<"Case "<<i<<":"<<countWays(n, m)<<endl;
    for(int i=0;i<=n;i++){
        cout<<cou[i]<<endl;
    }
    }
    return 0;
}
