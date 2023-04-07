#pragma once
#include <iostream>
#include <stdio.h>
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

#define KeyUp 72
#define KeyDown 80
#define KeyLeft 75
#define KeyRight 77
#define Space 32
#define Esc 27

struct characterBlockInfor{
    int TDiffer;    //totalDifferentCharacter
    int *charBlock; //characterBlock
    int TChar;      //totalCharacter
};
