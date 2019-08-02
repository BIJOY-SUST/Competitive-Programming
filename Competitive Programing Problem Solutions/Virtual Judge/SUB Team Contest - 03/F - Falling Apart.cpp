#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,s1=0,s2=0,c=0;
    cin>>n;
    ll a[n+1];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
    if(c%2==0)
    {
    s1+=a[i];
    c++;
    }
    else
    {
    s2+=a[i];
    c++;
    }
    }
    cout<<s1<<" "<<s2<<endl;
    return 0;
}
