#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
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
int t,n;
int arr[15];
vector<int>v;
vector<int>vv[1001];
bool flag[15];
bool isans;
int c;
void back_t(int i,int ans){
    if(ans==t){
        bool f1=false;
        bool f2=false;
        bool f=false;
        isans=true;

        //cout<<vv.size()<<endl;
        for(int k=0;k<c;k++){
            if(vv[k].size()==v.size()){
                f2=true;
                bool dd=false;
                for(int j=0;j<vv[k].size();j++){
                    if(vv[k][j]!=v[j]){
                        f1=true;
                        dd=true;
                        break;
                    }
                }
                if(dd==false){
                    f1=false;
                    break;
                }
            }
        }
        if(f2==false||(f2==true&&f1==true)){
            f=true;
            //vv.clear();
            printf("%d",v[0]);
            vv[c].push_back(v[0]);
            for(int j=1;j<v.size();j++){
                printf("+%d",v[j]);
                vv[c].push_back(v[j]);
            }
            c++;
        }
        if(f) printf("\n");
    }
    for(int j=i;j<n;j++){
        if(!flag[j]&&ans+arr[j]<=t){
            flag[j]=true;
            v.push_back(arr[j]);
            back_t(j,ans+arr[j]);
            flag[j]=false;
            v.pop_back();
            //v.pop_back(arr[j]);
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);

    while(1){
        scanf("%d %d",&t,&n);
        if(n==0) break;
        memset(flag,false,sizeof(flag));
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        c=0;
        printf("Sums of %d:\n",t);
        isans=false;
        back_t(0,0);
        if(!isans) printf("NONE\n");
        v.clear();
        for(int i=0;i<1001;i++) vv[i].clear();
    }
    return 0;
}
/*
97 12 94 91 63 58 58 50 26 11 10 8 5 2
*/
