#pragma once
#pragma pack(1)
#include <fstream>
#include <string>

#define BOARDSIZE 100

struct State
{
    int numRow, numCol;   // size of saved board (8bytes)
    char Board[BOARDSIZE];  // saved board (100 bytes)
};
struct Player
{
    char username[17];      //17bytes
    char password[15];      //15bytes
    unsigned int record;             //score  (4bytes)
    State savedStage;       //about saveBoard (108bytes)
};

bool isExistAcc(string FileName, char username[17]); //Check if account exists
void signUp (string FileName);  // sign up new account
void signIn (string FileName);  //  log in game
