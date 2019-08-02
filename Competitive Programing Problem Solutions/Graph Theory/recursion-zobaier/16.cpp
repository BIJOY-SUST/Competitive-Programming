#include<bits/stdc++.h>
using namespace std;
void rev(){
    char c;
    scanf("%c",&c);
    //cin>>c;
    if(c!='\n') rev();
    printf("%c",c);
}
int main(){
    rev();
    cout<<endl;
    return 0;
}

