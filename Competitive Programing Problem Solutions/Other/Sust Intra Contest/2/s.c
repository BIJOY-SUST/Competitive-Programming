#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 1000
using namespace std;

int a[N];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

        int t;
        int mm;
        int ans=1000000000;

        for(int i=1;i<n-1;i++)//枚举每个可以被拿走的
        {
            mm=0;
            for(int j=0;j<n;j++)
            {
                if(j==i)
                {
                    t=a[j+1]-a[j-1];
                }
                else if(j+1==i)
                t=a[j+2]-a[j];

                else
                t=a[j+1]-a[j];

                mm=max(mm,t);

            }
            ans=min(ans,mm);
        }

        cout<<ans<<endl;
    }
    return 0;
}
