#include<bits/stdc++.h>
using namespace std;
bool flag[101][101];
//map<int,int>_no;
int _no[101];
int _time[101];
//map<int,int>_time;
set<int>v;
class contest{
public:
    int iid;
    int score;
    int solve;
};
bool compare(contest a,contest b){
    if(a.solve==b.solve){
        if(a.score==b.score){
            return a.iid<b.iid;
        }
        return a.score<b.score;
    }
    else return a.solve>b.solve;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    freopen("j1.txt","r",stdin);
    freopen("j2.txt","w",stdout);
    int T;
    stringstream ss;
    string s;
    cin>>T;
    while(T--){
        getchar();
        cout<<'\n';
        memset(flag,false,sizeof(flag));
        memset(_no,0,sizeof(_no));
        memset(_time,0,sizeof(_time));

        contest ob[101];
        while(getline(cin,s)){
            if(s.empty()) break;
            int id,no,time;
            char ch;
            ss.clear();
            ss<<s;
            ss>>id>>no>>time>>ch;
            if(ch=='C'&&flag[id][no]==false){
                v.insert(id);
                _no[id]++;
                _time[id]+=time;
                flag[id][no]=true;
            }
            else if(ch=='I'&&flag[id][no]==false){
                _time[id]+=20;
                v.insert(id);
            }
        }
        int h=0;
        for(__typeof(v.begin()) it=v.begin();it!=v.end();it++){
            //cout<<*it<<" "<<_no[*it]<<" "<<_time[*it]<<'\n';
            ob[h].iid=*it;
            ob[h].solve=_no[*it];
            ob[h].score=_time[*it];
            h++;
        }
        sort(ob,ob+h,compare);
        for(int i=0;i<h;i++){
            cout<<ob[i].iid<<" "<<ob[i].solve<<" "<<ob[i].score<<'\n';
        }
        v.clear();
    }
    return 0;
}
