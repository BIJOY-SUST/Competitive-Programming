int main()
{
    long long int a, b, c;
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++){

    scanf("%lld %lld %lld",&a, &b, &c);

    if((a*a+b*b==c*c) || (a*a+c*c == b*b) || (b*b+c*c == a*a))
    {
        printf("Case %d: yes\n",i);
    }
    else
    {
        printf("Case %d: no\n",i);
    }
    }
    return 0;
}
