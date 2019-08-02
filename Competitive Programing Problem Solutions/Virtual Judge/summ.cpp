#include<bits/stdc++.h>

using namespace std;
int main() {
    unsigned long long int T, n, res;
    cin>>T;
    while(T--){
        res=0;
        cin>>n;
        n = n%1000000007;
        res = (n*n)%1000000007;
        cout<<res<<endl;
    }
    return 0;
}
/*
Sn≡n∑k=1Tn(modm)≡n∑k=1(k2−(k−1)2)(modm)≡n∑k=1(k2−(k2−2k+1))(modm)≡n∑k=1(2k−1)(modm)≡2n∑k=1k−n(modm)≡n(n+1)−n(modm)≡n2(modm)≡(nmodm)(nmodm)(modm)
*/
