#pragma once
#include "ClearScreen.cpp"
using namespace std;

//M� ASCII c�c ph�m di?u khi?n t? b�n ph�m
#define KeyUp 72
#define KeyDown 80
#define KeyLeft 75
#define KeyRight 77
#define Space 32
#define Esc 27

void getEvents(int &line, int &col, int &roundSelect, int &Choice);
void printMenu(int roundSelect, int Choice);
void generateMenu(int &line, int &col, int &roundSelect, int &Choice);

