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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int a,b;
        scanf("%d : %d",&a,&b);
        double ac=sqrt(a*a+b*b);
        double r=ac/2.0;
        double theta=acos((2*r*r-b*b)/(2*r*r));
        double s=theta*r;
        double x=400.0/((2*a)+(2*s));
        cout<<setprecision(10)<<"Case "<<cs<<": "<<a*x<<" "<<b*x<<'\n';
    }
    return 0;
}
/**
Input:
2
3 : 2
5 : 4

Output:
Case 1: 117.1858168 78.12387792
Case 2: 107.29095604 85.8327648

Solution
মনে করি আয়তটি, ABCD ।
আয়তের প্রস্থের দু পাশে যে দুইটা বৃত্তচাপ আছে, তারা একই বৃত্তের চাপ ।
অতএব, আয়তের কর্ণের দৈর্ঘ্য হবে ঐ বৃত্তের ব্যাস ।



অতএব, AC = sqrt(AD^2 + CD^2)
অতএব, r = OC = OD = AC/2

আমরা জানি, cos A = (b^2 + c^2 - a^2)/2bc
অতএব, cos(theta) = cos COD = (r^2 + r^2 - b^2)/2.r.r
অতএব, s = r.theta

মনে করি, অনুপাতকে x দিয়ে গুণ করলে বাহুর দৈর্ঘ্য পাওয়া যাবে ।

এখন, চাপ = s.x
আয়তের দৈর্ঘ্য = a.x

অতএব, 2.s.x + 2.a.x = 400
অতএব, x = 400 / (2s + 2a)

এখন, আউটপুট হবে a.x এবং b.x

**/
