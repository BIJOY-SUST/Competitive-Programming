#include<bits/stdc++.h>
using namespace std;
class recipe{
public:
    string name;
    int cost;
};
bool compare(recipe a,recipe b){
    if(a.cost==b.cost){
        return lexicographical_compare(a.name.begin(),a.name.end(),b.name.begin(),b.name.end());
    }
    else return a.cost<b.cost;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s;
        getchar();
        getline(cin,s);
        transform(s.begin(),s.end(),s.begin(),::toupper);
        int m,n,b,h=0;
        recipe List[101];
        map<string,int>store;
        cin>>m>>n>>b;
        for(int i=1;i<=m;i++){
            int c;
            string s1;
            cin>>s1>>c;
            store[s1]=c;
        }
        for(int i=1;i<=n;i++){
            string s2;
            getchar();
            getline(cin,s2);
            int k,ans=0;
            cin>>k;
            for(int j=1;j<=k;j++){
                int x;
                string s3;
                cin>>s3>>x;
                ans+=store[s3]*x;
            }
            if(ans<=b){
                List[h].name=s2;
                List[h].cost=ans;
                h++;
            }
        }
        cout<<s<<"\n";
        if(h==0){
            cout<<"Too expensive!\n";
        }
        else{
            sort(List,List+h,compare);
            for(int i=0;i<h;i++){
                cout<<List[i].name<<"\n";
            }
        }
        //if(T>=1) cout<<"\n";
        cout<<"\n";
    }
    return 0;
}
