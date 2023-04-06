#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "FormatScreens.cpp"
#include "Account.h"
using namespace std;

void swap(Player &a, Player &b);
void selectionSort(vector <Player> &Leader, int numAcc);
// Higest Score Board
void printLeaderBoard(string FileName);
