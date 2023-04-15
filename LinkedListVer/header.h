#pragma once
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <new>
#include <fstream>
#include <chrono>
#include <thread>
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
    int TChar;                  //totalCharacter - number of remaining blocks in game
};

struct State
{
    int numRow, numCol;         // size of saved board (8bytes)
};


struct Node{
	int data;
    int pos;
	Node* pNext;
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
    Node** pHead;
};

#include "board.cpp"
#include "showing.cpp"
#include "gamePlay.cpp"
#include "playMusic.cpp"
#include "linkedList.cpp"
#include "account.cpp"
#include "menu.cpp"
#include "printDesign.cpp"
#include "leaderBoard.cpp"
