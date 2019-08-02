#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
double area(double x1,double y1,double x2,double y2,double x3,double y3){
    return abs(0.5*(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1));
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    double ax[12],ay[12],bx[12],by[12],cx[12],cy[12];
    char ch[12];
    int i=0,no=1;
//    getchar();
    while(1){
        scanf("%s",&ch[i]);
//        cin>>ch[i];
        if(ch[i]=='*') break;
        else if(ch[i]=='r'){
//            cout<<"r"<<endl;
            scanf("%lf%lf%lf%lf",&ax[i],&ay[i],&bx[i],&by[i]);
        }
        else if(ch[i]=='c'){
//            cout<<"c"<<endl;
            scanf("%lf%lf%lf",&ax[i],&ay[i],&bx[i]);
//            cout<<ax[i]<<" "<<ay[i]<< " "<<bx[i]<<endl;
        }
        else if(ch[i]=='t'){
//            cout<<"t"<<endl;
            scanf("%lf%lf%lf%lf%lf%lf",&ax[i],&ay[i],&bx[i],&by[i],&cx[i],&cy[i]);
        }
        //getchar();
        i++;
    }
//    cout<<no<<" "<<i<<endl;
//    cout<<"BIJOY"<<endl;
    while(1){
        double x,y;
        scanf("%lf%lf",&x,&y);
        if(x==9999.9&&y==9999.9) break;
        bool flag=false;
        for(int j=0;j<i;j++){
            if(ch[j]=='r'){
                if(x>ax[j]&&x<bx[j]&&y>by[j]&&y<ay[j]){
                    printf("Point %d is contained in figure %d\n",no,j+1);
                    flag=true;
//                    cout<<"BIJOY "<<no<<" "<<j+1<<endl;
                }
            }
            else if(ch[j]=='c'){
                double d=sqrt((x-ax[j])*(x-ax[j])+(y-ay[j])*(y-ay[j]));
                if(d<bx[j]){
                    printf("Point %d is contained in figure %d\n",no,j+1);
                    flag=true;
                }
            }
            else if(ch[j]=='t'){
                double A=area(ax[j],ay[j],bx[j],by[j],cx[j],cy[j]);
                double A1=area(ax[j],ay[j],bx[j],by[j],x,y);
                double A2=area(x,y,bx[j],by[j],cx[j],cy[j]);
                double A3=area(ax[j],ay[j],x,y,cx[j],cy[j]);
                if((A1+A2+A3+.000005)>A&&(A1+A2+A3-.000005)<A){
                    printf("Point %d is contained in figure %d\n",no,j+1);
                    flag=true;
                }
            }
        }
        if(!flag) printf("Point %d is not contained in any figure\n",no);
        no++;
    }
    return 0;
}
/**
Input:

Output:

**/
