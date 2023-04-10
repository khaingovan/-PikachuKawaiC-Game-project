#pragma once
#include <iostream>
#include <ctime>
#include <cmath>
#include <new>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>

#include "FormatScreens.cpp"
#include "PlayMusic.cpp"
#include "PrintDesign.cpp"

//Mã ASCII các phím điều khiển từ bàn phím
#define KeyUp 72
#define KeyDown 80
#define KeyLeft 75
#define KeyRight 77
#define Space 32
#define Esc 27
#define BOARDSIZE 100

using namespace std;

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
