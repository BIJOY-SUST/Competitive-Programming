int main () {
    srand(time(NULL));
    LL n,m,k;
    SLLL(n,m,k);
    if ((n*m*2)%k != 0)
    {
        puts("NO");
        return 0;
    }
    LL T = (n*m*2)/k;  //two times area
    LL nn=n,mm=m;
    LL tmp = __gcd(n,k);
    n/=tmp, k/=tmp;
    tmp = __gcd(m,k);
    m/=tmp, k/=tmp;
    puts("YES");
    if (k == 2)
    {
        cout << 0 << ' ' << 0 <<endl;
        cout <<n << ' ' << 0 <<endl;
        cout << 0 << ' ' << m <<endl;
    }
    else if (n*2 <= nn)
    {
        cout << 0 << ' ' << 0 <<endl;
        cout << 2*n << ' ' << 0 << endl;
        cout << 0 << ' ' << m << endl;
    }
    else if (2*m <= mm)
    {
        cout << 0 << ' ' << 0 <<endl;
        cout <<n << ' ' << 0 <<endl;
        cout << 0 << ' ' << 2*m <<endl;
    }
    else if (k == 2)
    {
        cout << 0 << ' ' << 0 <<endl;
        cout <<n << ' ' << 0 <<endl;
        cout << 0 << ' ' << m <<endl;
    }
    else assert(0);
}
