#include<stdio.h>
#include<string.h>
struct nametype{
    char first[50];
    char last[50];
};
struct studenttype{
    int id;
    struct nametype name;
};
int main(){
    int i,n;
    scanf("%d",&n);
    struct studenttype student[n];


    for(i=0; i<n;i++){
        scanf("%d",&student[i].id);
        scanf("%s",&student[i].name.first);
        scanf("%s",&student[i].name.last);
        printf("\n\n");
    }

    for(i=0; i<n;i++){
        printf("ID: %d      Name: %s %s\n",student[i].id,student[i].name.first,student[i].name.last);
    }
    return 0;
}
