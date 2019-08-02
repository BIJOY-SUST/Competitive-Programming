#include<bits/stdc++.h>
using namespace std;
class data{
public:
    string name;
    int rrr;
};
bool compare(data a,data b){
    if(a.rrr==b.rrr){
        return lexicographical_compare(a.name.begin(),a.name.end(),b.name.begin(),b.name.end());
    }
    else return a.rrr>b.rrr;
}
int main(){
    int t;
    cin>>t;
    map<int,string>m;
    list<string>se;
    for(int j=1;j<=t;j++){
        int n,d;
        cin>>n;
        data ob[n];
        for(int i=0;i<n;i++){
            cin>>ob[i].name>>ob[i].rrr;
        }
        string ss;
        sort(ob,ob+n,compare);
        d=ob[0].rrr;
        ss=ob[0].name;
        if(d>=1&&d<=1199){
            cout<<"Case "<<j<<": "<<ss<<" is Newbie!.\n";
        }
        else if(d>=1200&&d<=1399){
            cout<<"Case "<<j<<": "<<ss<<" is Pupil!.\n";
        }
        else if(d>=1400&&d<=1599){
            cout<<"Case "<<j<<": "<<ss<<" is Specialist!.\n";
        }
        else if(d>=1600&&d<=1899){
            cout<<"Case "<<j<<": "<<ss<<" is Expert!.\n";
        }
    }
    return 0;
}
