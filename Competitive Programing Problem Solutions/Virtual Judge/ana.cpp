#include<bits/stdc++.h>
using namespace std;

string s;
int n,w1,w2,ans,ans1,ans2;
int main()
{
    scanf("%d",&n);
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(i%2){if(s[i]!='r')w1++;}
        else{if(s[i]!='b')w2++;}
    }
    ans=abs(w1-w2)+min(w1,w2);
    w1=w2=0;
    for(int i=0;i<n;i++)
    {
        if(i%2){if(s[i]!='b')w1++;}
        else{if(s[i]!='r')w2++;}
    }
    ans=min(ans,abs(w1-w2)+min(w1,w2));
    cout<<ans<<endl;
}
