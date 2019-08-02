#include<stdio.h>
struct student{
    int ID;
    char Name[40];
};
int main(){
    struct student one;
    one.ID = 1;
    strcpy(one.Name, "BIJOY");

    printf("ID : %d\n",one.ID);
    printf("Name : %s\n",one.Name);
}


