#pragma once
#include "header.h"
#include "LeaderBoard.cpp"

    //Small Function
// function get orders from keyboard 
void getEvents(int &row, int &col, int &roundSelect, int &Choice); 
// split up from printMenu, make it easy to change later
void printCredit();
// function show interactive screen 
void printMenu(int roundSelect, int Choice, string FileName);
    //Big Function
// exact menu
void generateMenu(int &row, int &col, int &roundSelect, int &Choice, string FileName);
