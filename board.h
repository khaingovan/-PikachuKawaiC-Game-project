#pragma once
#include "header.h"

void drawingBoard(int **board, int row, int col);
bool checkLineY(int **board, int x1, int x2, int y);
bool checkLineX(int **board, int y1, int y2, int x);
bool checkLShape(int **board, int y1, int x1, int y2, int x2);
void matching(int **board, int row, int col, int characterBlock[], int &totalCharacter);
