#include "showing.h"

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
    HANDLE col;
    col =  GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col, color);
}

//https://ss64.com/nt/syntax-ansi.html
/*  Color	                        Foreground	   Background	COLOR equivalent
    Default	                        Esc[0m	 	 
    Black BLACK	                    Esc[30m	       Esc[40m	    0
    Red DARK_RED	                Esc[31m        Esc[41m	    4
    Green DARK_GREEN	            Esc[32m        Esc[42m	    2
    Yellow DARK_YELLOW	            Esc[33m        Esc[43m	    6
    Blue DARK_BLUE	                Esc[34m	       Esc[44m	    1
    Magenta DARK_MAGENTA	        Esc[35m	       Esc[45m	    5
    Cyan DARK_CYAN	                Esc[36m	       Esc[46m	    3
    Light gray DARK_WHITE	        Esc[37m	       Esc[47m	    7
    Dark gray BRIGHT_BLACK	        Esc[90m	       Esc[100m	    8
    Light red BRIGHT_RED	        Esc[91m	       Esc[101m	    C
    Light green BRIGHT_GREEN	    Esc[92m	       Esc[102m	    A
    Light yellow BRIGHT_YELLOW	    Esc[93m	       Esc[103m	    E
    Light blue BRIGHT_BLUE	        Esc[94m	       Esc[104m	    9
    Light magenta BRIGHT_MAGENTA	Esc[95m	       Esc[105m	    D
    Light cyan BRIGHT_CYAN	        Esc[96m	       Esc[106m	    B
    White WHITE	                    Esc[97m	       Esc[107m	    F
*/


void level2(int **board, int row, int col){ //cac toa do chuyen dong xuong
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

void level3(int **board, int row, int col){ //cac toa do chuyen qua trai
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

void level4(int **board, int row, int col){ //cac toa do chuyen dong len
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

void level5(int **board, int row, int col){ //cac toa do chuyen qua phai
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

/*void drawingBackground(int **board, int row, int col, int i, int j){
    ofstream fout;
    ifstream fin;

    char *background;
    background = new char [5];
    fin.open("BackgroundArt\\art1.txt");
    int count = 0;
	while(count < 5){
		fin.get( background[count] );
		count++;
	}
    fin.close();

    //ve background
    for(int countI = 0; i < 5; i++)
		cout << background[countI];
    
    delete [] background;
}*/

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
    //i can phai *3 de ve board

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
        if(i%3 == 0)
            cout << " "         << " "         << (char)(179) << " "         << " "        ;
        else if(i%3 == 1)
            cout << " "         << " "         << (char)(179) << " "         << " "        ;
        else if(i%3 == 2)
            cout << " "         << " "         << (char)(179) << " "         << " "        ;
    }
    //line -
    else if(board[i/3][j] == (int)'5'){
        if(i%3 == 0)
            cout << " "         << " "         << " "         << " "         << " "        ;
        else if(i%3 == 1)
            cout << (char)(196) << (char)(196) << (char)(196) << (char)(196) << (char)(196);
        else if(i%3 == 2)
            cout << " "         << " "         << " "         << " "         << " "        ;
    }
    //line down-right
    else if(board[i/3][j] == (int)'6'){
        if(i%3 == 0)
            cout << " "         << " "         << " "         << " "         << " "        ;
        else if(i%3 == 1)
            cout << " "         << " "         << (char)(218) << (char)(196) << (char)(196);
        else if(i%3 == 2)
            cout << " "         << " "         << (char)(179) << " "         << " "        ;
    }
    //line down-left
    else if(board[i/3][j] == (int)'7'){
        if(i%3 == 0)
            cout << " "         << " "         << " "         << " "         << " "        ;
        else if(i%3 == 1)
            cout << (char)(196) << (char)(196) << (char)(191) << " "         << " "        ;
        else if(i%3 == 2)
            cout << " "         << " "         << (char)(179) << " "         << " "        ;
    }
    //line up-right
    else if(board[i/3][j] == (int)'8'){
        if(i%3 == 0)
            cout << " "         << " "         << (char)(179) << " "         << " "        ;
        else if(i%3 == 1)
            cout << " "         << " "         << (char)(192) << (char)(196) << (char)(196);
        else if(i%3 == 2)
            cout << " "         << " "         << " "         << " "         << " "        ;
    }
    //9: 217: line up-left
    else if(board[i/3][j] == (int)'9'){
        if(i%3 == 0)
            cout << " "         << " "         << (char)(179) << " "         << " "        ;
        else if(i%3 == 1)
            cout << (char)(196) << (char)(196) << (char)(217) << " "         << " "        ;
        else if(i%3 == 2)
            cout << " "         << " "         << " "         << " "         << " "        ;
    }
}

void drawingBoard(int **board, int row, int col, int &level, bool draw){
    clearScreen();

    if(level == 1){
        //31 = 1*16 + 15 chu trang sang nen xanh duong
        setColor(31);
    }
    else if(level == 2){
        //79 = 4*16 + 15 chu trang sang nen do
        setColor(79);

        if(draw)
            level2(board, row, col);
    }
    else if(level == 3){
        //79 = 4*16 + 15 chu trang sang nen do
        setColor(79);
        
        if(draw)
            level3(board, row, col);
    }
    else if(level == 4){
        //79 = 4*16 + 15 chu trang sang nen do
        setColor(79);
        
        if(draw)
            level4(board, row, col);
    }
    else if(level == 5){
        //79 = 4*16 + 15 chu trang sang nen do
        setColor(79);
        
        if(draw)
            level2(board, row, col);
    }
    cout << "Level " << level;
    
    //15 = 0*16 + 15 chu trang nen den
	setColor(15);

    cout << "\t\t\tScore:" << endl;

	for(int i = 0; i < (row + 2)*3; i++){
		for(int j = 0; j < col + 2; j++){
            if(board[i/3][j] >= (int)'0' && board[i/3][j] <= (int)'9'){
                //10 = 0*16 + 10 chu xanh la nen den
	            setColor(10);
                drawingLine(board, i, j);
            }
            else{
                //15 = 0*16 + 15 chu trang nen den
	            setColor(15);
                if(board[i/3][j] == -1)
                    cout << "#####";
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

    //10 = 0*16 + 10 chu xanh la nen den
	setColor(10);
    cout << endl << "Using arrow key.";
}