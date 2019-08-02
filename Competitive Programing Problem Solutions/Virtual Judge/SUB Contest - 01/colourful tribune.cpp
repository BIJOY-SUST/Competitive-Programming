#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    map<char,int>mp;
    while(cin>>n)
    {
        char a[n+1][n+1];
        char aa,bb;
        int x,y,x1,y1,y2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                mp[a[i][j]]++;
            }
        }
        map<char,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==n-1) aa=it->first;
            if(it->second==n+1) bb=it->first;
        }
        //cout<<aa<<" "<<bb<<endl;
        if(mp[bb]!=(n+1))
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[a[i][j]]!=n-1 && mp[a[i][j]]!=n)
                {
                    x=i+1;
                    y2=j+1;
                }
            }
        }
        else
        {
        //cout<<"HGBF"<<endl;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==bb)
                {
                    c++;
                }
                if(c==2 && a[i][j]==bb)
                {
                    x=i;
                }
            }
        }
        //cout<<"HHG"<<endl;
        int c=0;
        for(int j=0;j<n;j++)
        {
            if(a[x][j]==bb) c++;
            if(a[x][j]==bb && c==1)
            {
                y=j;
            }
            else if(a[x][j]==bb && c==2)
            {
                y1=j;
            }
        }
        //cout<<"HGB"<<endl;
        //cout<<x<<" "<<y<<" "<<y1<<endl;
        c=0;
        for(int i=0;i<n;i++)
        {

            if(a[i][y]==bb)
            {
                c++;
            }
            if(c==2)
            {
                y2=y+1;
            }
        }
        c=0;
        //cout<<"HGG"<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i][y1]==bb)
            {
                c++;
            }
            if(c==2)
            {
                y2=y1+1;
            }
        }
        x++;
        }
        cout<<x<<" "<<y2<<" "<<aa<<endl;
        mp.clear();
    }
    return 0;
}
/*
3
ABC
BBA
CAB
*/

