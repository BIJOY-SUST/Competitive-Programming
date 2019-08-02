#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
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
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n; scanf("%d",&n);
    while(n--){
        string s,s1="",s2="";
        cin>>s;
        int len=s.length();
        bool flag1=false,flag2=false;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0'&&s[i]<='9'){
                flag1=true;
            }
            else if(flag1) flag2=true;
        }
        if(!flag2){
            ll ans=0,cnt1=0;
            for(int i=0;i<len;i++){
                if(s[i]>='0'&&s[i]<='9') s1+=s[i];
            }
            for(int i=len-1;i>=0;i--){
                if(s[i]>='0'&&s[i]<='9') continue;
                int k=s[i]-'A'+1;
                if(cnt1==0) ans+=k;
                else{
                    while(k--){
                        ll temp=1,cnt2=cnt1;
                        while(cnt2--) temp*=26;
                        ans+=temp;
                    }
                }
                cnt1++;
            }
            cout<<"R"<<s1<<"C"<<ans<<'\n';
        }
        else{
            for(int i=1;i<len;i++){
                if(isupper(s[i])) break;
                s1+=s[i];
            }
            ll ans=0,q=1;
            for(int i=len-1;i>=0;i--){
                if(isupper(s[i])) break;
                if(q==1) ans=s[i]-'0';
                else ans+=((s[i]-'0')*q);
                q*=10;
            }
            bool f=false;
            while(ans>0){
                if(ans%26!=0){
                    s2+=(ans%26)+'A'-1;
//                    ans--;
                }
                if(ans%26==0){
                    s2+='Z';
                    ans/=26;
                    ans--;
                }
                else ans=ans/26;
//                ans--;
            }
            reverse(s2.begin(),s2.end());
            cout<<s2<<s1<<endl;
        }
    }
    return 0;
}
/*
input
2
R23C55
BC23
output
BC23
R23C55
..........................
*/
