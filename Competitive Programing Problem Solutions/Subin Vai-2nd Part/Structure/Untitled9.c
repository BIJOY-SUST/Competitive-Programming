#include<stdio.h>
#include<string.h>

typedef struct{
    char first[50];
    char last[50];
}nametype;
typedef struct{
    int id;
    nametype name;
    char grade[3];
}studenttype;

void calculate_grade(studenttype *s, int mark){
    if(mark>=80){
        strcpy(s->grade,"A+");
    }
    else if(mark>=70){
        strcpy(s->grade,"A");
    }
    else if(mark>=60){
        strcpy(s->grade,"A-");
    }
    else if(mark>=50){
        strcpy(s->grade,"B");
    }
    else if(mark>40){
        strcpy(s->grade,"C");
    }
    else{
        strcpy(s->grade,"F");
    }
}

int main(){
    int i,n=5;
    scanf("%d",&n);
    int marks[n];
    studenttype student[n];

    for(i=0;i<n;i++){
        scanf("%d",&student[i].id);
        scanf("%s",&student[i].name.first);
        scanf("%s",&student[i].name.last);
        scanf("%d",&marks[i]);
        printf("\n");                       //strcpy(student[i].grade,"");

    }
    for(i=0;i<n;i++){
        calculate_grade(&student[i],marks[i]);
    }
    printf("Output:\n\n");
    for(i=0;i<n;i++){
        printf("ID: %d      Name: %s %s     Grade: %s.\n",student[i].id,student[i].name.first,student[i].name.last,student[i].grade);
    }
    return 0;
}

