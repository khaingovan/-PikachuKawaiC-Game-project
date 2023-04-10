#include "Menu.h"
void generateMenu (int &line, int &col, int &roundSelect, int &Choice, string FileName)
{
    roundSelect = 1;
    Choice = 1;
    int directX = 85, directY = 19;

    clearScreen();
    backSound();
    
    while (true)
    {  
        if (roundSelect == -1)   // out while loop
            break;
        printMenu(roundSelect, Choice, FileName);
        getEvents(line, col, roundSelect, Choice);
    }
}

void getEvents(int &line, int &col,int &roundSelect, int &Choice)
{
    char button = getch();
    moveSound();
    switch (roundSelect)
    {
        case 1: //first screen 
        {
            switch(button)
            {
                case KeyUp: //point to upper choice
                {
                    Choice--;
                    if (Choice == 0)
                        Choice = 4;
                    break;                  
                }
                case KeyDown:   //point to below choice
                {
                    Choice++;
                    if (Choice == 5)
                        Choice = 1;
                    break;
                }
                case Space: //to select
                {
                    if (Choice == 1)
                    {
                        roundSelect = 2; // chọn độ khó
                        Choice = 1;
                    }
                    else if (Choice == 2)
                    {
                        roundSelect = 4; // LeaderBoard
                    }
                    else if (Choice == 3)
                    {
                        roundSelect = 3; //Credit
                    }
                    else if (Choice == 4)     // Quit
                        exit(0);
                    break;
                }
                case Esc:
                {
                    exit(0);        //Quit
                    break;
                }
            }
        break;
        }
        case 2:     //Screen where choose difficult
        {
            switch(button)
            {
                case KeyUp:
                {
                    Choice--;
                    if (Choice == 0)
                        Choice = 4;
                    break;                  
                }
                case KeyDown:
                {
                    Choice++;
                    if (Choice == 5)
                        Choice = 1;
                    break;
                }
                case Space:
                { 
                    switch (Choice)
                    {
                        case (1):
                        {
                            line = 4;
                            col = 4;
                            roundSelect = -1;        
                            break;
                        }
                        case (2):
                        {
                            line = 6;
                            col = 6;
                            roundSelect = -1;
                            break;
                        }
                        case (3):
                        {
                            line = 10;
                            col = 10;
                            roundSelect = -1;
                            break;
                        }
                    }
                    break;
                }
                case Esc:
                {
                    clearScreen();
                    roundSelect = 1;
                    Choice = 1;
                }
            }
        break;
        }
        case 3: case 4:
        {
            if (button == Esc)
            {
                clearScreen();
                roundSelect = 1;
                Choice = 1;
            }
            break;
        }
    }
}

void printMenu(int roundSelect, int Choice, string FileName)
{
    int directX = 85, directY = 19;
    gotoxy(0,9);
    SET_COLOR(6);
    cout << "\t\t\t\t\t\t\t\t  ____    _   _                     _             " << endl;
    cout << "\t\t\t\t\t\t\t\t |  _ `  (_) | | __   __ _    ___  | |__    _   _ " << endl;
    cout << "\t\t\t\t\t\t\t\t | |_) | | | | |/ /  / _` |  / __| | '_ `. | | | |" << endl;
    cout << "\t\t\t\t\t\t\t\t |  __/  | | |   <  | (_| | | (__  | | | | | |_| |" << endl;
    cout << "\t\t\t\t\t\t\t\t |_|     |_| |_|`.|  `__,_|  `___| |_| |_|  `__,_|" << "\n\n";
    SET_COLOR(7);

    switch (roundSelect)
    {
        case 1:
        {
            if (Choice == 1)
            {
                //delete old boxs
                deleteMenuBox(directX - 2, directY + 2);
                deleteMenuBox(directX - 2, directY + 6);
                deleteMenuBox(directX - 2, directY + 10);

                gotoxy(directX - 4, 18);
                SET_COLOR(11);
                cout << "   << Play >>    " << endl;
                printMenuBox (directX - 2, directY - 2);
                gotoxy(directX - 4, 22);
                SET_COLOR(7);
                cout << "   LeaderBoard   " << endl;

                gotoxy(directX - 4, 26);
                cout << "     Credit     " << endl;

                gotoxy(directX - 4, 30);
                cout << "      Quit      " << endl;
            }
            else if (Choice == 2)
            {
                //delete old boxs
                deleteMenuBox(directX - 2, directY - 2);
                deleteMenuBox(directX - 2, directY + 6);
                deleteMenuBox(directX - 2, directY + 8);

                gotoxy(directX - 4, 18);
                cout << "      Play       " << endl;

                SET_COLOR(11);
                printMenuBox (directX - 2, directY + 2);
                gotoxy(directX - 4, 22);
                cout << "<< LeaderBoard >>  " << endl;

                gotoxy(directX - 4, 26);
                SET_COLOR(7);
                cout << "     Credit      " << endl;

                gotoxy(directX - 4, 30);
                cout << "      Quit       "  << endl;
            }
            else if (Choice == 3)
            {
                //delete old boxs
                deleteMenuBox(directX - 2, directY - 2);
                deleteMenuBox(directX - 2, directY + 2);
                deleteMenuBox(directX - 2, directY + 10);

                gotoxy(directX - 4, 18);
                cout << "      Play       " << endl;

                gotoxy(directX - 4, 22);
                cout << "   LeaderBoard   " << endl;

                SET_COLOR(11);
                printMenuBox (directX - 2, directY + 6);
                gotoxy(directX - 4, 26);
                
                cout << "  << Credit >>    " << endl;

                gotoxy(directX - 4, 30);
                SET_COLOR(7);
                cout << "      Quit       " << endl;
            }
            else if (Choice == 4)
            {
                //delete old boxs
                for (int i = 0; i < 4; i++)
                    deleteMenuBox(directX - 2, directY - 2 + i*4);
                gotoxy(directX - 4, 18);
                cout << "      Play        " << endl;

                gotoxy(directX - 4, 22);
                cout << "   LeaderBoard    " << endl;

                gotoxy(directX - 4, 26);
                cout << "     Credit       " << endl;

                SET_COLOR(11);
                printMenuBox (directX - 2, directY + 10);
                gotoxy(directX - 4, 30);
                cout << "   << Quit >>      " << endl;

                SET_COLOR(7);
            }
            break;
        }
        case 2:
        {
            if (Choice == 1)
            {
                //clear old boxs
                // deleteMenuBox(directX - 2, directY - 2);
                deleteMenuBox(directX - 2, directY + 2);
                deleteMenuBox(directX - 2, directY + 6);
                deleteMenuBox(directX - 2, directY + 10);
                // gotoxy(directX - 7, 18);
                // cout <<"                    ";
                // gotoxy(directX - 7, 22);
                // cout <<"                    ";

                gotoxy(directX - 2, 18);
                SET_COLOR(11);
                cout << " << Easy >>    " << endl;
                printMenuBox(directX - 2, directY - 2);        

                SET_COLOR(7);
                gotoxy(directX - 2, 22);
                cout << "    Normal    " << endl;
                gotoxy(directX - 2, 26);
                cout << "    Hard      " << endl;
                gotoxy(directX - 2, 30);
                cout << "    Crazy     " << endl;
                
            }
            else if (Choice == 2)
            {
                //clear old boxs
                deleteMenuBox(directX - 2, directY - 2);
                deleteMenuBox(directX - 2, directY + 6);
                deleteMenuBox(directX - 2, directY + 10);
                gotoxy(directX - 2, 18);
                cout << "    Easy      " << endl;

                SET_COLOR(11);
                gotoxy(directX - 2, 22);
                cout << " << Normal >>  " << endl;
                printMenuBox(directX - 2, directY + 2);

                SET_COLOR(7);
                gotoxy(directX - 2, 26);
                cout << "    Hard      " << endl;
                gotoxy(directX - 2, 30);
                cout << "    Crazy     " << endl;
            } 
            else if (Choice == 3)
            {
                //clear old boxs
                deleteMenuBox(directX - 2, directY - 2);
                deleteMenuBox(directX - 2, directY + 2);
                deleteMenuBox(directX - 2, directY + 10);
                gotoxy(directX - 2, 18);
                cout << "    Easy      " << endl;
                gotoxy(directX - 2, 22);
                cout << "    Normal    " << endl;

                gotoxy(directX - 2, 26);
                SET_COLOR(11);
                cout << " << Hard >>   " << endl;
                printMenuBox(directX - 2, directY + 6);

                SET_COLOR(7);
                gotoxy(directX - 2, 30);
                cout << "    Crazy     " << endl;
            }
            else if (Choice == 4)
            {
                //clear old boxs
                deleteMenuBox(directX - 2, directY - 2);
                deleteMenuBox(directX - 2, directY + 2);
                deleteMenuBox(directX - 2, directY + 6);
                gotoxy(directX - 2, 18);
                cout << "    Easy      " << endl;
                gotoxy(directX - 2, 22);
                cout << "    Normal    " << endl;
                gotoxy(directX - 2, 26);
                cout << "    Hard      " << endl;

                SET_COLOR(11);
                gotoxy(directX - 2, 30);
                cout << " << Crazy >>  " << endl;
                printMenuBox(directX - 2, directY + 10);
                SET_COLOR(7);
            }
            break;
        }
        case 3:
        {
            clearScreen();
            printCredit();
            break;
        }
        case 4:
        {
            clearScreen();
            gotoxy(0, 6);
            printLeaderBoard(FileName);
            break;
        }
    }

}
void printCredit()
{
    int directX = 85, directY = 19;
    backSound();
    gotoxy(0, 12);
    SET_COLOR(6);
    cout << "\t\t\t\t\t\t\t        ____                     _   _   _             \n"; 
    cout << "\t\t\t\t\t\t\t       / ___|  _ __    ___    __| | (_) | |_   ___    \n"; 
    cout << "\t\t\t\t\t\t\t      | |     | '__|  / _ `  / _` | | | | __| / __|   \n"; 
    cout << "\t\t\t\t\t\t\t      | |___  | |    |  __/ | (_| | | | | |_ .\\__ \\   \n"; 
    cout << "\t\t\t\t\t\t\t       `____| |_|     `___|  `__,_| |_| '__./ |___/   \n\n"; 

    cout << "\t\t\t\t\t\t\t\t\t\t Pikachu Game \n";
    cout << "\t\t\t\t\t\t\t\t Programming Technique's Course Project \n";
    SET_COLOR(13);
    cout << "\t\t\t\t\t\t\t\t Programmed and Designed by \n";
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " Ngo Van Khai" << setfill(' ')  << "22127174 \n";
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " Nguyen Quoc Tin" << setfill(' ')  << "22127416 \n";
    
    SET_COLOR(3);
    cout << "\t\t\t\t\t\t\t   This is our first game. Hope you have good experience\n";
    cout << "\t\t\t\t\t\t\t\t\t\t Thank you!!";
    gotoxy(directX - 8, directY + 10);
    SET_COLOR(8);
    cout << " Press ESC to exit";

    SET_COLOR(7);
}
