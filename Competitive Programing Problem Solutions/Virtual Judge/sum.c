 #include<stdio.h>
int main(){
    int n,N,ans;
    scanf("%d",&N);
    if(N > 1){
        n=N;
    }
    else{
        n=-1*N+2;
    }
    ans=(n*(N+1))/2;
    printf("%d\n",ans);
    return 0;
}
