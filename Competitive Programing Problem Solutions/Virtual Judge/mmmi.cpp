 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 using namespace std;

 const int maxn = 100 + 5;
 const int INF = 1000 + 5;
int a[maxn];
int main()
 {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE

     int n;
     while (scanf("%d", &n) != EOF)
   {
         for (int i = 1; i <= n; i++)
             scanf("%d", &a[i]);
         int minans = INF;
         for (int i = 2; i <= n-1; i++)
         {
             int maxans = -INF;
            for (int j = 1; j <= n-1; j++)
             {
                 if (i == j)
                     maxans = max(maxans, a[j+1] - a[i-1]);
               else
                     maxans = max(maxans, a[j+1] - a[j]);
             }
             minans = min(minans, maxans);
         }
         printf("%d\n", minans);
     }
     return 0;
 }
