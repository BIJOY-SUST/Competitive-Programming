#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
struct data{
    int w,s,no;
    bool operator<(const data &p)const{
        return s>p.s;
    }
};
vector<data>val;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a,b;
    data ob;
    int cnt=0;
    while(scanf("%d%d",&a,&b)==2&&a!=EOF){
        ob.w=a; ob.s=b;
        ob.no=++cnt;
        val.push_back(ob);
    }
    sort(val.begin(),val.end());
//    for(int i=0;i<val.size();i++){
//        cout<<val[i].w<<" "<<val[i].s<<endl;
//    }
    vector<int>par(val.size(),-1),level(val.size(),1);
    int sum=0,st;
    for(int i=1;i<val.size();i++){
        for(int j=0;j<i;j++){
            if(val[j].w<val[i].w&&val[j].s>val[i].s){
                if(level[i]<level[j]+1){
                    level[i]=level[j]+1;
                    par[i]=j;
                }
            }
        }
        if(sum<level[i]){
            sum=level[i];
            st=i;
        }
    }
    printf("%d\n",sum);
    vector<int>ans;
    while(par[st]!=-1){
        //printf("%d\n",val[st].no);
        ans.push_back(val[st].no);
        st=par[st];
    }
    ans.push_back(val[st].no);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        printf("%d\n",ans[i]);
    }
    //printf("%d\n",val[st].no);
    return 0;
}
/*

*/
