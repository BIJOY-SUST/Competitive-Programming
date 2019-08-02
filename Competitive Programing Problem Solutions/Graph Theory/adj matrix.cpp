int N;
int matrix[100][100]; //এই সর্বোচ্চ ১০০ নোডের গ্রাফ স্টোর করা যাবে।

//ডিক্লেয়ার করার পরে ইনপুট নেবার পালা। খুব সহজ কাজ:
scanf("%d",&N);
for(int i=1;i<=N;i++)
for(int j=1;j<=N;j++)
scanf("%d" ,&matrix[i][j]);










int Node,Edge;
int matrix[100][100];
scanf("%d%d",&Node,&Edge);
for(i=0;i<Edge;i++)
{
int n1,n2,cost;
scanf("%d%d%d",&n1,&n2,&cost);
matrix[n1][n2]=cost;
matrix[n2][n1]=cost;
}
