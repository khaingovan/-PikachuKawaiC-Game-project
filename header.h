#pragma once
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <new>
#include <fstream>
#include <chrono>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;
using namespace std::chrono;

#define KeyUp 72
#define KeyDown 80
#define KeyLeft 75
#define KeyRight 77
#define Space 32
#define Esc 27

struct characterBlockInfor{
    int TDiffer;                //totalDifferentCharacter
    int *charBlock;             //characterBlock
    int TChar;                  //totalCharacter
};

struct State
{
    int numRow, numCol;         // size of saved board (8bytes)
};

struct Player
{
    char username[17];          //17bytes
    char password[15];          //15bytes
    int record;                 //score(4bytes)
    State savedStage; 
};

struct mainScreen{
    int row;
    int col;
    int **board;
};

#include "board.cpp"
#include "showing.cpp"
#include "account.cpp"
#include "leaderBoard.cpp"
#include "menu.cpp"
#include "printDesign.cpp"
#include "gamePlay.cpp"
#include "playMusic.cpp"