#include<stdio.h>
struct student{
    int id;
    char *name;
};
int main(){
    struct student one;
    one.id = 1;
    one.name = "BIJOY";
    printf("ID: %d\n",one.id);
    printf("Name: %s\n",one.name);

    return 0;
}

