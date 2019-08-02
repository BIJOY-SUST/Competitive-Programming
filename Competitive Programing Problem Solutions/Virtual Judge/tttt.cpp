#include <iostream>
#include <cmath>
using namespace std;
#define size 1000000
int ara[1000100];
void sieve()
{
    int i,j;
    for(i=1; i<=size; i++){
        ara[0] = 1;
    }
    for(i=2; i<=size; i++){
        if(ara[i]==1){
            for(j=2; i*j<size; j++){
                ara[i*j] = 0;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    sieve();
    while(n--)
    {
        long long x;
        cin >> x;
        long long num = sqrt(x);
        if (num * num == x && ara[num])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
