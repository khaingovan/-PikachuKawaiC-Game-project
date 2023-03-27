#pragma once
#include "header.h"

void clearScreen();
void checkLineX(int **board, int x1, int x2, int y, int &matchShape);
void checkLineY(int **board, int y1, int y2, int x, int &matchShape);
bool checkLShape(int **board, int y1, int x1, int y2, int x2);
bool isLegalMatch(int **board, int row, int col, int y1, int x1, int y2, int x2);
bool testingBoard(int **board, int row, int col, int totalCharacter);
void matching(int **board, int row, int col, int characterBlock[], int &totalCharacter, int totalDifferentCharacter);
void shuffleBoard(int **board, int row, int col, int characterBlock[], int totalCharacter, int totalDifferentCharacter);
void deleteBoard(int **board, int col);
