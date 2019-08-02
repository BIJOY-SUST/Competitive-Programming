/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
int n,e;
map<int,vector<int> >edges;
map<int,int>finish;
set<int>s;
bool visited[mx];
int cnt=0;;
void dfs(int start){
    visited[start]=true;
    for(__typeof(edges[start].begin())it=edges[start].begin();it!=edges[start].end();it++){
        if(!visited[*it]) dfs(*it);
    }
    cout<<start<<" ";
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    while(scanf("%d%d",&n,&e)==2&&n!=0&&e!=0){
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=e;i++){
            int u,v;scanf("%d%d",&u,&v);
            edges[u].push_back(v);
        }
        for(int i=1;i<=n;i++) s.insert(i);
        for(__typeof(s.begin())it=s.begin();it!=s.end();it++){
            if(!visited[*it]) dfs(*it);
        }

        for(int i=1;i<=n;i++) edges[i].clear();
        s.clear();
    }
    return 0;
}
/**
Input:
7 10
1 2
2 3
3 1
2 4
3 7
4 5
5 4
5 6
6 7
7 6
Output:
1-7 8
2-4 5
3-2 1 3
**/













































//#include<bits/stdc++.h>
//using namespace std;
//#define me BOSS
//map<int ,vector<int> >m;
//stack<int>st;
//set<int>s;
//map<int ,int>reach;
//map<int ,int>finish;
//int cnt=0;
//int vis[1000001];
//int visit[100001];
//int cn=0;
//void printcircle(int start)
//{
//    visit[start]=1;
//    for(__typeof(m[start].begin())it=m[start].begin();it!=m[start].end();it++)
//    {
//        if(visit[*it]==0)
//            printcircle(*it);
//    }
//    cout<<start<<" ";
//}
////bool comp( const pair<int,int>&a ,const pair<int,int>&b)
////{
////    return b< a;
////}
//void top(int start)
//{
//    cnt++;
//    reach[start]=cnt;
//    vis[start]=1;
//    //cout<<cnt<<endl;
//
//
//    for(__typeof(m[start].begin())it=m[start].begin();it!=m[start].end();it++)
//    {
//        if(vis[*it]==0)
//            top(*it);
//        //cnt++;
//    }
////    cnt++;
////    finish[start]=cnt;
//    //st.push(start);
//}
//int main()
//{
//   int n,e,a,b;
//   cin>>n>>e;
//   for(int i=0;i<e;i++)
//   {
//       cin>>a>>b;
//       m[a].push_back(b);
//       s.insert(a);
//       s.insert(b);
//   }
//   for(__typeof(s.begin())it=s.begin();it!=s.end();it++)
//   {
//       if(vis[*it]==0)
//        top(*it);
//   }
//   vector<pair<int,int> >v(reach.begin(),reach.end());
//   cout<<"SIZE:"<<v.size()<<endl;
//   cout<<"Before Sorting:"<<endl;
//   for(int i=0;i<v.size();i++){
//    cout<<v[i].first<<" "<<v[i].second<<endl;
//   }
//   cout<<"After sorting:"<<endl;
//   sort(v.rbegin(),v.rend());
//      for(int i=0;i<v.size();i++){
//    cout<<v[i].first<<" "<<v[i].second<<endl;
//   }
//   cout<<"Final Answer:"<<endl;
//   for(int i=0;i<v.size();i++)
//   {
//       if(visit[v[i].first]==0){
//       cn++;
//       cout<<cn<<"-";
//       printcircle(v[i].first);
//       cout<<endl;
//       }
//   }
//
//   //for(__typeof(s.begin())it=s.begin();it!=s.end();it++){
////    for(int i=n;i>0;i--){
////        if(visit[i]==0){
////            cn++;
////            cout<<cn<<"-";
////            printcircle(i);
////            cout<<endl;
////        }
////   }
//return 0;
//}
///*
//Input:
//6 7
//5 6
//6 5
//4 5
//1 2
//2 3
//3 1
//3 4
//
//
//*/
