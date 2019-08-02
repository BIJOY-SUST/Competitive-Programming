#include<bits/stdc++.h>
using namespace std;
class contest{
public:
    int tn,ps[11],pt,s,p,t[11];
}ob[103];
bool compare(contest a,contest b){
    if(a.p==b.p){
        if(a.pt==b.pt){
            return a.tn<b.tn;
        }
        else return a.pt<b.pt;
    }
    else return a.p>b.p;
}
int main(){
    //freopen("j1.txt","r",stdin);
    //freopen("j2.txt","w",stdout);
    int T;
    int z=0;
    cin>>T;
    getchar();
    getchar();
    while(T--){
        for(int i=0;i<=102;i++){
            ob[i].tn=i;
            ob[i].s=0;
            ob[i].p=0;
            ob[i].pt=0;
            memset(ob[i].ps,0,sizeof(ob[i].ps));
            memset(ob[i].t,0,sizeof(ob[i].t));
        }
        string s;
        while(getline(cin,s)&&s.size()){
            int id,no,time;
            char ch;
            stringstream ss(s);
            //ss.clear();
            //ss<<s;
            ss>>id>>no>>time>>ch;
            ob[id].s=1;
            //cout<<id<<no<<time<<ch<<endl;
            if(ch=='C'&&ob[id].ps[no]==0){
                ob[id].ps[no]=true;
                ob[id].pt=ob[id].pt+time+ob[id].t[no];
                ob[id].p++;
                ob[id].t[no]=0;
            }
            else if(ch=='I'&&ob[id].ps[no]==0){
                ob[id].t[no]+=20;
            }
        }
        sort(ob,ob+103,compare);
        if(z) cout<<'\n';
        z=1;
        for(int i=0;i<=102;i++){
            if(ob[i].s){
                cout<<ob[i].tn<<" "<<ob[i].p<<" "<<ob[i].pt<<'\n';
            }
        }
    }
    return 0;
}
