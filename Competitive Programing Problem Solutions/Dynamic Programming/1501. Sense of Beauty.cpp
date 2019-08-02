/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             1000001
//#define mod            100000007
//const long long inf =  1e15;
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,c1=0,c2=0;
    scanf("%d",&n);
    string s1,s2;
    string s3="";
    cin>>s1>>s2;
    bool flag=true;
    for(int i=0;i<n;i++){
        if(c1==2||c2==2){
            flag=false;
            break;
        }
        if(s1[i]=='0'&&s1[i]==s2[i]){
            c1++;
            s3+="22";
        }
        else if(s1[i]=='1'&&s1[i]==s2[i]){
            c2++;
            s3+="11";
        }
        else if(s1[i]=='0'&&s1[i]!=s2[i]){
            c1--;
            c2--;
            s3+="12";
        }
        else{
            c1--;
            c2--;
            s3+="21";
        }
    }
    if(flag) cout<<s3<<'\n';
    else cout<<"Impossible"<<'\n';
    return 0;
}
