#include "header.h"

int main()
{
    int roundSelect = 1, Choice = 1;
    int *pChoice = &Choice;
    Player user;
    bool accountLogedIn = true;
    int scoreWhenOutGame = 0;
    mainScreen game;
    game.col = 0;
    game.row = 0;
    string FileName = "SaveFile.dat";
    unsigned int index = 0;

    HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd, 0, 0, 1450, 760,TRUE);
    ShowScrollbar(0);
    DisableResizeWindow();
    setColor(15);
    gotoxy(79, 38);
    cout << "Use arrow key to move.";
    gotoxy(78, 39);
    cout << "Press SPACE for choosing.";
    generateAccScreen(roundSelect, Choice, FileName, user, index);
    if(roundSelect == -1)
        accountLogedIn = false;
    while(1){
        int scoreWhenOutGame = 0;
    	generateMenu(game, roundSelect, Choice, FileName);
    	if(game.row != 0 || game.col != 0)
        	playPikachu(user, game, roundSelect, accountLogedIn, scoreWhenOutGame);
        if(scoreWhenOutGame > user.record)
            updateScore(FileName, user, index, scoreWhenOutGame);
	}
    
    return 0;
}
