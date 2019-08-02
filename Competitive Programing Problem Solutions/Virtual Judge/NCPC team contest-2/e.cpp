#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<< #x" " << x << endl;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    int n,o,m;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        if(a==1)
            o=i+1;
        if(a==n)
            m=i+1;
    }
    int mm=max(n-m,m-1);
    int oo = max(o-1,n-o);
    cout<< max(mm,oo);
    return 0;
}
