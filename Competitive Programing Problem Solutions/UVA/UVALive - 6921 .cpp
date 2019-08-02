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
double dhal(double x1,double y1,double x2,double y2){
    return (y2-y1)/(x2-x1);
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        double w,h,x,x1,y1,mew;
        cin>>w>>h>>x>>x1>>y1>>mew;
        double upor,nij;
        upor=dhal(w,h,x1,y1);
        nij=dhal(w,h,x,0);
        if(upor>=nij) printf("0.0000\n");
        else{
            double uu=dhal(h,w,y1,x1);
            double r=atan(uu);
            double vv=sin(r)/mew;
            double i=asin(vv);
            double hh=(x1-x-y1*tan(r))/(tan(i)-tan(r));
            if(hh>h) printf("Impossible\n");
            else printf("%.4f\n",hh);
        }
    }
    return 0;
}
/*
Sample Input
2
100 150 30 200 200 3.0000
100 150 30 200 200 2.0000
Sample Output
136.2840
Impossible
*/
