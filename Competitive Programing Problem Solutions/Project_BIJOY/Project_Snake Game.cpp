#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define PLANEHEIGHT 20
#define PLANEWIDTH 50
#define INITIALSNAKELENGTH 1
#define FPS 5
using namespace std;
int snakeLength = INITIALSNAKELENGTH;
char lastDirection = 'd';
int foodX;
int foodY;
char plane[ PLANEHEIGHT * PLANEWIDTH ];
class SnakeSegment{
public:
    SnakeSegment() {};
    SnakeSegment( int x1,int y1 ){
        x = x1;
        y = y1;
    }
    int x;
    int y;
};
vector< SnakeSegment > m_Snake;
void DisplayPlane(){
    for(int i = 0; i < PLANEWIDTH + 2; i++ ) printf( "%c", '-' );     printf( "\n" ); //upper bound
    for(int y = 0; y < PLANEHEIGHT; y++ ){
        printf( "%c", '|' ); //left bound
        for(int x = 0; x < PLANEWIDTH; x++ ){
            printf( "%c",plane[ y * PLANEWIDTH + x ] ); //stuff: X = food, O  = snake segment, ' ' = blank space
        }
        printf( "%c\n",'|' ); //right bound
    }
    for(int i = 0; i < PLANEWIDTH + 2; i++ ) printf( "%c",'-' );     printf( "\n" ); //lower bound
    printf( "Snake length: %d\n",snakeLength );
}
void NormalisePlane(){
    for(int x = 0; x < PLANEWIDTH; x++ )
        for(int y = 0; y < PLANEHEIGHT; y++ )
            plane[ y * PLANEWIDTH + x ] = ' ' ;//sets all plane cells to ' '
}
void SnakeInit() {
    for(int i = 0; i < snakeLength; i++ ){
        SnakeSegment segment;
        segment.x = i;
        segment.y = 0;
        m_Snake.push_back( segment );//spawns snake in a line of set length in first row of plane
        plane[ i ] = 'O';
    }
}
void FoodInit(){
    foodX = rand() % PLANEWIDTH;
    foodY = rand() % PLANEHEIGHT;
    while ( plane[ foodY * PLANEWIDTH + foodX ] != ' ' ){
        foodX = rand() % PLANEWIDTH;
        foodY = rand() % PLANEHEIGHT;//new food has to be spawned at empty cell
    }
    plane[ foodY * PLANEWIDTH + foodX ] = 'X';
}
void DeleteLastSnakeSegment(){
    SnakeSegment temp = m_Snake[ 0 ];
    plane[ temp.y * PLANEWIDTH + temp.x ] = ' ';
    m_Snake.erase( m_Snake.begin() ); //first is last
}
void Move(){
    if( lastDirection == 'd' ){
        SnakeSegment segment = m_Snake.at( m_Snake.size() - 1 );
        segment.x++;
        m_Snake.push_back( segment );
        plane[ segment.y * PLANEWIDTH + segment.x ] = 'O';
        DeleteLastSnakeSegment();
    }
    else if( lastDirection == 's' ){
        SnakeSegment segment = m_Snake.at( m_Snake.size() - 1 );
        segment.y++;
        m_Snake.push_back( segment );
        plane[ segment.y * PLANEWIDTH + segment.x ] = 'O';
        DeleteLastSnakeSegment();
    }
    else if(lastDirection == 'a'){
        SnakeSegment segment = m_Snake.at( m_Snake.size() - 1 );
        segment.x--;
        m_Snake.push_back( segment );
        plane[ segment.y * PLANEWIDTH + segment.x ] = 'O';
        DeleteLastSnakeSegment();
    }
    else if( lastDirection == 'w' ){
        SnakeSegment segment = m_Snake.at( m_Snake.size() - 1 );
        segment.y--;
        m_Snake.push_back( segment );
        plane[ segment.y * PLANEWIDTH + segment.x ] = 'O';
        DeleteLastSnakeSegment();
    }
}
bool HasEatenFood(){
    SnakeSegment segment = m_Snake.at( m_Snake.size() - 1 ); //first element of snake
    SnakeSegment food;
    food.x = foodX;
    food.y = foodY;
    return segment.x == food.x && segment.y == food.y; //if his "head" collides with food cell
}
void WipeConsole(){
    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    COORD coord = {0,0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if( GetConsoleScreenBufferInfo(hStdOut,&csbi )){
        FillConsoleOutputCharacter( hStdOut,(TCHAR)32,csbi.dwSize.X * csbi.dwSize.Y,coord,&count );
        FillConsoleOutputAttribute( hStdOut,csbi.wAttributes,csbi.dwSize.X - 1 * csbi.dwSize.Y - 1,coord,&count );
        SetConsoleCursorPosition( hStdOut,coord );
    }
    return;
}
bool Won(){
    bool space = false;
    for( int x = 0; x < PLANEWIDTH; x++ ) for(int y = 0; y < PLANEHEIGHT; y++ )
        if( plane[ y * PLANEWIDTH + x ] == ' ' ) {//if none of cells is empty we won
            space = true;
            break;
        }
    return !space;
}
bool Lost(){
    SnakeSegment segment = m_Snake.at( m_Snake.size() - 1 ); //first element of snake
    if( segment.x < 0 || segment.x > PLANEWIDTH - 1 ||
        segment.y < 0 || segment.y > PLANEHEIGHT - 1 ) return true; //if colides with boundries

    for(int i = 0; i < m_Snake.size() - 1; i++ ) {//or with itself we return true
        SnakeSegment temp = m_Snake[ i ];
        if( temp.x == segment.x && temp.y == segment.y ) return true;
    }
    return false;
}
int main(){
    srand((unsigned int)time(NULL));
    NormalisePlane();
    SnakeInit();
    FoodInit();
    while(1){
        clock_t start;
        double time = 0.0;
        start = clock();
        while( time < 1.0 / FPS ){
            time = ( clock() - start ) / (double)CLOCKS_PER_SEC;
        }
        if(_kbhit()){//can get keyboard input without pressing Enter key
            lastDirection = _getch();
        }
        if(HasEatenFood()){
            snakeLength++;
            SnakeSegment segment( foodX,foodY );
            m_Snake.push_back( segment ); //we add eaten food position as a new snake segment
            FoodInit(); //and spawn new food
        }
        WipeConsole();
        DisplayPlane();
        Move();
        if( Won() ){
            printf( "Congratulation, you have won!\n" );
            break;
        }
        if( Lost() ){
            printf( "You have lost!\n" );
            break;
        }
    }
    system( "PAUSE" );
}


