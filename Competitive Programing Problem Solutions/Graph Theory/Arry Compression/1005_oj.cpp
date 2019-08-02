#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        string s1,s2;
        bool flag = true;
        map<string,int>mymap;
        int edge,assign=0;
        cin>>edge;
        for(int j=1;j<=edge;j++){
            cin>>s1>>s2;
            //if(mymap.find(s1)==mymap.end()){
                //mymap[s1]=assign++;
                mymap[s1]++;
            //}
            //if(mymap.find(s2)==mymap.end()){
                //mymap[s2]=assign++;
                mymap[s2]++;
           // }
            int u=mymap[s1];
            int v=mymap[s2];
            if(u>v){
                flag=false;
                break;
            }
        }
        if(flag==false){
            cout<<"Case "<<i<<": No"<<"\n";
        }
        else{
            cout<<"Case "<<i<<": Yes"<<"\n";
        }
    }
    return 0;
}
