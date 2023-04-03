#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <conio.h>
#include <iomanip>
#include <new>
#include <fstream>
#include <windows.h>
//#include <vector>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

struct characterBlockInfor{
    int TDiffer;    //totalDifferentCharacter
    int *charBlock; //characterBlock
    int TChar;      //totalCharacter
};