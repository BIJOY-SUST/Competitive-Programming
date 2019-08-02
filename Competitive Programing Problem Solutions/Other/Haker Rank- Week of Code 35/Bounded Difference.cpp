#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;
vector<ll>v1,v2;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        ll h;scanf("%lld",&h);
        v1.push_back(h);
    }
    v2=v1;
    vector<ll>s;
    sort(v1.begin(),v1.end());
//    for(int i=0;i<n;i++){
//        printf("%d\n",v1[i]);
//    }
    bool flag=true,f=true;
    for(int i=0;i<n;i++){
        if(i==0){
            if(flag&&v1[i]!=v2[i]){
                s.push_back(i+1);
                int m;
                for(int j=0;j<n;j++){
                    if(v2[i]==v1[j]){
                        m=j;
                        break;
                    }
                }
                //cout<<i+1<<" "<<m+1<<endl;
                s.push_back(m+1);
                flag=false;
            }
        }
        else if(v1[i]-v1[i-1]<=k){
            if(flag&&v1[i]!=v2[i]){
                s.push_back(i+1);
                int m;
                for(int j=0;j<n;j++){
                    if(v2[i]==v1[j]){
                        m=j;
                        break;
                    }
                }
                //cout<<i+1<<" "<<m+1<<endl;
                s.push_back(m+1);
                flag=false;
            }
        }
        else{
            f=false;
            break;
        }
    }
    if(f&&flag) printf("0\n");
    else if(f&&flag==false) printf("%lld %lld\n",s[0],s[1]);
    else if(f==false) printf("-1");
    return 0;
}
/*

*/

