# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>

using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(x)      for(__typeof(x.begin()) it=(x.begin());it!=(x.end());++it)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double a[mx];
int boss(double mid,int n,int m){
    int d=0;
    for(int i=0;i<n;i++){
        d+=(int)(a[i]/mid);
    }
//    cout<<d<<endl;
    if(d<=m) return 0;
    else return 1;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n,m;
        scanf("%d%d",&n,&m);
        double l=0,r=-1,mid;
        for(int i=0;i<n;i++){
            scanf("%lf",&a[i]);
            a[i]=a[i]*a[i]*PI;
            if(r<a[i]) r=a[i];
        }
//        for(int i=0;i<n;i++) cout<<a[i]<<" ";
//        cout<<endl;
//        cout<<r<<" "<<l<<endl;
        while((r-l)>.001){
            mid=(l+r)/2;
//            cout<<mid<<endl;
            if(boss(mid,n,m)) l=mid;
            else r=mid;
        }
        printf("%.4f\n",mid);
    }
    return 0;
}
