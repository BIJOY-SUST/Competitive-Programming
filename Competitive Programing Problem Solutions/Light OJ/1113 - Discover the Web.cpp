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
stack<string>ff,bb;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        string s1="",s2="",s3="",s="http://www.lightoj.com/";
        //bb.push(s);
        s3=s;
        cout<<"Case "<<cs<<":\n";
        while(cin>>s1){
            if(s1=="QUIT")
            {
                while(!ff.empty()) ff.pop();
                while(!bb.empty()) bb.pop();
                s3="";
                break;
            }
            else if(s1=="VISIT"){
                cin>>s2;
                if(s3.size()>0) bb.push(s3);
                while(!ff.empty()){
                    ff.pop();
                }
                s3=s2;
                cout<<s3<<'\n';
            }
            else if(s1=="BACK"){
                if(bb.empty()){
                    cout<<"Ignored"<<'\n';
                }
                else{
                    ff.push(s3);
                    s3=bb.top();
                    cout<<s3<<'\n';
                    bb.pop();
                }
            }
            else if(s1=="FORWARD"){
                if(ff.empty()){
                    cout<<"Ignored"<<'\n';
                }
                else{
                    bb.push(s3);
                    s3=ff.top();
                    cout<<s3<<'\n';
                    ff.pop();
                }
            }
        }
    }
    return 0;
}
/*
Input:
1

VISIT http://uva.onlinejudge.org/

VISIT http://topcoder.com/

BACK

BACK

BACK

FORWARD

VISIT http://acm.sgu.ru/

BACK

BACK

FORWARD

FORWARD

FORWARD

QUIT
*/
