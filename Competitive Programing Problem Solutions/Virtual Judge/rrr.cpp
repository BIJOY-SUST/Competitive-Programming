#include
int main()
{
int n,k,i,j,c=0,temp,p[50],t[50];
scanf("%d%d",&n,&k);
for(i=0;i scanf("%d%d",&p[i],&t[i]);
for(i=0;i for(j=i+1;j if(p[i]t[j])){
temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=t[i];
t[i]=t[j];
t[j]=temp;
}
}
}
for(i=0;i if(p[i]==p[k-1] && t[i]==t[k-1])
c++;
}
printf("%d",c);
return 0;
}
