#include <iostream>
using namespace std;

int main() {
    int n  ;
    cin>>n;
    int bag=n*n;

int c=0 ;
if (n==2)
{
        cout<<1<<" "<<4<<endl;

        cout<<2<<" "<<3 ;
    return 0 ;

}
    for(int j=0;j<=(n*n/2-1);j++)
    {


        cout<<j+1<<" ";
        cout<<bag-j<<" " ;
        c+=2 ;
        if(c==n)
        {cout<<endl; c=0 ;}




    }

    return 0;
}
