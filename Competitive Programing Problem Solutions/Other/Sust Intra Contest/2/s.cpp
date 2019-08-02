#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long int i,n;
    double a,d;
    scanf("%lf %lf",&a,&d);
    scanf("%lld",&n);
    double k=0.0;
    for(i=0;i<n;i++){
        k=k+d;

        if(k>4*a){
            k=fmod(k,4*a);
            //k=k-4*a*((int)(k/4/a));
        }
        //printf("%lf\n",k);
        if(k<=a) printf("%.10lf %.10lf\n",k,0.0);
        else if(k<=2*a) printf("%.10lf %.10lf\n",a,k-a);
        else if(k<=3*a) printf("%.10lf %.10lf\n",3*a-k,a);
        else if(k<=4*a) printf("%.10lf %.10lf\n",0.0,4*a-k);
    }
    return 0;
}
