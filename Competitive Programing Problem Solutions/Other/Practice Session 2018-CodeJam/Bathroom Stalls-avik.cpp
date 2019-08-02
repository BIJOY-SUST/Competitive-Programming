#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int cnt=1;
    map<long long int,long long int>mp;
    while(t--)
    {
        long long int n,k;
        mp.clear();
        cin>>n>>k;
         printf("Case #%d: ",cnt++);
        priority_queue<long long int>q;
        mp[n]=1;
        q.push(n);

        while(mp[q.top()]<k)
        {
            cout<<q.top()<<" "<<mp[q.top()]<<endl;
             long long int x=q.top()/2;
             k-=mp[q.top()];
            if(q.top()%2==0)
            {
                if(mp[x]==0)
                {
                    q.push(x);
                }
                if(mp[x-1]==0)
                {
                    q.push(x-1);
                }

               mp[x-1]+=mp[q.top()];
               mp[x]+=mp[q.top()];

            }
             if(q.top()%2==1)
            {
                if(mp[x]==0)
                {
                    q.push(x);
                }


               mp[x]+=mp[q.top()];
               mp[x]+=mp[q.top()];
               cout<<x<<" "<<mp[x]<<endl;

            }

            q.pop();
        }
        if(q.top()%2==0)
        {
            cout<<q.top()/2<<" "<<(q.top()/2)-1<<endl;
        }
        else
        {
             cout<<q.top()/2<<" "<<(q.top()/2)<<endl;
        }
        while(!q.empty())
        {
            q.pop();
        }

    }
}


