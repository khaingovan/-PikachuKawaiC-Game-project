#include "header.h"

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
    generateMenu(row, col, roundSelect, Choice, FileName);
    
    return 0;
}
