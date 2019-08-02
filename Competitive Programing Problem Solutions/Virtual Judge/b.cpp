#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define sf scanf
#define pf printf
typedef long long ll;

int main()
{
    char s[105];
    cin >> s;
    int len = strlen(s);
    sort(s, s+len);
    int count =0;
    for(int i=0; i<len; i++)
    {
        if(s[i] != s[i+1])
        {
            count++;
        }
    }
    if(count%2==0)
    {
        pf("CHAT WITH HER!\n");
    }
    else
    {
        pf("IGNORE HIM!\n");
    }
}
