#pragma once
#include <fstream>
#include <string>
using namespace std;
#define BOARDSIZE 100

struct State
{
    int numRow, numCol;   // size of saved board (8bytes)
    char Board[BOARDSIZE];  // saved board (100 bytes)
};
struct Player
{
    char username[16];      //16bytes
    char password[10];      //10bytes
    unsigned int record;             //score  (4bytes)
    State savedStage;       //about saveBoard (108bytes)
};

string FileName = "FileSave.bin";
bool isValidAcc(string FileName, char username[16]);
void signUp(string FileName);
void signin(string FileName);

