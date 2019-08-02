#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
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
vector<int>arr;
vector<int>man[1001];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k; scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int h; scanf("%d",&h);
        arr.push_back(h);
    }
    vector<int>arr2(arr.begin(),arr.end());
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    n=arr.size();
    for(int i=0;i<n;i++){
        int g=arr[i];
        int m=1;
        while(g>k){
            man[arr[i]].push_back(m);
            g--;
            m++;
            if(m>k) m=1;
        }
        for(int j=1;j<=g;j++){
            man[arr[i]].push_back(j);
        }
    }
//    for(int i=0;i<arr2.size();i++){
//        for(int j=0;j<man[arr2[i]].size();j++){
//            if(j==0) cout<<man[arr2[i]][j];
//            else cout<<" "<<man[arr2[i]][j];
//        }
//        cout<<endl;
//    }
   // vector<pair<int,int> >sum[1001];
   vector<int>sum;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            int ans=0;
            for(int h=0;h<man[arr[j]].size();h++){
                if(man[arr[j]][h]==i) ans++;
            }
            //int ans=upper_bound(man[arr[j]].begin(),man[arr[j]].end(),i)-man[arr[j]].begin();
            //if(i==3) cout<<ans<<endl;
            if(ans!=0) sum.push_back(ans);
            //if(i==2) cout<<ans<<endl;
           // if(man[arr[j]].size()==0) sum.push_back(ans);
        }
        if(arr.size()>sum.size()) sum.push_back(0);
        sort(sum.begin(),sum.end());
        int len=sum.size();
        if(sum[len-1]-sum[0]>1){
            cout<<"NO"<<endl;
            return 0;
        }
        else sum.clear();
    }
    cout<<"YES"<<endl;
    for(int i=0;i<arr2.size();i++){
        for(int j=0;j<man[arr2[i]].size();j++){
            if(j==0) cout<<man[arr2[i]][j];
            else cout<<" "<<man[arr2[i]][j];
        }
        cout<<endl;
    }
   // vector<pair<int,int> >sum[1001];
//    for(int i=1;i<=k;i++){
//        for(int j=0;j<sum[i].size();j++){
//
//            //cout<<sum[i][j].first<< " "<<sum[i][j].second<<" ";
//        }
//        cout<<endl;
//    }
    return 0;
}
/*

*/
