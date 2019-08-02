#include<bits/stdc++.h>
#define mx             10010
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
map<string,vector<string> >conver;
set<string>no,wow;
map<string,int>dekhi;
map<string,int>cnt;
bool comp(const pair<string,int> &a,const pair<string,int> &b){
    if(a.second>b.second){
        return true;
    }
    else if(a.second<b.second){
        return false;
    }
    else{
        return a.first<b.first;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    scanf("%d",&n);
    getchar();
    string name;
    for(int i=1;i<=n;i++){
        string s;
        getline(cin,s);
        stringstream ss(s);
        string word;
        bool flag=true;
        while(ss>>word){
            if(flag) name=word;
            else{
                conver[name].push_back(word);
                cnt[word]++;
                wow.insert(word);
            }
            flag=false;
        }
        no.insert(name);
    }
    for(__typeof(wow.begin())it2=wow.begin();it2!=wow.end();it2++){
        for(__typeof(no.begin())it=no.begin();it!=no.end();it++){
            for(int i=0;i<conver[*it].size();i++){
                if(conver[*it][i]==*it2){
                    dekhi[*it2]++;
//                    cout<<*it2<<endl;
                    break;
                }
            }
        }
    }
    vector<pair<string,int> >mm;
    int lok=no.size();
    for(__typeof(wow.begin())it2=wow.begin();it2!=wow.end();it2++){
        //cout<<*it2<<" "<<dekhi[*it2]<<endl;
        if(dekhi[*it2]==lok){
//            cout<<*it2<<" "<<cnt[*it2]<<endl;
            mm.push_back({*it2,cnt[*it2]});
        }
    }
    if(mm.size()>=1){
        sort(mm.begin(),mm.end(),comp);
        for(int i=0;i<mm.size();i++){
            cout<<mm[i].first<<'\n';
        }
    }
    else{
        cout<<"ALL CLEAR\n";
    }
    return 0;
}
/*
Input:
8
Jepson no no no no nobody never
Ashley why ever not
Marcus no not never nobody
Bazza no never know nobody
Hatty why no nobody
Hatty nobody never know why nobody
Jepson never no nobody
Ashley never never nobody no
Output:

*/
