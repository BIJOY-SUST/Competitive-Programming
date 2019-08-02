/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             1000001
//#define mod            100000007
//const long long inf =  1e15;
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int biton(int N,int pos){return N=N(1<<pos);}
//int bitoff(int N,int pos){return N=N&~(1<<pos);}
//bool check(int N,int pos){return (bool)(N&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
map<string,int>v,vv;
vector<pair<string,int> >vs;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    v.clear();
    vv.clear();
    int n,m=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s;
        int w;
        cin>>s>>w;
        vs.push_back(make_pair(s,w));
        v[s]+=w;

    }
    for(int i=0;i<n;i++){
        if(v[vs[i].first]>m) m=v[vs[i].first];
    }
    string ans;
    for(int i=0;i<n;i++){
        vv[vs[i].first]+=vs[i].second;
        //cout<<v[vs[i].first]<<" "<<m<<" "<<vs[i].first<<" "<<vv[vs[i].first]<<endl;
        if(v[vs[i].first]==m&&vv[vs[i].first]>=m){
            //cout<<"BIJOY"<<endl;
            ans=vs[i].first;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
//5
//kaxqybeultn -352
//mgochgrmeyieyskhuourfg -910
//kaxqybeultn 691
//mgochgrmeyieyskhuourfg -76
//kaxqybeultn -303



















///*
//BIJOY
//CSE-25th Batch
//Shahjalal University of Science and Technology
//*/
//#include<bits/stdc++.h>
////#define pi             3.141592653589793238462643383
////#define pi             2*acos(0.0)
////#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
////#define ll             long long int
////#define llu            unsigned long long int
////#define mx             1000001
////#define mod            100000007
////const long long inf =  1e15;
///*----------------------Graph Moves------------------*/
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
////const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
////const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
///*---------------------------------------------------*/
///*-----------------------Bitmask---------------------*/
////int biton(int N,int pos){return N=N(1<<pos);}
////int bitoff(int N,int pos){return N=N&~(1<<pos);}
////bool check(int N,int pos){return (bool)(N&(1<<pos));}
///*---------------------------------------------------*/
//using namespace std;
//map<string,int>v;
//map<string,int>vv;
//class struc{
//public:
//    string s;
//    int value;
//};
//int main(){
////    freopen("Input.txt","r",stdin);
////    freopen("Output.txt","w",stdout);
//    struc ob[1001];
//    v.clear();
//    int n,m=0;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        cin>>ob[i].s>>ob[i].value;
//        v[ob[i].s]+=ob[i].value;
//        if(v[ob[i].s]>m){
//            m=v[ob[i].s];
//        }
//    }
//    //cout<<m<<endl;
//    string ans="";
//    //int h=0;
//    for(int i=0;i<n;i++){
//        vv[ob[i].s]+=ob[i].value;
//        if(v[ob[i].s]==m&&vv[ob[i].s]>=m){
//            //cout<<++h<<endl;
//            ans=ob[i].s;
//            break;
//        }
//    }
//    cout<<ans<<endl;
//    return 0;
//}
