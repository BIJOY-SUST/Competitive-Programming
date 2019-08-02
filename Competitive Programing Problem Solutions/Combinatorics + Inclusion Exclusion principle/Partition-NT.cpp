#include <iostream>
#include <vector>

using namespace std;

void print (vector<int>& v, int level){
    for(int i=0;i<=level;i++)
        cout << v[i] << " ";
    cout << endl;
}

void part(int n, vector<int>& v, int level){
    int first; /* first is before last */

    if(n<1) return ;
    v[level]=n;
    print(v, level);

    first=(level==0) ? 1 : v[level-1];

    for(int i=first;i<=n/2;i++){
        v[level]=i; /* replace last */
        part(n-i, v, level+1);
    }
}

int main(){
    int N;
    cout << "input number:";
    cin >> N;

    vector<int> v(N);

    part(N, v, 0);
}
/*
int p (int n, int m)
{
    if (n == m)
        return 1 + p(n, m - 1);
    if (m == 0 || n < 0)
        return 0;
    if (n == 0 || m == 1)
        return 1;

    return p(n, m - 1) + p(n - m, m);

}
/
