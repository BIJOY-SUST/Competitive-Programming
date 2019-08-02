#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define p              pair<int,int>
//#define ll             long long int
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
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;
vector<int>v1,v2;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;scanf("%d",&k);
        v1.push_back(k);
        v2.push_back(k);
    }
    sort(v1.begin(),v1.end());
    int c=0;
//    vector<p >pp;
    int u=0,v=0;
    for(int i=0;i<n;i++){
        if(v1[i]!=v2[i]&&c==0){
//            pp.push_back(make_pair(v1[i],v2[i]));
            u=i;
            c++;
        }
        else if(v1[i]!=v2[i]&&c>0){
            v=i;
        }
    }
//    cout<<u<<" "<<v<<endl;
    reverse(v2.begin()+u,v2.begin()+v+1);
//    for(int i=0;i<n;i++) printf("%d ",v2[i]);
    bool flag=true;
    for(int i=u;i<=v;i++){
        if(v1[i]!=v2[i]){
            flag=false;
            break;
        }
    }
    if(c==0){
        printf("yes\n");
        printf("1 1\n");
    }
    else if(flag){
        printf("yes\n");
        printf("%d %d\n",u+1,v+1);
    }
    else{
        printf("no\n");
    }
    return 0;
}
/*

*/
