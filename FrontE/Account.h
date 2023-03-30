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
//Small Function
bool isExistAcc(string FileName, char username[17], unsigned int &index); //Check if account exists
bool isPasswordCorrect(string FileName, char password[15], unsigned int index);     //Check Password
void getInfo(string FileName, Player &oldMan, unsigned int index);
//Big Function
void signUp (string FileName);  // sign up new account
void signIn(string FileName, Player &oldMan);  //  log in game

