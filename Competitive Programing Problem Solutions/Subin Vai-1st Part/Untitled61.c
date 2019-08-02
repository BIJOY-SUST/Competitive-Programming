#include<stdio.h>
int main() {
    int x,y,i,j;
    int grid[10][10];
    char c;
    printf("Please enter a initial position : ");
    scanf("%d %d", &x, &y);
    while (1) {
        scanf("%c", &c);
        if(c == 'S') {
            break;
        }
        else if (c == 'u') {
            x--;
        }
        else if (c == 'D') {
            x++;
        }
        else if (c == 'L') {
            y--;
        }
        else if (c == 'R') {
            y++;
        }
    }
    printf("Final position of the robot is : %d, %d\n", x, y);
    return 0;
}
