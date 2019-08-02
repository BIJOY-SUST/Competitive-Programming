#include<bits/stdc++.h>
using namespace std;
bool flag;
class data{
public:
    string name;
    int attack;
    int defend;
};
bool compare(data a,data b){
    if(a.attack==b.attack){
        if(a.defend==b.defend){
            return lexicographical_compare(a.name.begin(),a.name.end(),b.name.begin(),b.name.end());
        }
        else return a.defend<b.defend;
    }
    else return a.attack>b.attack;
}
int main(){
    int T,k=1;
    cin>>T;
    getchar();
    while(T--){
        data p[10];
        for(int i=0;i<10;i++){
            cin>>p[i].name>>p[i].attack>>p[i].defend;
        }
        sort(p,p+10,compare);
        list<string>s;
        list<string>::iterator it;
        cout<<"Case "<<k<<":"<<endl;
        //For attack player...
        for(int i=0;i<5;i++){
            string ss = p[i].name;
            s.push_back(ss);
        }
        s.sort();
        it = s.begin();
        s.pop_front();
        cout<<"(";
        cout<<*it;
        for(it=s.begin();it!=s.end();it++){
            cout<<", "<<*it;
        }
        cout<<")"<<endl;
        //For defend player...
        s.clear();
        for(int i=5;i<10;i++){
            string ss = p[i].name;
            s.push_back(ss);
        }
        s.sort();
        it = s.begin();
        s.pop_front();
        cout<<"(";
        cout<<*it;
        for(it=s.begin();it!=s.end();it++){
            cout<<", "<<*it;
        }
        cout<<")"<<endl;
        k++;
    }
    return 0;
}
