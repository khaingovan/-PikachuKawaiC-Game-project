#include "menu.h"
#include "leaderBoard.h"
#include "playMusic.h"


void generateMenu (int &row, int &col, int &roundSelect, int &Choice, string FileName)
{
    roundSelect = 1;
    Choice = 1;
    int directX = 85, directY = 19;

    clearScreen();
    backSound();
    
    while (true)
    {
        //out while loop
        if (roundSelect == -1)
            break;
        printMenu(roundSelect, Choice, FileName);
        getEvents(row, col, roundSelect, Choice);
    }
}

void getEvents(int &row, int &col,int &roundSelect, int &Choice)
{
    char button = getch();
    moveSound();
    switch (roundSelect)
    {
        //first screen 
        case 1:
        {
            switch(button)
            {
                //point to upper choice
                case KeyUp:
                {
                    Choice--;
                    if (Choice == 0)
                        Choice = 4;
                    break;                  
                }
                //point to below choice
                case KeyDown:
                {
                    Choice++;
                    if (Choice == 5)
                        Choice = 1;
                    break;
                }
                //to select
                case Space:
                {
                    if (Choice == 1)
                    {
                        //go to difficulty options screen
                        roundSelect = 2;
                        Choice = 1;
                    }
                    else if (Choice == 2)
                    {
                        //LeaderBoard
                        roundSelect = 4;
                    }
                    else if (Choice == 3)
                    {
                        //Credit
                        roundSelect = 3;
                    }
                    else if (Choice == 4)
                        //Quit
                        exit(0);
                    break;
                }
                case Esc:
                {
                    //Quit
                    exit(0);
                    break;
                }
            }
        break;
        }
        //Screen where choosing game difficulty
        case 2:
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
                            row = 6;
                            col = 6;
                            roundSelect = -1;        
                            break;
                        }
                        case (2):
                        {
                            row = 8;
                            col = 10;
                            roundSelect = -1;
                            break;
                        }
                        case (3):
                        {
                            row = 8;
                            col = 20;
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
    setColor(6);
    /*
    cout << "\t\t\t\t\t\t\t\t  ____    _   _                     _             " << endl;
    cout << "\t\t\t\t\t\t\t\t |  _ `  (_) | | __   __ _    ___  | |__    _   _ " << endl;
    cout << "\t\t\t\t\t\t\t\t | |_) | | | | |/ /  / _` |  / __| | '_ `. | | | |" << endl;
    cout << "\t\t\t\t\t\t\t\t |  __/  | | |   <  | (_| | | (__  | | | | | |_| |" << endl;
    cout << "\t\t\t\t\t\t\t\t |_|     |_| |_|`.|  `__,_|  `___| |_| |_|  `__,_|" << "\n\n";
    */
    cout << "\t\t\t\t\t\t\t\t __________  .__   __                       .__            "<< endl;                                                                                                                                                                               
    cout << "\t\t\t\t\t\t\t\t \\______   \\ |__| |  | __ _____      ____   |  |__    __ __ "<< endl;                                                                                                                                                                               
    cout << "\t\t\t\t\t\t\t\t  |     ___/ |  | |  |/ / \\__  \\   _/ ___\\  |  |  \\  |  |  \\"<< endl;                                                                                                                                                                               
    cout << "\t\t\t\t\t\t\t\t  |    |     |  | |    <   / __ \\_ \\  \\___  |   Y  \\ |  |  /"<< endl;
    cout << "\t\t\t\t\t\t\t\t  |____|     |__| |__|_ \\ /____  /  \\___  > |___|  / |____/ "<< endl;
    cout << "\t\t\t\t\t\t\t\t                       \\/      \\/       \\/       \\/        "<< endl;
    setColor(7);

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
                setColor(11);
                cout << "   << Play >>    " << endl;
                printMenuBox (directX - 2, directY - 2);
                gotoxy(directX - 4, 22);
                setColor(7);
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

                setColor(11);
                printMenuBox (directX - 2, directY + 2);
                gotoxy(directX - 4, 22);
                cout << "<< LeaderBoard >>  " << endl;

                gotoxy(directX - 4, 26);
                setColor(7);
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

                setColor(11);
                printMenuBox (directX - 2, directY + 6);
                gotoxy(directX - 4, 26);
                
                cout << "  << Credit >>    " << endl;

                gotoxy(directX - 4, 30);
                setColor(7);
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

                setColor(11);
                printMenuBox (directX - 2, directY + 10);
                gotoxy(directX - 4, 30);
                cout << "   << Quit >>      " << endl;

                setColor(7);
            }
            break;
        }
        case 2:
        {
            if (Choice == 1)
            {
                //clear old boxs
                deleteMenuBox(directX - 2, directY + 2);
                deleteMenuBox(directX - 2, directY + 6);
                deleteMenuBox(directX - 2, directY + 10);

                gotoxy(directX - 2, 18);
                setColor(11);
                cout << " << Easy >>    " << endl;
                printMenuBox(directX - 2, directY - 2);        

                setColor(7);
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

                setColor(11);
                gotoxy(directX - 2, 22);
                cout << " << Normal >>  " << endl;
                printMenuBox(directX - 2, directY + 2);

                setColor(7);
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
                setColor(11);
                cout << " << Hard >>   " << endl;
                printMenuBox(directX - 2, directY + 6);

                setColor(7);
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

                setColor(11);
                gotoxy(directX - 2, 30);
                cout << " << Crazy >>  " << endl;
                printMenuBox(directX - 2, directY + 10);
                setColor(7);
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
    setColor(6);
    cout << "\t\t\t\t\t\t\t        ____                     _   _   _             \n"; 
    cout << "\t\t\t\t\t\t\t       / ___|  _ __    ___    __| | (_) | |_   ___    \n"; 
    cout << "\t\t\t\t\t\t\t      | |     | '__|  / _ `  / _` | | | | __| / __|   \n"; 
    cout << "\t\t\t\t\t\t\t      | |___  | |    |  __/ | (_| | | | | |_ .\\__ \\   \n"; 
    cout << "\t\t\t\t\t\t\t       `____| |_|     `___|  `__,_| |_| '__./ |___/   \n\n"; 

    cout << "\t\t\t\t\t\t\t\t\t\t Pikachu Game \n";
    cout << "\t\t\t\t\t\t\t\t Programming Technique's Course Project \n";
    setColor(13);
    cout << "\t\t\t\t\t\t\t\t Programmed and Designed by \n";
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " Ngo Van Khai" << setfill(' ')  << "22127174 \n";
    cout << "\t\t\t\t\t\t\t\t" << left << setw(30) << " Nguyen Quoc Tin" << setfill(' ')  << "22127416 \n";
    
    setColor(3);
    cout << "\t\t\t\t\t\t\t   This is our first game. Hope you have good experience\n";
    cout << "\t\t\t\t\t\t\t\t\t\t Thank you!!";
    gotoxy(directX - 8, directY + 10);
    setColor(8);
    cout << " Press ESC to exit";

    setColor(7);
}
