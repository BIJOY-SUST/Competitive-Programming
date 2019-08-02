#include<bits/stdc++.h>
using namespace std;
#define me BOSS
map<int ,vector<int> >m;
stack<int>st;
set<int>s;
map<int ,int>reach;
map<int ,int>finish;
int cnt=0;
int vis[1000001];
void top(int start)
{
    vis[start]=1;
    cnt++;
    reach[start]=cnt;
    for(__typeof(m[start].begin())it=m[start].begin();it!=m[start].end();it++)
    {
        if(vis[*it]==0)
        {
            top(*it);
        }
//        cnt++;
    }
    cnt++;
    finish[start]=cnt;
    st.push(start);
}
int main()
{
    int n,e,a,b;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        m[a].push_back(b);
        s.insert(a);
        s.insert(b);
    }
    for(__typeof(s.begin())it=s.begin();it!=s.end();it++)
    {
      if(vis[*it]==0)
      {
          top(*it);
      }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" "<<reach[st.top()]<<" "<<finish[st.top()]<<endl;
        st.pop();
    }
return 0;
}
/*
Input:
5 6
1 2
2 3
3 4
1 4
2 5
3 5

7 8
1 2 2 3 3 1 3 4 4 5 5 6 6 7 7 5
Output:
1 1 16
2 2 13
3 3 10
5 7 8
4 4 5
*/

