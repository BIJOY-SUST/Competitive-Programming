#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int main()
{
    cin>>s1>>s2;
    int ans = 0;
    for(int i=0;i<s1.size();i++)
    {
        int flag = 0;
        for(int j=0;j<s2.size();j++)
        {
            if(i+j>s1.size())
            {
                flag = 1;
                break;
            }
            if(s1[i+j]!=s2[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            s1[i+s2.size()-1]='#';
            ans++;
        }
    }
    cout<<ans<<endl;
}
