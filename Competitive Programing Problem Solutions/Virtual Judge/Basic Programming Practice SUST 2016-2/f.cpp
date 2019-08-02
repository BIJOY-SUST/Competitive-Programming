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
map<char,int>mm;
vector<char>vv;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    scanf("%d",&k);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        mm[s[i]]++;
    }
    if(k>mm.size()){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
        if(mm.size()==1||k==1){
            for(int i=0;i<s.length();i++)
            cout<<s[i];
            cout<<'\n';
            return 0;
        }
        map<char,bool>ff;
        for(char cc='a';cc<='z';cc++) ff[cc]=false;
//        mem(ff,false);
        char ch=s[0];
        ff[ch]=true;
        vv.push_back(s[0]);
        int cnt=1;
        for(int i=1;i<s.size();i++){
            if(ff[s[i]]==true){
                vv.push_back(s[i]);
            }
            else if(!ff[s[i]]){
                cnt++;
                ff[s[i]]=true;
                for(int j=0;j<vv.size();j++){
                    cout<<vv[j];
                }
                cout<<'\n';
                vv.clear();
                vv.push_back(s[i]);
                if(cnt==k){
                    for(int j=i;j<s.length();j++){
                        cout<<s[j];
                    }
                    cout<<'\n';
                    return 0;
                }
            }
        }

    return 0;
}
/*

*/
