#include "header.h"

int main()
{
    int roundSelect = 1, Choice = 1, col = 0, row = 0 ;
    Player user;
    string FileName = "SaveFile.dat";
    unsigned int index = 0;
    // SetWindowSize(60, 100);
    // SetScreenBufferSize(60, 100);
    // DisableResizeWindow();
    // generateMenu(row, col, roundSelect, Choice ); 
    // signUp(FileName);
    generateAccScreen(roundSelect, Choice, FileName, user, index);
    
    generateMenu(row, col, roundSelect, Choice);
    // unsigned int score = 144;
    
    // updateScore(FileName, user, index, score);
    // cout << user.record;
    // generateAccScreen(roundSelect, Choice, FileName, user);

    // string Music = "F:\\Code\\Kỹ thuật lập trình\\Game Pikachu\\CloneOp\\-PikachuKawaiC-Game-project\\FrontE\\ES_Sunday_Coffee_Rebecca_Mardal.wav";
    // PlaySound(TEXT("ES_Sunday_Coffee_Rebecca_Mardal.wav"), NULL, SND_FILENAME | SND_ASYNC);
    
    return 0;
}