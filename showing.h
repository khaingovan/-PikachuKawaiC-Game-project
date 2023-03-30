#pragma once
#include "header.h"

void fontsize(int a, int b);
void clearScreen();
void setColor(int color);
void level2(int **board, int row, int col);
void level3(int **board, int row, int col);
void level4(int **board, int row, int col);
void level5(int **board, int row, int col);
//void drawingBackground(int **board, int row, int col, int i, int j);
void drawingLine(int **board, int i, int j);
void drawingBoard(int **board, int row, int col, int &level, bool draw = 0);
