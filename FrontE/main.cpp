#include "header.h"

int main()
{
    int roundSelect = 1, Choice = 1, col = 0, row = 0 ;
    Player user;
    string FileName = "SaveFile.dat";
    //string FileName = "SaveFile.bin";
    unsigned int index = 0;
    SetWindowSize(60, 100);
    SetScreenBufferSize(60, 100);
    DisableResizeWindow();
    generateAccScreen(roundSelect, Choice, FileName, user, index);
    generateMenu(row, col, roundSelect, Choice, FileName);
    
    return 0;
}

