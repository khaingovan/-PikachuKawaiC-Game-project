#pragma once
#include "header.h"

//time counter
void countdown(time_t originalTime, int timeLeft, bool &overTime);

//game logic
void createBoard(mainScreen &game, characterBlockInfor &CBI, int roundSelect);
void playPikachu(Player &user, mainScreen &game, int roundSelect, bool accountLogedIn, int &scoreWhenOutGame);
