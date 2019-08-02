#include <bits/stdc++.h>
using namespace std;
#define n 1000005
bool a[n];
long long int k=1;
long long int twin[n];
void sieve()
{
    long long int i,j;
    a[0]=a[1]=1;
    for(i=4;i<=n;i=i+2)
    {
        a[i]=1;
    }
    for(i=3;i<=sqrt(n);i=i+2)
    {
        for(j=i*i;j<=n;j=j+2*i)
        {
            a[j]=1;        //3*3, 3*5,3*7.....
        }
    }
    for(i=2;i<=n;i++)
    {
        if(a[i]==0)
        {
           twin[k]=i;
           k++;
        }
    }

}
int main()
{
    long long int m,g,c,r,s,t,l,h;
    //ifstream in ("1028.txt");
    //ofstream out("out1028.txt");
    cin>>t;
    //in>>t;
    sieve();
    for(l=1;l<=t;l++)
    {
        cin>>m;
        //in>>m;
        r=1;
        h=0;
        for(g=1;g<=k && twin[g]<=sqrt(m);g++)
        {
            c=0;
            if(m%twin[g]==0)
            {

            while(m%twin[g]==0)
            {
                c++;
                m=m/twin[g];
                if(m==0 || m==1)
                {
                    break;
                }

             }
              s=c+1;
              r=r*s;
            }



        }
        if(m!=1)
        {
            r=r*2;    //for prime numbers there are only 2 divisors.
        }

        printf("Case %lld: %lld\n",l,r-1);
        //out<<"Case "<<l<<":"<<" "<<r-1<<endl;

    }

    return 0;
}
