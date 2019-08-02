#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
vector<string>v;
vector<pair<int,pair<int,string> > >mp;
//bool comp(const pair<string,int> &a,const pair<string,int> &b){
//    if(a.second>b.second) return a.second<b.second;
//}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<v[i].size()-1;j++){
                for(int k=j+1;k<v[i].size();k++){
                    if(v[i][k]<v[i][j]){
                        cnt++;
//                        swap(v[i][k],v[i][j]);
                    }
                }
            }
//            mp[v[i]]=cnt;
            mp.push_back({cnt,{i,v[i]}});
//            cout<<v[i]<<" "<<cnt<<endl;
        }
//        vector<pair<string,int> >vv(mp.begin(),mp.end());
        sort(mp.begin(),mp.end());

        for(auto it = mp.begin();it!=mp.end();it++){
            cout<<(*it).second.second<<'\n';
        }
        if(t) cout<<'\n';
        mp.clear();
        v.clear();
    }
    return 0;
}
/*
Input:

Output:

*/
