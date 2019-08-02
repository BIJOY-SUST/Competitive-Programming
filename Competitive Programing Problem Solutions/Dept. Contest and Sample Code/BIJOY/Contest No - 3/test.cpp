#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             10000010
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
vector<int>v;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        sum+=k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    int ans=-1;
    vector<int>mm;
    if(sum%10!=0){
        printf("%d\n",sum);
    }
    else{
        bool flag=false;
        for(int i=0;i<n;i++){
            if((sum-v[i])%10!=0){
                printf("%d\n",sum-v[i]);
                flag=true;
                break;
            }

        }
        if(!flag){
            cout<<"0"<<endl;
        }
        //printf("0\n");
    }
//    if(mm.size()>0){
//        sort(mm.begin(),mm.end());
//        int l=mm.size();
//        cout<<mm[l-1]<<endl;
//    }
//    else{
//        cout<<0<<endl;
//    }
    return 0;
}

