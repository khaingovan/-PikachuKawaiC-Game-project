#include "header.h"

int main()
{
    int roundSelect = 1, Choice = 1, col = 0, row = 0 ;
    Player user;
    string FileName = "SaveFile.dat";
    unsigned int index = 0;
<<<<<<< HEAD
    // SetWindowSize(60, 100);
    // SetScreenBufferSize(60, 100);
    // // DisableResizeWindow();
    // generateAccScreen(roundSelect, Choice, FileName, user, index);

    // generateMenu(row, col, roundSelect, Choice ); 
    // signUp(FileName);
    // generateAccScreen(roundSelect, Choice, FileName, user, index);
    
    // generateMenu(row, col, roundSelect, Choice);
    // unsigned int score = 3;
    printLeaderBoard(FileName);
    
    
        // unsigned score = 30;
        // updateScore(FileName, user, index, score);
    // 
    // cout << user.record;
    

    // string Music = "F:\\Code\\K? thu?t l?p trình\\Game Pikachu\\CloneOp\\-PikachuKawaiC-Game-project\\FrontE\\ES_Sunday_Coffee_Rebecca_Mardal.wav";
    // PlaySound(TEXT("ES_Sunday_Coffee_Rebecca_Mardal.wav"), NULL, SND_FILENAME | SND_ASYNC);
=======
    SetWindowSize(60, 100);
    SetScreenBufferSize(60, 100);
    DisableResizeWindow();
    generateAccScreen(roundSelect, Choice, FileName, user, index);
    generateMenu(row, col, roundSelect, Choice, FileName);
>>>>>>> 985fbac88cb92cadcfcd65fcf9edaa4c57e06ebf
    
    return 0;
}
