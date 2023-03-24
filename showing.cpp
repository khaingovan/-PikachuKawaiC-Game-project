#include "showing.h"

void clearScreen(){ //using code from https://cplusplus.com/forum/articles/10515/
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

void drawingBoard(int **board, int row, int col){
    clearScreen();
	for(int i = 0; i <= (row + 1)*3; i++){
		for(int j = 0; j <= col + 1; j++){
			if(board[i/3][j] == -1)
				cout << "     ";
			else if(i%3 == 0)
				cout << char(201) << char(205) << char(205) << char(205) << char(187);
			else if(i%3 == 1)
				cout << char(186) << " " << (char)(board[i/3][j] + (int)'A') << " " << char(186);
            else if(i%3 == 2)
				cout << char(200) << char(205) << char(205) << char(205) << char(188);
		}
		cout << endl;
	}
}