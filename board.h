#pragma once
#include "header.h"

//check I (horizontal-X and vertical-Y), L, U, Z line shape
void checkLineX(mainScreen &game, int x1, int x2, int y, bool testing, int &matchShape, int *pcharacterLost);
void checkLineY(mainScreen &game, int y1, int y2, int x, bool testing, int &matchShape, int *pcharacterLost);
void checkLShape(mainScreen &game, int y1, int x1, int y2, int x2, bool testing, int &matchShape, int *pcharacterLost);
void checkUAndZShape(mainScreen &game, int y1, int x1, int y2, int x2, bool testing, int &matchShape, int *pcharacterLost);

//functions for playing
void isLegalMatch(mainScreen &game, int y1, int x1, int y2, int x2, characterBlockInfor &CBI, bool testing, bool &legalMatch, int *pcharacterLost);
bool testingBoard(mainScreen &game, characterBlockInfor CBI, int *pcharacterLost);
void shuffleBoard(mainScreen &game, characterBlockInfor CBI);

//function for quiting (deleting the dynamic memory allocation)
void deleteBoard(mainScreen &game, characterBlockInfor CBI);
