#include "header.h"

int main()
{
    int roundSelect = 1, Choice = 1;
    int *pChoice = &Choice;
    Player user;
    mainScreen game;
    game.col = 0;
    game.row = 0;
    string FileName = "SaveFile.dat";
    unsigned int index = 0;

    HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd, 0, 0, 1450, 760,TRUE);
    ShowScrollbar(0);
    DisableResizeWindow();
    generateAccScreen(roundSelect, Choice, FileName, user, index);
    while(1){
    	generateMenu(game, roundSelect, Choice, FileName);
    	if(game.row != 0 || game.col != 0)
        	playPikachu(user, game, roundSelect);
	}
    /*generateMenu(row, col, roundSelect, Choice, FileName);
    
    if(row != 0 || col != 0){
        playPikachu(user, row, col);
    }*/
    return 0;
}
