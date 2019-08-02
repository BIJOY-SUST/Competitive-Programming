#include<bits/stdc++.h>
using namespace std;
int dis[20][20];
int ar[20][20];
int arx[]={0,0,1,-1};
int ary[]={-1,1,0,0};
int n,c;
map<int,int>mp,mp1;
void dfs(int i,int j,int cn)
{
    cn++;
    for(int h=0; h<4;h++)
    {
        int x=i+arx[h];
        int y=j+ary[h];
        if(i>=0 && j>=0 && i<n && j<n && ar[x][y]==cn)
        {
            if(cn==10)
            {
                c++;
            }
            dfs(x,y,cn);
        }
    }

}
int main()
{
    int t;
    int cnt=1;
    cin>>t;
    while(t--)
    {
        //int n;
       // memset(dis,0,sizeof(dis));
        cin>>n;
        c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ar[i][j];
            }
        }
        if(n<=3)
        {
            printf("Case %d: 0\n",cnt++);
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {

                   //dfs(i,j,1);
                   //dis[i][j]=1;
                   int cn=0,k,kk;
                   mp.clear();
//cout<<c<<endl;
                   for(k=i;k<i+2 && k<n;k++)
                   {
                       for(kk=j;kk<j+5 && kk<n;kk++)
                       {
                           //cout<<"ll"<<endl;
                           if(mp[ar[k][kk]]==0)
                           {
                               cn++;
                               mp[ar[k][kk]]++;
                           }
                       }
                   }
                  // cout<<c<<endl;
                   if(cn==10)
                   {
                       c++;
                       //cout<<"aaaaa"<<endl;
                   }
                   cn=0;
                   mp.clear();
                   for(k=i;k<i+5 && k<n;k++)
                   {
                      // cout<<k<<endl;
                       for(kk=j;kk<j+2 && kk<n;kk++)
                       {
                           //cout<<mp[ar[k][kk]]<<endl;
                           if(mp[ar[k][kk]]==0)
                           {
                               mp[ar[k][kk]]=1;
                               cn++;
                           }
                       }
                   }
                   //cout<<c<<endl;
                   if(cn==10)
                   {
                       c++;
                       //cout<<"aaa"<<endl;
                   }
                   cn=0;
                   mp.clear();
                   for(k=i;k<=i && k<n;k++)
                   {
                       for(kk=j;kk<j+10 && kk<n;kk++)
                       {
                           if(mp[ar[k][kk]]==0)
                           {
                               mp[ar[k][kk]]++;
                               cn++;
                           }
                       }
                   }
                  // cout<<c<<endl;
                    if(cn==10)
                   {
                       c++;
                       cout<<"aaaa"<<endl;
                   }
                   cn=0;
                   mp.clear();
                   for(k=i;k<i+10 && k<n;k++)
                   {
                       for(kk=j;kk<=j && kk<n;kk++)
                       {
                           if(mp[ar[k][kk]]==0)
                           {
                               mp[ar[k][kk]]=1;
                               cn++;
                           }
                       }
                   }
                   cn=0;
                   mp.clear();
                  // cout<<c<<endl;
               }
            }
            printf("Case %d: %d\n",cnt++,c);
    }
        }


