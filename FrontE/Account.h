#pragma once
#pragma pack(1)
#include <fstream>
#include <string>
#include "PrintDesign.cpp"
#define BOARDSIZE 100
//Mã ASCII các phím điều khiển từ bàn phím
#define KeyUp 72
#define KeyDown 80
#define Space 32
#define Esc 27
struct State
{
    int numRow, numCol;   // size of saved board (8bytes)
};
struct Player
{
    char username[17];      //17bytes
    char password[15];      //15bytes
    unsigned int record;             //score  (4bytes)
    State savedStage; 
};
//Small Function
bool isExistAcc(string FileName, char username[17], unsigned int &index); //Check if account exists
bool isPasswordCorrect(string FileName, char password[15], unsigned int index);     //Check Password
void getInfo(string FileName, Player &oldMan, unsigned int index);
//Big Function
void signUp(string FileName);  // sign up new account
void signIn(string FileName, Player& oldMan, unsigned int &index);  //  log in game
//void updateScore(string FileName, Player &oldMan, unsigned int index, unsigned int newscore);
//Choice Sign in or Sign up
void selectAccChoice(int &roundSelect, int &Choice);
void printAccChoice(int Choice);
void generateAccScreen(int &roundSelect, int &Choice, string FileName, Player &oldMan, unsigned int &index);
