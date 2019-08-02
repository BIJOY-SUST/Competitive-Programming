#include<bits/stdc++.h>
#define M 55
using namespace std;
map<int,vector<int> >depends;
map<int,int>visited;
map<int,int>taken;
void take( int p ) {
    if( !taken[ p ] ) {
        // i am taking all the items that i should take before p
        for(int i=0; i<depends[p].size(); i++)
            take( depends[p][i] );
        ans.push_back( p ); // now i can take it
        taken[p] = 1;
    }
}

int main() {
    int
    for(int i=0; i<n; i++) take( i );
    for(int i=0; i<n; i++) printf("%d\n", ans[i] );

    return 0;
}
