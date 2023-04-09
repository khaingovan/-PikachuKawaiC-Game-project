#include "showing.h"

//http://mycodecollection.blogspot.com/2015/01/c-console-change-font-size.html
void fontsize(int a, int b){  
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
    GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
    lpConsoleCurrentFontEx->dwFontSize.X = a;  
    lpConsoleCurrentFontEx->dwFontSize.Y = b;  
    SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
}

//https://cplusplus.com/forum/articles/10515/
void clearScreen(){
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR) ' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}

//https://nguyenvanquan7826.wordpress.com/2013/08/22/cc-gotoxy-trong-dev-c-gotoxy-in-dev-c/
void gotoxy(SHORT x, SHORT y){ //y: row, x: col
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

//https://www.codespeedy.com/color-text-output-in-console-in-cpp/
/*
number =
0  : Black
1  : Blue
2  : Green
3  : Cyan
4  : Red
5  : Purple
6  : Yellow(dark)
7  : Default white
8  : Grey
9  : Bright blue
10 : Bright green
11 : Bright cyan
12 : Bright red
13 : Pink
14 : yellow
15 : Bright white

int color = number*16                  +       number
            (this is background color)       (and this is test color)
*/
void setColor(int color){
    HANDLE colo;
    colo =  GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colo, color);
}

void level2(int **board, int row, int col){ //blocks moving down
    for(int j = 1; j <= col; j++)
        for(int i = row; i >= 1; i--){
            if(board[i][j] == -1)
                for(int key = i; key >= 1; key--)
                    board[key][j] = board[key - 1][j];
            if(board[i][j] == -1)
                for(int key = i; key >= 1; key--)
                    board[key][j] = board[key - 1][j];
        }
}

void level3(int **board, int row, int col){ //blocks moving left
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++){
            if(board[i][j] == -1)
                for(int key = j; key <= col; key++)
                    board[i][key] = board[i][key + 1];
            if(board[i][j] == -1)
                for(int key = j; key <= col; key++)
                    board[i][key] = board[i][key + 1];
        }
}

void level4(int **board, int row, int col){ //blocks moving up
    for(int j = 1; j <= col; j++)
        for(int i = 1; i <= row; i++){
            if(board[i][j] == -1)
                for(int key = i; key <= row; key++)
                    board[key][j] = board[key + 1][j];
            if(board[i][j] == -1)
                for(int key = i; key <= row; key++)
                    board[key][j] = board[key + 1][j];
        }
}

void level5(int **board, int row, int col){ //blocks moving right
    for(int i = 1; i <= row; i++)
        for(int j = col; j >= 1; j--){
            if(board[i][j] == -1)
                for(int key = j; key >= 1; key--)
                    board[i][key] = board[i][key - 1];
            if(board[i][j] == -1)
                for(int key = j; key >= 1; key--)
                    board[i][key] = board[i][key - 1];
        }
}

void levelMove(int **board, int row, int col, int level){
    if(level == 1){
        //40 = 1*16 + 15 white text blue background
        setColor(40);
    }
    else if(level == 2){
        //79 = 4*16 + 15 white text red background
        setColor(79);
        level2(board, row, col);
    }
    else if(level == 3){
        //79 = 4*16 + 15 white text red background
        setColor(79);
        level3(board, row, col);
    }
    else if(level == 4){
        //79 = 4*16 + 15 white text red background
        setColor(79);
        level4(board, row, col);
    }
    else if(level == 5){
        //79 = 4*16 + 15 white text red background
        setColor(79);
        level5(board, row, col);
    }
}

void drawUnKey(int **board, int yr, int xr, char art[50][120], int y1, int x1){
    if(board[yr][xr] == -1){
		//15 = 0*16 + 15 white text black background
		setColor(15);

	    gotoxy(xr*5 + 1, yr*3 + 2);
        cout << art[yr*3    ][xr*5] << art[yr*3    ][xr*5 + 1] << art[yr*3    ][xr*5 + 2] << art[yr*3    ][xr*5 + 3] << art[yr*3    ][xr*5 + 4];
        gotoxy(xr*5 + 1, yr*3 + 3);
        cout << art[yr*3 + 1][xr*5] << art[yr*3 + 1][xr*5 + 1] << art[yr*3 + 1][xr*5 + 2] << art[yr*3 + 1][xr*5 + 3] << art[yr*3 + 1][xr*5 + 4];
        gotoxy(xr*5 + 1, yr*3 + 4);
        cout << art[yr*3 + 2][xr*5] << art[yr*3 + 2][xr*5 + 1] << art[yr*3 + 2][xr*5 + 2] << art[yr*3 + 2][xr*5 + 3] << art[yr*3 + 2][xr*5 + 4];
    }
    else{
        if(yr == y1 && xr == x1)
            //240 = 15*16 + 0 black text white background
            setColor(240);
        else
            //showing color from 8 to 14
            setColor(board[yr][xr]%6 + 9);
        
        char show;
        if(board[yr][xr] >= 0 && board[yr][xr] < 26)
            show = (char)(board[yr][xr] + (int)'A');
        else if(board[yr][xr] >= 26)
            show = (char)(board[yr][xr] + (int)'a' - 26);

        gotoxy(xr*5 + 1, yr*3 + 2);
        cout << (char)(201) << (char)(205) << (char)(205) << (char)(205) << (char)(187);
        gotoxy(xr*5 + 1, yr*3 + 3);
        cout << (char)(186) << " "         << show        << " "         << (char)(186);
        gotoxy(xr*5 + 1, yr*3 + 4);
        cout << (char)(200) << (char)(205) << (char)(205) << (char)(205) << (char)(188);
    }
}

void drawKey(int **board, int yr, int xr, int y1, int x1){
    if(yr == y1 && xr == x1)
        //241 = 15*16 + 1 blue text white background
	    setColor(241);
    else
        //31 = 1*16 + 15 white text blue background
        setColor(16 + board[yr][xr]%6 + 9);
    
    char show;
    if(board[yr][xr] >= 0 && board[yr][xr] < 26)
        show = (char)(board[yr][xr] + (int)'A');
    else if(board[yr][xr] >= 26)
        show = (char)(board[yr][xr] + (int)'a' - 26);
    else{
        //31 = 1*16 + 15 white text blue background
	    setColor(31);
        show = '_';
    }

	gotoxy(xr*5 + 1, yr*3 + 2);
	cout << (char)(201) << (char)(205) << (char)(205) << (char)(205) << (char)(187);
	gotoxy(xr*5 + 1, yr*3 + 3);
    cout << (char)(186) << " "         << show        << " "         << (char)(186);
	gotoxy(xr*5 + 1, yr*3 + 4);
    cout << (char)(200) << (char)(205) << (char)(205) << (char)(205) << (char)(188);
}

/*
    Use for void drawingLine (block in board)
    0: line down
    1: line up
    2: line right
    3: line left
    4: 179: line |
    5: 196: line -
    6: 218: line down-right
    7: 191: line down-left
    8: 192: line up-right
    9: 217: line up-left
    
    Use for void drawingLine
*/

void drawingLine(int **board, int i, int j){
    //4 = 0*16 + 4 red text black background
    setColor(4);
    gotoxy(j*5 + 1, i + 2);

    //mutiply i with 3 to draw the board

    //line down
    if(board[i/3][j] == (int)'0'){
        if(i%3 == 0)
            cout << (char)(201) << (char)(205) << (char)(205) << (char)(205) << (char)(187);
        else if(i%3 == 1)
            cout << (char)(186) << " "         << (char)(179) << " "         << (char)(186);
        else if(i%3 == 2)
            cout << (char)(200) << (char)(205) << (char)(179) << (char)(205) << (char)(188);
    }
    //line up
    else if(board[i/3][j] == (int)'1'){
        if(i%3 == 0)
            cout << (char)(201) << (char)(205) << (char)(179) << (char)(205) << (char)(187);
        else if(i%3 == 1)
            cout << (char)(186) << " "         << (char)(179) << " "         << (char)(186);
        else if(i%3 == 2)
            cout << (char)(200) << (char)(205) << (char)(205) << (char)(205) << (char)(188);
    }
    //line right
    else if(board[i/3][j] == (int)'2'){
        if(i%3 == 0)
            cout << (char)(201) << (char)(205) << (char)(205) << (char)(205) << (char)(187);
        else if(i%3 == 1)
            cout << (char)(186) << " "         << (char)(196) << (char)(196) << (char)(196);
        else if(i%3 == 2)
            cout << (char)(200) << (char)(205) << (char)(205) << (char)(205) << (char)(188);
    }
    //line left
    else if(board[i/3][j] == (int)'3'){
        if(i%3 == 0)
            cout << (char)(201) << (char)(205) << (char)(205) << (char)(205) << (char)(187);
        else if(i%3 == 1)
            cout << (char)(196) << (char)(196) << (char)(196) << " "         << (char)(186);
        else if(i%3 == 2)
            cout << (char)(200) << (char)(205) << (char)(205) << (char)(205) << (char)(188);
    }
    //line |
    else if(board[i/3][j] == (int)'4'){
        gotoxy(j*5 + 3, i + 2);
        cout                                   << (char)(179);
    }
    //line -
    else if(board[i/3][j] == (int)'5'){
        gotoxy(j*5 + 1, i + 2);
        if(i%3 == 1)
            cout << (char)(196) << (char)(196) << (char)(196) << (char)(196) << (char)(196);
    }
    //line down-right
    else if(board[i/3][j] == (int)'6'){
        gotoxy(j*5 + 3, i + 2);
        if(i%3 == 1)
            cout                               << (char)(218) << (char)(196) << (char)(196);
        else if(i%3 == 2)
            cout                               << (char)(179);
    }
    //line down-left
    else if(board[i/3][j] == (int)'7'){
        if(i%3 == 1){
            gotoxy(j*5 + 1, i + 2);
            cout << (char)(196) << (char)(196) << (char)(191);
        }
        else if(i%3 == 2){
            gotoxy(j*5 + 3, i + 2);
            cout                               << (char)(179);
        }
    }
    //line up-right
    else if(board[i/3][j] == (int)'8'){
        gotoxy(j*5 + 3, i + 2);
        if(i%3 == 0)
            cout                               << (char)(179);
        else if(i%3 == 1)
            cout                               << (char)(192) << (char)(196) << (char)(196);
    }
    //9: 217: line up-left
    else if(board[i/3][j] == (int)'9'){
        if(i%3 == 0){
            gotoxy(j*5 + 3, i + 2);
            cout                               << (char)(179);
        }
        else if(i%3 == 1){
            gotoxy(j*5 + 1, i + 2);
            cout << (char)(196) << (char)(196) << (char)(217);
        }
    }
}

void drawBorder(int color){
    setColor(color);

    gotoxy(0, 1);
    cout << char(218);
    for(int i = 1; i <= 22*5; i++)
        cout << char(196);
    cout << char(191);
    for(int i = 2; i <= 10*3 + 2; i++){
        gotoxy(0, i);
        cout << char(179);
        gotoxy(22*5 + 1, i);
        cout << char(179);
    }
    gotoxy(0, 10*3 + 3);
    cout << char(192);
    for(int i = 1; i <= 22*5; i++)
        cout << char(196);
    cout << char(217);
}

void drawingBoard(int **board, int row, int col, char bgArt[40][120]){
    //clearScreen();

	for(int i = 0; i < (row + 2)*3; i++){
		for(int j = 0; j < col + 2; j++){
            if(board[i/3][j] >= (int)'0' && board[i/3][j] <= (int)'9'){
                drawingLine(board, i, j);
            }
            else{
                //15 = 0*16 + 15 white text black background
	            //setColor(15);
                //showing color from 8 to 14
                setColor(board[i/3][j]%6 + 9);
                gotoxy(j*5 + 1, i + 2);
                if(board[i/3][j] == -1){
                    //15 = 0*16 + 15 white text black background
	                setColor(15);
                    cout << bgArt[i][j*5] << bgArt[i][j*5 + 1] << bgArt[i][j*5 + 2] << bgArt[i][j*5 + 3] << bgArt[i][j*5 + 4];
                }
                else if(i%3 == 0)
                    cout << (char)(201) << (char)(205) << (char)(205)                           << (char)(205) << (char)(187);
                else if(i%3 == 1 && board[i/3][j] < 26)
                    cout << (char)(186) << " "         << (char)(board[i/3][j] + (int)'A')      << " "         << (char)(186);
                else if(i%3 == 1 && board[i/3][j] >= 26)
                    cout << (char)(186) << " "         << (char)(board[i/3][j] + (int)'a' - 26) << " "         << (char)(186);
                else if(i%3 == 2)
                    cout << (char)(200) << (char)(205) << (char)(205)                           << (char)(205) << (char)(188);
            }
		}
		cout << endl;
	}

    //15 = 0*16 + 15 white text black background
	setColor(15);
}

void drawOutsideBoard(int &level, Player &user){
    if(level == 1){
        //1 draw blue border
        drawBorder(1);
        //40 = 1*16 + 15 white text blue background
        setColor(31);
    }
    else if(level == 2 || level == 4){
        //5 draw purple border
        drawBorder(5);
        //95 = 5*16 + 15 white text purple background
        setColor(95);
    }
    else if(level == 3 || level == 5){
        //4 draw red border
        drawBorder(4);
        //79 = 4*16 + 15 white text red background
        setColor(79);
    }
    gotoxy(0, 0);
    cout << "Level " << level;
    
    //15 = 0*16 + 15 white text black background
	setColor(15);
    gotoxy(20, 0);
    cout << "Player: ";
    gotoxy(40, 0);
    cout << "Score: " << user.record << endl;

    //drawing turtorial
    //10 = 0*16 + 10 bright green text black background
	setColor(10);
    gotoxy(125, 1);
    cout << "Using arrow key to move.";
    gotoxy(125, 2);
    cout << "Press SPACE for chosing 1 block.";
    gotoxy(125, 3);
    cout << "Press 'A' for auto playing (1 match).";
    gotoxy(125, 4);
    cout << "Press 'S' for shuffling the board.";

    //15 = 0*16 + 15 white text black background
	setColor(15);
}
