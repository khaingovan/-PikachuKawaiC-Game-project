#include "header.h"
/*#include "account.cpp"
#include "leaderBoard.cpp"
#include "playMusic.cpp"*/

int main()
{
    int roundSelect = 1, Choice = 1, col = 0, row = 0 ;
    Player user;
    string FileName = "SaveFile.dat";
    unsigned int index = 0;

    HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd, 0, 0, 1450, 760,TRUE);
    ShowScrollbar(0);
    DisableResizeWindow();
    generateAccScreen(roundSelect, Choice, FileName, user, index);
    while(1){
    	generateMenu(row, col, roundSelect, Choice, FileName);
    	if(row != 0 || col != 0)
        	playPikachu(user, row, col);
	}
    /*generateMenu(row, col, roundSelect, Choice, FileName);
    
    if(row != 0 || col != 0){
        playPikachu(user, row, col);
    }*/
    return 0;
}
