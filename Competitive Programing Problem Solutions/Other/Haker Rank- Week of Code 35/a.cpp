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
vector<pair<ll,string> >ans;
//bool compare(pair<ll,string>&a,pair<ll,string>&b){
//    return a.first<b.first;
//}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s;
        ll price;
        cin>>s>>price;
        ll pp=price;
        stringstream ss;
        ss<<price;
        string s2=ss.str();
//        cout<<s<<" "<<s2<<'\n';
        int four=0,seven=0;
        bool flag=false,f1=false,f2=false;
        //cout<<s2<<" "<<s2.length()<<endl;
        int len=s2.length();
        if(len%2==0){
            for(int i=0;i<s2.length();i++){
                //cout<<s2[i]<<" "<<endl;
                if(s2[i]=='4'||s2[i]=='7'){
                    if(s2[i]=='4'){
                        four++;
                        f1=true;
                    }
                    else if(s2[i]=='7'){
                        seven++;
                        f2=true;
                    }
                }
                else{
                    flag=true;
                    break;
                }
            }
        }
        if(flag==false&&f1==true&&f2==true&&four==seven){
            ans.push_back(make_pair(pp,s));
        }
    }
    if(ans.size()){
        sort(ans.begin(),ans.end());
        cout<<ans[0].second<<'\n';
    }
    else{
        printf("-1\n");
    }
    return 0;
}
/*

*/
