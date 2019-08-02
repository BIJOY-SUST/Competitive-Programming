#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
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
map<char,int>w;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    w['q'] = 9;
    w['r'] = 5;
    w['b'] = 3;
    w['n'] = 3;
    w['p'] = 1;
    w['k'] = 0;
    string s1,s2="";
    for(int i=1;i<=8;i++){
        cin>>s1;
        s2+=s1;
    }
    int white=0,black=0;
    for(int i=0;i<s2.length();i++){
        if(isupper(s2[i])){
            char ch=tolower(s2[i]);
            white+=w[ch];
        }
        else if(islower(s2[i])){
            black+=w[s2[i]];
        }
    }
    if(white>black) printf("White\n");
    else if(white<black) printf("Black\n");
    else printf("Draw\n");
    return 0;
}
/*

*/
