#pragma once
#include "header.h"

//ready to set gameplay
void fontsize(int a, int b);
void clearScreen();
void gotoxy(SHORT x, SHORT y);
void setColor(int color);

//blocks' moving in different level
void level2(int **board, int row, int col);
void level3(int **board, int row, int col);
void level4(int **board, int row, int col);
void level5(int **board, int row, int col);
void levelMove(int **board, int row, int col, int level);

//move the blue key
void drawUnKey(int **board, int yr, int xr, char art[50][120], int y1, int x1);
void drawKey(int **board, int yr, int xr, int y1, int x1);

//draw the board for playing
void drawBorder(int color);
void drawingLine(int **board, int i, int j);
void drawingBoard(int **board, int row, int col, char bgArt[40][120]);
void drawOutsideBoard(int &level, Player &user);
