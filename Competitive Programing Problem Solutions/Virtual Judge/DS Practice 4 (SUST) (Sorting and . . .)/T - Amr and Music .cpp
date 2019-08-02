/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
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
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
vector<int>v,vv;
map<int,vector<int> >mapping;
map<int,bool>mm;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int h;scanf("%d",&h);
        v.push_back(h);
        mapping[h].push_back(i);
    }
    sort(v.begin(),v.end());
    int ans=0,c=0;
    for(int i=0;i<n;i++){
        if(ans+v[i]<=k){
            ++c;
            ans+=v[i];
            vv.push_back(v[i]);
        }
        else break;
    }
    printf("%d\n",c);
    int kk=0;
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    for(int i=0;i<vv.size()&&kk<c;i++){
        for(int j=0;j<mapping[vv[i]].size()&&kk<c;j++){
            printf("%d ",mapping[vv[i]][j]);
            kk++;
        }
    }
    printf("\n");
    vv.clear();
    v.clear();
    return 0;
}
//        if(mm[v[i]]==false) printf("%d ",mapping[v[i]]);
//        while(mm[v[i]]==true){
//            if(mm[v[i]]==false){
//                mm[v[i]]=true;
//                printf("%d ",mapping[v[i]]);
//                break;
//            }
//            i++;
//        }
