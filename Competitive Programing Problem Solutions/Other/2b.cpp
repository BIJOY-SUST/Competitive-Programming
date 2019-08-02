#include <iostream>

using namespace std;

int main()
{
    int i=0,array[5] = {5,123,5,9,1};
    int temp = 0;

    while(i<5)
    {
        if(array[i]>temp)
        temp=array[i];
        i++;
    }
    cout << "The biggest number is: " << temp << endl;
    return 0;
}
