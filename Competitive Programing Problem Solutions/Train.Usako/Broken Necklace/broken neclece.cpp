#include<bits/stdc++.h>

using namespace std;
int N;
string s;
int re_plus(int n) {
    if(n<0){
        n+=N;
    }
    n=n%N;
    return n;
}
int total_beads(int initial_beads, int d) {
    int i,j;
    char colour='w';
    if(d==1){
        j=initial_beads;
    }
    else{
        j=initial_beads-1;
        if(j<0){
            j=re_plus(j);
        }
    }
    for(i=0; i<N; i++, j=re_plus(j+d)){
        if(colour=='w' && s[j]!='w'){
            colour=s[j];
        }
        if(colour!='w' && s[j]!='w' && s[j]!=colour){
            break;
        }
    }
    return i;
}

int main() {

    int maximum=0;
    cin>>N;
    cin>>s;
    for(int i=0; i<N; i++){
        maximum=max(total_beads(i, -1)+total_beads(i, 1), maximum);
    }
    if(maximum>N){
        maximum=N;
    }
    cout<<maximum<<endl;
    return 0;
}
