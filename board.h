#pragma once
#include "header.h"

void clearScreen();
void checkLineX(int **board, int x1, int x2, int y, bool testing, int &matchShape, int *pcharacterLost);
void checkLineY(int **board, int y1, int y2, int x, bool testing, int &matchShape, int *pcharacterLost);
void checkLShape(int **board, int y1, int x1, int y2, int x2, bool testing, int &matchShape, int *pcharacterLost);
void checkUAndZShape(int **board, int row, int col, int y1, int x1, int y2, int x2, bool testing, int &matchShape, int *pcharacterLost);
void isLegalMatch(int **board, int row, int col, int y1, int x1, int y2, int x2, characterBlockInfor &CBI, bool testing, bool &legalMatch, int *pcharacterLost);
bool testingBoard(int **board, int row, int col, characterBlockInfor CBI, int *pcharacterLost);
void matching(int **board, int row, int col, characterBlockInfor &CBI, int &level);
void shuffleBoard(int **board, int row, int col, characterBlockInfor CBI);
void deleteBoard(int **board, int col, characterBlockInfor CBI);
