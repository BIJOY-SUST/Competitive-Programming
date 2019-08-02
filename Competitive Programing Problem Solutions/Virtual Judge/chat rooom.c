#include<stdio.h>
#include<string.h>
int main(){
    char a[100];
    int h,e,l1,l2,o,l,flag=0;
    gets(a);
    l=strlen(a);
    for(h=0;h<l;h++){
        if(a[h]=='h'){
        for(e=h+1;e<l;e++){
            if(a[e]=='e'){
            for(l1=e+1;l1<l;l++){
                if(a[l1]=='l'){
                for(l2=l1+1;l2<l;l2++){
                    if(a[l2]=='l'){
                    for(o=l2+1;o<l;o++){
                        if(a[o]=='o'){
                        flag=1;
                        break;
                        }
                    }
                    }
                }
                }
            }
            }
        }
        }
    }

    if(flag==1){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
