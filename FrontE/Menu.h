#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <fstream>
#include <windows.h>
#include "FormatScreens.cpp"
#include "LeaderBoard.cpp"
using namespace std;

//Mã ASCII các phím điều khiển từ bàn phím
#define KeyUp 72
#define KeyDown 80
#define KeyLeft 75
#define KeyRight 77
#define Space 32
#define Esc 27

    //Small Function
// function get orders from keyboard 
void getEvents(int &row, int &col, int &roundSelect, int &Choice); 
// split up from printMenu, make it easy to change later
void printCredit();
// function show interactive screen 
void printMenu(int roundSelect, int Choice);
    //Big Function
// exact menu
void generateMenu(int &row, int &col, int &roundSelect, int &Choice);

