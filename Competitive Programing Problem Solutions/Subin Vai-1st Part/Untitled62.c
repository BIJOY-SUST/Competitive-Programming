#include<stdio.h>
int main() {
    int x,y,i,j,n;
    int grid[10][10];
    char c;
    printf("Please enter a initial position : ");
    scanf("%d %d", &x, &y);
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            grid[i][j] = 1;
        }
    }
    printf("Plese enter the number of blocked cells : ");
    scanf("%d", &n);
    printf("Now enter the cells : ");
    for (i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        grid[x][y] = 0;
    }
    while (grid[x][y] == 1) {
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

