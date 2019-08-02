#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        int i=a,j=b;
        if(a>b){
            swap(a,b);
        }
        int d,m_d = 0;
        while(a<=b){
            int n = a;
            d=1;
            while(n!=1){
                if(n%2==1){
                    n = 3 * n + 1;
                }
                else{
                    n /= 2;
                }
                d++;
            }
            if(d>m_d){
                m_d = d;
            }
            a++;
        }
        cout<<i<<" "<<j<<" "<<m_d<<endl;
    }
    return 0;
}
