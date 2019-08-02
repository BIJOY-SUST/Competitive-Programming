#include<stdio.h>
#include<math.h>
int Prime(int n){
    int i,sqrt_n,flag=1;
    sqrt_n=(int)sqrt(n);
    sqrt_n++;
    if(n<2){
        return 0;
    }
    else{
        if(n==2){
            return 1;
        }
        else if(n%2==0){
        return 0;
        }
    }
    for(i=3;i<sqrt_n;i=i+2){
        if(n%i==0){
            flag=0;
            break;
        }
    }
    return flag;
}
int main(){
        int count=1;
        int i,n;
        while(scanf("%d",&n) && n!=0){
            if(n==1){
                printf("2\n");
                continue;
            }
            i=3;
            count = 1;
            while(count<n)
            {
                if(Prime(i)==1){
                count++;
            }
            i=i+2;
            }
        printf("%d\n",i-2);
        }
        return 0;
}
