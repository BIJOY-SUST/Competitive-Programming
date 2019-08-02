#include<bits/stdc++.h>
using namespace std;
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    int a[1005];
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int t;
        int mm;
        int ans=1000000000;

        for(int i=1;i<n-1;i++)
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
    cout<<ans<<"\n";
    return 0;
}
