#pragma once
#include "header.h"

//https://cplusplus.com/forum/general/70677/
inline void wait ( short seconds );
inline void countDown();

void createBoard(mainScreen &game, characterBlockInfor &CBI, int roundSelect);
void playPikachu(Player &user, mainScreen &game, int roundSelect);