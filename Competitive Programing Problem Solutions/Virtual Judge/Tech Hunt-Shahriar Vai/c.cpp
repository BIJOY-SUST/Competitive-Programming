#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;
bool ques[1001];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int k;
    string s;
    scanf("%d",&k);
    cin>>s;
    int len=s.length();
//    bool flag=false;
    memset(ques,false,sizeof(ques));
    for(int i=0;i<len;i++){
        if(s[i]!='?'){
            if(s[len-1-i]=='?') s[len-1-i]=s[i];
            else if(s[i]!=s[len-1-i]){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int i=0;i<len;i++) ques[(int)s[i]]=true;
    int j='a'+k-1;
    for(int i=(len-1)/2;i>=0;i--){
        while(j>='a'&&ques[j]) --j;
        if(s[i]!='?') continue;
        if(j>='a') s[len-1-i]=s[i]=j--;
        else s[len-1-i]=s[i]='a';
    }
    while(j>='a'&&ques[j]) --j;
    if(j>='a'){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else{
        cout<<s<<'\n';
    }
    return 0;
}
/**
16
?bc??f?hi?k??n??hb??liiglal???npi???b???p?n?j?al????j???ponmlkjih??e??b?
*/






































































//#include<bits/stdc++.h>
////#define mx             100001
////#define mod            1000000007
////#define pi             2*acos(0.0)
////#define p              pair<int,int>
////#define ll             long long int
////#define one(n)         __builtin_popcount(n)
////#define ull            unsigned long long int
////#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
////const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
////const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
////int biton(int n,int pos){return n=n|(1<<pos);}
////int bitoff(int n,int pos){return n=n&~(1<<pos);}
////bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//using namespace std;
//int k;
//string s;
//bool vis[1001];
////void sieve(char ch1,char ch2){
////    for(char ch='a';ch<='a'+k;ch++){
////
////    }
////}
//int main(){
////    freopen("Input.txt","r",stdin);
////    freopen("Output.txt","w",stdout);
////    int k;
//    scanf("%d",&k);
////    string s;
//    cin>>s;
//    int len=s.length();
//    bool flag=false;
//    memset(vis,false,sizeof(vis));
//    int c=0;
//    for(int i=0;i<(len+1)/2;i++){
//        if(s[i]=='?'&&s[len-1-i]=='?'){
//            c++;
//        }
//    }
//    for(int i=0;i<(len+1)/2;i++){
//            int kk=k;
//            for(char cc='a';cc<='a'+k-1;cc++){
//                if(vis[cc]){
//                    kk--;
//                }
//            }
//            if(kk>c){
//                flag=true;
//                break;
//            }
//        if(islower(s[i])&&islower(s[len-1-i])&&s[i]==s[len-1-i]){
//            vis[s[i]]=true;
//            continue;
//        }
//        else if(islower(s[i])&&islower(s[len-1-i])&&s[i]!=s[len-1-i]){
//            flag=true;
//            break;
//        }
//        else if(!islower(s[i])&&islower(s[len-1-i])){
//            s[i]=s[len-1-i];
//            vis[s[i]]=true;
//        }
//        else if(islower(s[i])&&!islower(s[len-1-i])){
//            s[len-1-i]=s[i];
//            vis[s[i]]=true;
//        }
//        else if(!islower(s[i])&&!islower(s[len-1-i])){
//            int kk=k;
//            for(char cc='a';cc<='a'+k-1;cc++){
//                if(vis[cc]){
//                    kk--;
//                }
//            }
//            if(kk>c){
//                flag=true;
//                break;
//            }
//            bool f=false;
//            bool ff=false;
////            if(i!=0){
//            char aaa='a';
//            if(c>=k){
//                s[i]=aaa;
//                s[len-1-i]=aaa;
//                ff=true;
//                c--;
//            }
////            }
//            else if(!ff){
//                for(char ch='a';ch<='a'+k-1;ch++){
//                    if(!vis[ch]){
//                        s[i]=ch;
//                        s[len-1-i]=ch;
//                        vis[ch]=true;
//                        f=true;
//                        break;
//                    }
//                }
//            }
//            if(f==false){
//                s[i]='a';
//                s[len-1-i]='a';
//                char ch='a';
//                vis[ch]=true;
//            }
//        }
//    }
//    if(!flag){
//        cout<<s<<'\n';
//    }
//    else{
//        cout<<"IMPOSSIBLE\n";
//    }
//    return 0;
//}

