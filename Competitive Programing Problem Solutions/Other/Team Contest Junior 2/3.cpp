#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
#define FOR(i,a,b) for(i=a;i<b;i++)
#define LL long long
#define ULL unsigned long long
#define MIN INT_MIN
#define MAX INT_MAX
#define SF scanf
#define PF printf
#define pi acos(-1.0)
#define db(x) (x*pi)/180.0
#define __  std::ios_base::sync_with_stdio (false)
using namespace std;
vector<int>v;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int arr[27],arr1[27];
memset(arr, 0 ,sizeof(arr));
memset(arr1, 0, sizeof(arr1));
        string s;
        int n;
        cin>>n;
        while(n--)
        {
        cin>>s;
        int l=s.size();
        //cout<<s[0]<<" "<<s[l-1]<<endl;
        arr[s[0]-'a'+1]++;
        arr1[s[l-1]-'a'+1]++;
        }
        int count1=0,count2=0,count=0;
        for(int i=1;i<=26;i++)
        {
           // cout<<arr[i]<<" "<<arr1[i]<<endl;
            if(arr[i]==arr1[i]) continue;
            else if(arr[i]-arr1[i]==1) count1++;
            else if((arr1[i]-arr[i])==1) count2++;
            else if((int)abs(arr1[i]-arr[i])>2)
            {
                count=4;
                break;
            }
            else count++;
        }
        if(count==0 && count1<=1 && count2<=1)
        {
            cout<<"Ordering is possible."<<endl;
        }
        else cout<<"The door cannot be opened."<<endl;
    }


  return 0;
}

