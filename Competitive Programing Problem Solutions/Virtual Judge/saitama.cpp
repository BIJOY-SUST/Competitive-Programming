//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define maxn 1005
int a[maxn];

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
    {
        int x,t;
        scanf("%d%d",&x,&t);
        //printf("%d\n",a[x]);
        a[x]=max(t,a[x]);
        //printf("%d\n",a[x]);

    }
    //int x,y;
    int ans=0;
    for(int i=s;i>=0;i--)
    {
        ans = max(ans,a[i]);
        //printf("%d\n",ans);
        ans++;
        //printf("%d\n",ans);
    }
    cout<<ans-1<<endl;
}
