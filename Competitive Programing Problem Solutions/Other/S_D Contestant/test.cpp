#include <bits/stdc++.h>
using namespace std;

int n,t,r;
int adl[102][102];


void fw()
{
    int i,j,k;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<n; k++)
            {
                if(adl[i][j]>adl[i][k]+adl[k][j])
                    adl[i][j]=adl[i][k]+adl[k][j];


            }
}


int main()
{
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int cs=1;
    int u,v,i,j;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&n,&r);

        for(i=0; i<101; i++)
            for(j=0; j<101; j++)
            {
                if(i==j)
                    adl[i][j] = 0;
                else adl[i][j] = INT_MAX;
            }

        while(r--)
        {
            scanf("%d%d",&u,&v);
            adl[u][v] =1;
            adl[v][u]=1;


        }
        scanf("%d%d",&u,&v);
        fw();
        int ans =0;

        for(i=0; i<n; i++)
        {
            ans = max(ans,adl[u][i]+adl[i][v]);

        }

        printf("Case %d: %d\n",cs++,ans);


    }





}
