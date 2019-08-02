#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
///    return b==0?a:gcd(b,a%b);
    return (a%b==0)?abs(b):gcd(b,a%b);
}
bool isPossible(int a,int b,int c){
    return (c%gcd(a,b)==0);
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    isPossible(a,b,c)?cout<<"Possible\n":cout<<"Not Possible\n";
    return 0;
}
///Given three integers a, b, c representing a linear equation of the form : ax + by = c.
///Determine if the equation has a solution such that x and y are both integral values.
