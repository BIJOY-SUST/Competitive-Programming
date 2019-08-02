#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    map<string,int>mymap;
    int edge,assign=0;
    cin>>edge;
    for(int i=0;i<edge;i++){
        string s1,s2;
        cin>>s1>>s2;
        if(mymap.find(s1)==mymap.end()){
            printf("Maping %s with %d\n",s1.c_str(),assign);
            mymap[s1]=assign++;
        }
        if(mymap.find(s2)==mymap.end()){
            printf("Maping %s with %d\n",s2.c_str(),assign);
            mymap[s2]=assign++;
        }
        int u=mymap[s1];
        int v=mymap[s2];
        printf("Edge: %d %d\n",u,v);
    }
    return 0;
}
