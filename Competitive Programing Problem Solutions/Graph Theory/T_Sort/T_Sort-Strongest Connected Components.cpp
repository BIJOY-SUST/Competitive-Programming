#include<bits/stdc++.h>
using namespace std;
#define me BOSS
vector<int>m[100001];
vector<int>mm[100001];
stack<int>st;
set<int>s;
map<int ,int>reach;
map<int ,int>finish;
int cnt=0;
int vis[1000001];
int visit[100001];
int cn=0;
void printcircle(int start)
{
    visit[start]=1;
    for(__typeof(m[start].begin())it=m[start].begin();it!=m[start].end();it++)
    {
        if(visit[*it]==0)
            printcircle(*it);
    }
    cout<<start<<" ";
}
bool comp( const pair<char,int>&a ,const pair<char,int>&b)
{
    return b< a;
}
void top(int start)
{
    vis[start]=1;
    cnt++;
    reach[start]=cnt;

    for(__typeof(m[start].begin())it=m[start].begin();it!=m[start].end();it++)
    {
        if(vis[*it]==0)
            top(*it);
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
   top(1);
//   for(__typeof(s.begin())it=s.begin();it!=s.end();it++)
//   {
//       if(vis[*it]==0)
//        top(*it);
//   }
//   for(int i=1;i<=n;i++){
//        for(int j=0;j<m[i].size();j++){
//            mm[m[i][j]].push_back(i);
//        }
//   }

   vector<pair<int,int> >v(reach.begin(),reach.end());
   sort(v.begin(),v.end(),comp);
   for(int i=0;i<v.size();i++){
    cout<<v[i].first<<" "<<v[i].second<<endl;
   }
   for(int i=0;i<v.size();i++)
   {
       if(visit[v[i].first]==0){
       cn++;
       cout<<cn<<"-";
       printcircle(v[i].first);
       cout<<endl;
       }
   }
return 0;
}
/*
Input:
8 10
1 2
2 3
3 1
2 4
3 7
4 5
5 4
5 8
8 7
7 8
Output:
1-7 8
2-4 5
3-2 1 3
*/

