/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
using namespace std;
bool isLeap(int year){
    if(year%400==0||(year%4==0&&year%100!=0)) return true;
    else return false;
}
int main(){
    int choice;
    printf("Select an option :-\n(1) English Calander\n(2) Bengali Calander\n");
    printf("Enter your choice : ");
    while(scanf("%d",&choice)&&choice!=0){
        switch(choice){
            case 1:{
                char EngMonthNames[12][10]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
                int EngMonthDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
                char DayNames[7][5]={"SAT","SUN","MON","TUE","WED","THU","FRI"};
                int DayNo[31]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
                //int y=1,day=2,m=0,year,month;
                int year;
                printf("\nEnter a year : ");
                scanf("%d",&year);
//                printf("\nEnter the serial no of month : ");
//                scanf("%d",&month);
//                month--;
                for(int month=0;month<12;month++){
                    int y=1,day=2,m=0;
                    while(y<year){
                        if(isLeap(y)) day=(day+366)%7;
                        else day=(day+365)%7;
                        y++;
                    }
                    while(m<month){
                        if(isLeap(year)&&m==1) day=(day+29)%7;
                        else day=(day+EngMonthDays[m])%7;
                        m++;
                    }
                    printf("\n\n");
                    printf("%90s%36d",EngMonthNames[month],year);
                    printf("\n\n%90s%6s%6s%6s%6s%6s%6s\n",DayNames[0],DayNames[1],DayNames[2],DayNames[3],DayNames[4],DayNames[5],DayNames[6]);
                    for(int i=0;i<day;i++){
                        if(i==0) printf("%90s"," ");
                        else printf("%6s"," ");
                    }
                    if(isLeap(year)&&month==1) EngMonthDays[1]=29;
                    else EngMonthDays[1]=28;
                    for(int i=0,j=day;i<EngMonthDays[month];i++,j++){
                        if(j==0) printf("%90d",DayNo[i]);
                        else printf("%6d",DayNo[i]);
                        if(j==6){
                            j=-1;printf("\n");
                        }
                    }
                    printf("\n\n");
                }
                break;
            }
            case 2:{
                char EngMonthNames[12][10]={"BOISHAKH","JOISHTHO","ASHAR","SHRABON","BHADRO","ASHSHIN","KARTRIK","OGROHAYON","POUSH","MAGH","PHALGUN","CHOITRO"};
                int EngMonthDays[12]={31,31,31,31,31,30,30,30,30,30,30,30};
                char DayNames[7][5]={"SAT","SUN","MON","TUE","WED","THU","FRI"};
                int DayNo[31]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
//                int y=1,day=2,m=0,year,month;
                int year;
                printf("\nEnter a year : ");
                scanf("%d",&year);
//                printf("\nEnter the serial no of month : ");
//                scanf("%d",&month);
//                month--;
                for(int month=0;month<12;month++){
                    int y=1,day=2,m=0;
                    while(y<year){
                        if(isLeap(y+594)) day=(day+366)%7;
                        else day=(day+365)%7;
                        y++;
                    }
                    while(m<month){
                        if(isLeap(year+594)&&m==10) day=(day+31)%7;
                        else day=(day+EngMonthDays[m])%7;
                        m++;
                    }
                    printf("\n\n");
                    printf("%90s%36d",EngMonthNames[month],year);
                    printf("\n\n%90s%6s%6s%6s%6s%6s%6s\n",DayNames[0],DayNames[1],DayNames[2],DayNames[3],DayNames[4],DayNames[5],DayNames[6]);
                    for(int i=0;i<day;i++){
                        if(i==0) printf("%90s"," ");
                        else printf("%6s"," ");
                    }
                    if(isLeap(year+594)&&month==10) EngMonthDays[10]=31;
                    else EngMonthDays[10]=30;
                    for(int i=0,j=day;i<EngMonthDays[month];i++,j++){
                        if(j==0) printf("%90d",DayNo[i]);
                        else printf("%6d",DayNo[i]);
                        if(j==6){
                            j=-1;printf("\n");
                        }
                    }
                    printf("\n\n");
                }
            }
        }
        printf("Select an option :-\n(1) English Calander\n(2) Bengali Calander\n(0) For Exist\n");
        printf("Enter your choice : ");
    }
    return 0;
}
