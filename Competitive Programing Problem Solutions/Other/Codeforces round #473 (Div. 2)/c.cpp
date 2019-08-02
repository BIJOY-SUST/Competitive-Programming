#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    long long int node_no;
    cin>>node_no;
    if(node_no==2){
        cout<<"-1"<<endl;
        cout<<"1 2"<<endl;
    }
    else if(node_no==3){
        cout<<"-1"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 3"<<endl;
    }
    else if(node_no==5||node_no==4){
        cout<<"-1"<<endl;
        for(long long int i=2;i<=node_no;i++){
            cout<<"1 "<<i<<endl;
        }
    }
    else{
        long long int k=(node_no/2)+1;
        for(long long int i=2;i<=k;i++){
            cout<<"1 "<<i<<endl;
        }
        for(long long int i=k+1;i<=node_no;i++){
            cout<<"2 "<<i<<endl;
        }
//        cout<<"next"<<endl;
        for(long long int i=2;i<=node_no;i++){
            cout<<"1 "<<i<<endl;
        }
    }
    return 0;
}
/*

*/
