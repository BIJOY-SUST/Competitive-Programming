#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

string str1,str2;
int main()
{
    long long int n1,n2;
    cin>>str1;
    cin>>str2;
    n1=str1.size();
    n2=str2.size();
    int ans = 0;
    for(int i=0;i<n1;i++)
    {
        bool flag = false;
        for(int j=0;j<n2;j++)
        {
            if(i+j>n1)
            {
                flag = true;
                break;
            }
            if(str1[i+j]!=str2[j])
            {
                flag = true;
                break;
            }
        }
        if(flag==false)
        {
            str1[i+n2-1]='#';
            ans++;
        }
    }
    cout<<ans<<endl;
}
