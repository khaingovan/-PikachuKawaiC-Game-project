#pragma once
#include <iostream>
#include <Windows.h>
#include <Mmsystem.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "-lwinmm")

using namespace std;
void backSound()    //Play in background
{
    PlaySound(TEXT("Sounds\\ES_Sunday_Coffee_Rebecca_Mardal.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    //PlaySound(TEXT("Sounds\\ES_Sunday_Coffee_Rebecca_Mardal.wav"), 0, SND_FILENAME|SND_LOOP|SND_ASYNC);
}

void moveSound()     //Play while get control from keyboard
{
    PlaySound(TEXT("Sounds\\ES_Video Game Jump Play - SFX Producer.wav"), NULL, SND_FILENAME|SND_ASYNC);
}

void selectSound()     //Play While press Space
{                      //or 2 part is matching
    PlaySound(TEXT("Sounds\\ES_Arcade Game Tap 1 - SFX Producer.wav"), NULL, SND_FILENAME|SND_ASYNC);
}
