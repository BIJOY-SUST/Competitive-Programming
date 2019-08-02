#include<bits/stdc++.h>
using namespace std;
/*class data{
public:
    string name;
    int rrr;
};
*/bool compare(string a,string b){
        return lexicographical_compare(a.begin(),a.end(),b.begin(),b.end());
}
int main(){
    int t;
    cin>>t;
    map<int,string>m;
    vector<string>se;
    for(int j=1;j<=t;j++){
        int n,d=0,c=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            string s;
            int rat;
            cin>>s>>rat;
            m[rat]=s;
            if(rat>d){
                d=rat;
                se.push_back(s);
            }
            else if(rat==d){
                c++;
                se.push_back(s);
            }
        }
        string ss;
        if(c==0){
            ss=m[d];
        }
        else{
            sort(se.begin(),se.end(),compare);
            ss=se[0];
        }
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
        se.clear();
        m.clear();
    }
    return 0;
}
