#include<bits/stdc++.h>
using namespace std;
class data{
public:
    int choice;
    int HP;
};
bool compare(data a,data b){
//    return a.choice<=b.choice&&a.HP>=b.HP;
    if(a.HP<b.HP){
        return a.choice<b.choice;
    }
    else return a.HP>b.HP;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        data ob[101];
        for(int i=0;i<n;i++){
            cin>>ob[i].choice>>ob[i].HP;
        }
        sort(ob,ob+n,compare);
//        for(int i=0;i<n;i++){
//            cout<<ob[i].choice<<" "<<ob[i].HP<<'\n';
//        }
        int ans=0;
        for(int i=0;i<n;i++){
            //if(m<=0) break;
            if(m>=ob[i].choice) ans+=ob[i].HP;
            else break;
            m-=ob[i].choice;

        }
        printf("%d\n",ans);
    }
    return 0;
}
