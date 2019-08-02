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
bool comp(string a,string b){
    return a+b<b+a;
//    int d1=min(a.length(),b.length());
//    int d2=max(a.length(),b.length());
//    bool f=false;
//    for(int i=0;i<d1;i++){
//        if(a[i]!=b[i]){
//            f=true;
////            cout<<"BIJOY"<<endl;
//        }
//    }
//    if(f) return a<b;
//    else{
//        //return true;
////        if(a.length()<b.length()) return false;
////        else return true;
//        return a>b;
//    }
    //return lexicographical_compare(a.begin(),a.end(),b.begin(),b.end());
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
    cout<<endl;
    return 0;
}
/**
Input:

Output:

**/
