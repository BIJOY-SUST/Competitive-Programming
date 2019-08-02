#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >sol;
bool isValidSolution(int a,int b,int c,int p,int divisor){
    if(((divisor-c)%a)!=0) return false;//x = (div - c) / a
    if(((p-b*divisor)%(a*divisor))!=0) return false;// y = (p-b*div)
    sol.push_back(make_pair((divisor-c)/a,(p-b*divisor)/(a*divisor)));
//    cout<<divisor<<'\n';
    return true;
}
int hyperbolicDiophantine(int a,int b,int c,int d){
    int p=a*d+b*c;
    if(p==0){
        if(-c%a==0) return -1;///Infinite Solution (-c/a,k)
        else if(-b%a==0) return -1;///Infinite Solution(k,-b/a)
        else return 0;///NO Solution
    }
    else{
        int sqrtn=sqrt(p),ans=0;
        for(int i=1;i<=sqrtn;i++){
            if(p%i==0){
                //Check if divisors i,-i,p/i,-p/i produces valid solutions
                if(isValidSolution(a,b,c,p,i)) ans++;
                if(isValidSolution(a,b,c,p,-i)) ans++;
                if(p/i!=i){
                    if(isValidSolution(a,b,c,p,p/i)) ans++;
                    if(isValidSolution(a,b,c,p,-p/i)) ans++;
                }
            }
        }
        return ans;
    }
}
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int ans=hyperbolicDiophantine(a,b,c,d);
    printf("%d\n",ans);
    for(int i=0;i<ans;i++){
        cout<<sol[i].first<<" "<<sol[i].second<<'\n';
    }
    return 0;
}
