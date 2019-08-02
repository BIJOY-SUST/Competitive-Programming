#include<stdio.h>
struct nametype{
    char first[20];
    char last[20];
}a;
struct student{
    int id;
    struct nametype name;
};
int main(){
    struct student one;

    scanf("%d",&one.id);
    scanf("%s",&one.name.first);
    scanf("%s",&one.name.last);

    printf("ID: %d      Name: %s %s\n",one.id,one.name.first,one.name.last);
    //printf("%d\n",sizeof(a));
}
