#include "header.h"
//#include "OnlLib.h"
#include "Menu.cpp"
#include "ClearScreen.cpp"
int main()
{
    int roundSelect = 1, Choice = 1, col = 0, line = 0 ;

    generateMenu(line, col, roundSelect, Choice );
   
    return 0;
} 
