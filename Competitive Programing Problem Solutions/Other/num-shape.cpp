#include <iostream>


using namespace std;

int main()
{
    unsigned i,k=0,n;
    cout<<"n= "; cin>>n;

    while(k<=n)
        {

            for (i=0;i<=k;i++)
                cout<<i;
            for (i=k;i>0;i--)
                cout<<i-1;
            cout<<endl;
            k++;
        }

    k=n;

    while (k)
        {
            k--;
            for (i=0;i<=k;i++)
                cout<<i;
            for (i=k;i>0;i--)
                cout<<i-1;
            cout<<endl;

        }

}
