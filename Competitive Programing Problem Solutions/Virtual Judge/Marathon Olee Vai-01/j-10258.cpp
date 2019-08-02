#include<bits/stdc++.h>
using namespace std;
int solve[101];
int penalty[101];
int idstore[101];
int check[101][101];
bool idcheck[101];
bool solvecheck[101][101];
class contest{
public:
    int id;
    int solve;
    int panalty;
};
bool compare(contest a,contest b){
    if(a.solve==b.solve){
        if(a.panalty==b.panalty){
            return a.id<b.id;
        }
        else return a.panalty<b.panalty;
    }
    else return a.solve>b.solve;
}
int main(){
    //freopen("j1.txt","r",stdin);
    //freopen("j2.txt","w",stdout);
    int T;
    cin>>T;
    getchar();
    getchar();
    while(T--){
        memset(solve,0,sizeof(solve));
        memset(penalty,0,sizeof(penalty));
        memset(idstore,0,sizeof(idstore));
        memset(check,0,sizeof(check));
        memset(idcheck,false,sizeof(idcheck));
        memset(solvecheck,false,sizeof(solvecheck));
        int c=0;
        string s;
        while(getline(cin,s)){
            if(s.empty()) break;
            int id,no,time;
            char ch;
            stringstream ss;
            ss.clear();
            ss<<s;
            ss>>id>>no>>time>>ch;
            //cout<<id<<no<<time<<ch<<endl;
            if(!idcheck[id]){
                idcheck[id]=true;
                idstore[c]=id;
                c++;
            }
            if(ch=='C'&&!solvecheck[id][no]){
                solve[id]++;
                penalty[id]=penalty[id]+time+check[id][no];
                solvecheck[id][no]=true;
            }
            else if(ch=='I'&&!solvecheck[id][no]){
                check[id][no]=check[id][no]+20;
            }
        }
        contest ob[101];
        for(int i=0;i<c;i++){
            if(idcheck[idstore[i]]){
                ob[i].id=idstore[i];
                ob[i].solve=solve[idstore[i]];
                ob[i].panalty=penalty[idstore[i]];
                //cout<<ob[i].id<<" "<<ob[i].solve<<" "<<ob[i].panalty<<'\n';
            }
        }
        sort(ob,ob+c,compare);
        for(int i=0;i<c;i++){
            cout<<ob[i].id<<" "<<ob[i].solve<<" "<<ob[i].panalty<<'\n';
        }
        if(T) cout<<'\n';
    }
    return 0;
}
