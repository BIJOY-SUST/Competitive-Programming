#include<bits/stdc++.h>
using namespace std;
struct data{
    char name[100];
    int height, weight;
    long long income;
};
bool compare( data a, data b ) {
    if( a.income == b.income ) {
        if( a.height == b.height ) {
            if( a.weight == b.weight ){
              return strlen( a.name ) < strlen( b.name);
            }
            else return a.weight < b.weight;
        }
        else return a.height > b.height;
    }
    else return a.income > b.income;
}
int main(){
    data s[3];
    for(int i=0;i<3;i++){
        cin>>s[i].name>>s[i].income>>s[i].height>>s[i].weight;
    }
    sort( s, s+3, compare );
    for(int i=0;i<3;i++){
        cout<<s[i].name<<s[i].income<<s[i].height<<s[i].weight<<endl;
    }
    return 0;
}
