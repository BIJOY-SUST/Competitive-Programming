#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
//#define ll             long long int
#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<m
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
char a[19][19];
int cnt1=0,n,m,ans1=0,rider[105],sq[19][19],dis[19][19][105];
bool vis[19][19];
void bfs(int i,int j,int c){
    mem(vis,false);
    dis[i][j][c]=0;
    sq[i][j]++;
    queue<pp >q;
    q.push({i,j});
    vis[i][j]=true;
    while(!q.empty()){
        pp x=q.front();
        q.pop();
        if(sq[x.first][x.second]==cnt1){
            int ans2=0;
            for(int i=1;i<=cnt1;i++){
//                ans2+=ceil((double)dis[x.first][x.second][i]/rider[i]);
                    ans2+=(dis[x.first][x.second][i]+rider[i]-1)/rider[i];
//                cout<<"yaa "<<dis[x.first][x.second][i]<<endl;
            }
//            bug(ans2);
            ans1=min(ans2,ans1);
        }
        for(int i=0;i<8;i++){
            int tx=x.first+fx[i];
            int ty=x.second+fy[i];
            if(valid(tx,ty)){
                if(!vis[tx][ty]){
                    dis[tx][ty][c]=dis[x.first][x.second][c]+1;
                    vis[tx][ty]=true;
                    sq[tx][ty]++;
                    q.push({tx,ty});
                }
            }
        }
    }
//    while(!q.empty()) q.pop();
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",&a[i]);
        }
        cnt1=0;
        int c=0;
        mem(rider,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]!='.'){
                    cnt1++;
                    c++;
                    rider[c]=a[i][j]-'0';
                }
            }
        }
//        bug(cnt1);
        int cnt2=0;
        ans1=1000001;
        mem(sq,0);
        mem(dis,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]!='.'){
                    cnt2++;
//                    bug(cnt2);
                    bfs(i,j,cnt2);
                }
            }
        }
        if(ans1!=1000001) printf("Case %d: %d\n",cs,ans1);
        else{
            printf("Case %d: -1\n",cs);
        }
    }
    return 0;
}
/*
Input:
5

3 2
..
2.
..

3 3
1.1
...
..1

10 10
..........
.2....2...
......2...
1.........
...2.1....
...1......
..........
.......21.
..........
..........

1 4
1..1

8 4
.54.
5...
....
.4..
.5..
1.13
5..5
8..9
Output:
Case 1: 0
Case 2: 4
Case 3: 14
Case 4: -1
Case 5: 12
*/






























//#include<bits/stdc++.h>
////#define mx             100001
////#define mod            1000000007
////#define pi             2*acos(0.0)
//#define pp             pair<int,int>
////#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
////#define one(n)         __builtin_popcount(n)
////#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<n&&ty>=0&&ty<m
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
////int biton(int n,int pos){return n=n|(1<<pos);}
////int bitoff(int n,int pos){return n=n&~(1<<pos);}
////bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
////template< class T > inline T SQR(T a) {return ((a)*(a));}
////template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
////template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
////template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
////template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
////template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
//using namespace std;
//char a[11][11];
//int n,m;
//int f_dis[11][11][101];
//bool vis[11][11];
////priority_queue<pp,vector<pp>,greater<pp> >q;
//void bfs(int i,int j,int c,int num){
//    mem(vis,false);
//    int dis[11][11][101];
//    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
//        dis[i][j][c]=100001;
//    queue<pp >q;
//    q.push({i,j});
//    dis[i][j][c]=0;
//    while(!q.empty()){
//        pp x=q.front();
//        q.pop();
////        if(vis[x.first][x.second]) continue;
//        for(int i=0;i<8;i++){
//            int tx=x.first+fx[i];
//            int ty=x.second+fy[i];
//            if(valid(tx,ty)){
//                if(dis[tx][ty][c]>dis[x.first][x.second][c]+1){
//                    dis[tx][ty][c]=dis[x.first][x.second][c]+1;
//                    q.push({tx,ty});
//                }
//            }
//        }
//    }
//    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
//        if(c==1&&dis[i][j][c]!=100001){
//            int d=(dis[i][j][c]+num-1)/num;
//            f_dis[i][j][c]+=f_dis[i][j][c-1];
//            f_dis[i][j][c]+=d;
//        }
//        else if(dis[i][j][c]!=100001&&f_dis[i][j][c-1]!=0){
//            int d=(dis[i][j][c]+num-1)/num;
//            f_dis[i][j][c]+=f_dis[i][j][c-1];
//            f_dis[i][j][c]+=d;
//        }
//    }
//    //while(!q.empty()) q.pop();
//}
//int main(){
////    freopen("Input.txt","r",stdin);
////    freopen("Output.txt","w",stdout);
//    int t;
//    scanf("%d",&t);
//    for(int cs=1;cs<=t;cs++){
//        scanf("%d %d",&n,&m);
//        for(int i=0;i<n;i++){
//            scanf("%s",&a[i]);
//        }
//        int cnt1=0;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                if(a[i][j]!='.') cnt1++;
//            }
//        }
//        if(cnt1==1){
//            printf("Case %d: 0\n",cs);
//            return 0;
//        }
//        int cnt2=0;
//        mem(f_dis,0);
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                if(a[i][j]!='.'){
//                    int num=a[i][j]-'0';
//                    cnt2++;
//                    bfs(i,j,cnt2,num);
//                }
//            }
//        }
//        int ans=1000001;
//        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
//            if(f_dis[i][j][cnt1]!=0)
//                ans=min(ans,f_dis[i][j][cnt1]);
//        }
//        if(ans!=1000001) printf("Case %d: %d\n",cs,ans);
//        else{
//            printf("Case %d: -1\n",cs);
//        }
//    }
//    return 0;
//}
