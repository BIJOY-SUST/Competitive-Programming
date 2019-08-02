#include<bits/stdc++.h>
#define OVERFLOW 2
#define R   g
#define C g+f+OVERFLOW
using namespace std;
int Car(int n) {
    int carry = 0;
    if(n>=10) {
        while(n!=0) {
            carry = n %10;
            n = n/10;
        }
    }
    else carry = 0;
    return carry;
}

int num(char a) {
    return int(a)-48;
}

string mul(string a, string b) {
        string r;
        int  f= a.length();
        int  g= b.length();
        int m[R][C];
        for(int i =0; i<R; ++i) {
            for(int j=0; j<C; ++j) {
                m[i][j] = 0;

            }
        }

        int carry=0, n,x=f-1,y=g-1;
        for(int i=0; i<R; ++i) {
            x=f-1;
            carry = 0;
            for(int j=(C-1)-i; j>=0; --j) {
                if((x>=0)&&(y>=0))  {
                    n = (num(a[x])*num(b[y]))+carry;
                    m[i][j] = n%10;
                    carry = Car(n);
                }
                else if((x>=-1)&&(y>=-1)) m[i][j] = carry;
                x=x-1;
            }
            y=y-1;
        }

        carry = 0;
        int sum[C];
        for(int i =0; i<C; ++i) sum[i] = 0;
        for(int i=0; i<R; ++i) {
            for(int j=C-1; j>=0; --j) {
                sum[j] += (m[i][j]);
            }
        }
        int t;
        for(int i=C-1; i>=0; --i) {
            sum[i] += carry;
            t = sum[i];
            sum[i] = sum[i]%10;
            carry = Car(t);
        }

        for(int i=0; i<C; ++i) {
            r.push_back(char(sum[i]+48));
        }

        while(r[0]=='0'){
            r = r.substr(1,r.length()-1);
        }
        return r;
}

void printhuge(string a) {
    for(string::iterator i = a.begin(); i!=a.end(); ++i) {
        cout<<*i;
    }
}

int main() {
    string a,b;
    cin>>a>>b;
    printhuge(mul(a,b));
    return 0;
}
