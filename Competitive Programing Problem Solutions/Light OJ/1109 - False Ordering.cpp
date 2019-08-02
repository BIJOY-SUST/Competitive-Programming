#include<bits/stdc++.h>
//#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
vector<pair<int,int> >jora;
int NOD(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i*i!=n) cnt+=2;
            else cnt++;
        }
    }
    return cnt;
}
bool compare(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second==b.second){
        return a.first>b.first;
    }
    else{
        return a.second<b.second;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i=1;i<=1000;i++){
        int ans=NOD(i);
        jora.push_back(make_pair(i,ans));
    }
    sort(jora.begin(),jora.end(),compare);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        cout<<"Case "<<cs<<": "<<jora[n-1].first<<endl;
//        printf("Case %d: %d\n",cs,jora[n-1].first);
    }
    return 0;
}
/*

*/





























//#include<bits/stdc++.h>
//#define mx             1010
////#define mod            1000000007
////#define pi             2*acos(0.0)
//#define pp             pair<int,int>
////#define ll             long long int
////#define bug(x)         printf("X: %d\n",x)
////#define one(n)         __builtin_popcount(n)
////#define ull            unsigned long long int
////#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
////#define mem(arr,val)   memset(arr,val,sizeof(arr))
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
////const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
////const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
////int biton(int n,int pos){return n=n|(1<<pos);}
////int bitoff(int n,int pos){return n=n&~(1<<pos);}
////bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
////ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
////ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
////ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
//using namespace std;
//bool mark[mx];
//vector<int>prime;
//vector<pp >jora;
//void sieve(){
//    memset(mark,true,sizeof(mark));
//    mark[0]=mark[1]=false;
//    for(int i=4;i<=mx;i+=2) mark[i]=false;
//    for(int i=3;i<=(int)sqrt(mx);i+=2){
//        if(mark[i]){
//            for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
//        }
//    }
//    prime.push_back(2);
//    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
//}
//int NOD(int n){
//    int sqrtn=sqrt(n);
//    int ans=1;
//    for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
//        int c=0;
//        if(n%prime[i]==0){
//            while(n%prime[i]==0){
//                n/=prime[i];
//                c++;
//            }
//            sqrtn=sqrt(n);
////            cout<<n<<" "<<sqrtn<<" "<<c<<'\n';
//            c++;
//            ans*=c;
//        }
//    }
//    if(n!=1) ans*=2;
//    return ans;
//}
//bool compare(pair<int,int> &a,pair<int,int> &b){
//    if(a.second==b.second){
//        return a.first>b.first;
//    }
//    else{
//        return a.second<b.second;
//    }
//}
//int main(){
////    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
////    ios_base::sync_with_stdio(false); cin.tie(NULL);
//    sieve();
//    for(int i=1;i<=1000;i++){
//        jora.push_back({i,NOD(i)});
//    }
//    sort(jora.begin(),jora.end(),compare);
//    int t; scanf("%d",&t);
//    for(int cs=1;cs<=t;cs++){
//        int n;
//        scanf("%d",&n);
//        printf("Case %d: %d\n",cs,jora[n-1].first);
//    }
//    return 0;
//}
