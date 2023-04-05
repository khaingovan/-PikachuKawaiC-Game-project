#include "Menu.h"
void generateMenu (int &line, int &col, int &roundSelect, int &Choice)
{
    roundSelect = 1;
    Choice = 1;
    
    SET_COLOR(6);
    gotoxy(0,10);
    
    cout << "\t\t\t\t _|_|_|    _|  _|                            _|                 "<< endl;                                                                                                                                                                               
    cout << "\t\t\t\t _|    _|      _|  _|      _|_|_|    _|_|_|  _|_|_|    _|     _| "<< endl;
    cout << "\t\t\t\t _|_|_|    _|  _|_|      _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "\t\t\t\t _|        _|  _|  _|    _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "\t\t\t\t _|        _|  _|    _|    _|_|_|    _|_|_|  _|    _|    _|_|_|  \n\n";
    cout << "\t\t\t\t\t\t Press Space to continue!!" << endl;
    char button = getch();
    if (button = Space)
        clearScreen();

    Sleep(500); // menu screen will stop in 500 millisecond
    SET_COLOR(7);
    while (true)
    {  
        if (roundSelect == -1)   // out while loop
            break;  
        printMenu(roundSelect, Choice);
        getEvents(line, col, roundSelect, Choice);
        clearScreen();
    }
}

void getEvents(int &line, int &col,int &roundSelect, int &Choice)
{
    char button = getch();
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
                roundSelect = 1;
                Choice = 1;
            }
            break;
        }
    }
}

void printMenu(int roundSelect, int Choice)
{
    gotoxy(0,9);
    SET_COLOR(6);
    cout << "\t\t\t\t  ____    _   _                     _             " << endl;
    cout << "\t\t\t\t |  _ `  (_) | | __   __ _    ___  | |__    _   _ " << endl;
    cout << "\t\t\t\t | |_) | | | | |/ /  / _` |  / __| | '_ `. | | | |" << endl;
    cout << "\t\t\t\t |  __/  | | |   <  | (_| | | (__  | | | | | |_| |" << endl;
    cout << "\t\t\t\t |_|     |_| |_|`.|  `__,_|  `___| |_| |_|  `__,_|" << "\n\n";
    SET_COLOR(7);
    switch (roundSelect)
    {
        case 1:
        {
            if (Choice == 1)
            {
                SET_COLOR(11);
                cout << "\t\t\t\t\t\t   <<Play>>" << endl;
                SET_COLOR(7);
                cout << "\t\t\t\t\t\t  LeaderBoard" << endl;
                cout << "\t\t\t\t\t\t    Credit" << endl;
                cout << "\t\t\t\t\t\t     Quit      " << endl;
            }
            else if (Choice == 2)
            {
                cout << "\t\t\t\t\t\t     Play" << endl;
                SET_COLOR(11);
                cout << "\t\t\t\t\t\t<<LeaderBoard>>" << endl;
                SET_COLOR(7);
                cout << "\t\t\t\t\t\t    Credit" << endl;
                cout << "\t\t\t\t\t\t     Quit      "  << endl;
            }
            else if (Choice == 3)
            {
                cout << "\t\t\t\t\t\t     Play" << endl;
                cout << "\t\t\t\t\t\t  LeaderBoard" << endl;
                SET_COLOR(11);
                cout << "\t\t\t\t\t\t  <<Credit>>" << endl;
                SET_COLOR(7);
                cout << "\t\t\t\t\t\t     Quit        " << endl;
            }
            else if (Choice == 4)
            {
                cout << "\t\t\t\t\t\t     Play" << endl;
                cout << "\t\t\t\t\t\t  LeaderBoard" << endl;
                cout << "\t\t\t\t\t\t    Credit" << endl;
                SET_COLOR(11);
                cout << "\t\t\t\t\t\t   <<Quit>>      " << endl;
                SET_COLOR(7);
            }
            break;
        }
        case 2:
        {
            if (Choice == 1)
            {
                SET_COLOR(11);
                cout << "\t\t\t\t\t\t <<Easy>>" << endl;
                SET_COLOR(7);
                cout << "\t\t\t\t\t\t   Normal" << endl;
                cout << "\t\t\t\t\t\t   Hard" << endl;
                cout << "\t\t\t\t\t\t   Crazy" << endl;
                
            }
            else if (Choice == 2)
            {
                cout << "\t\t\t\t\t\t   Easy" << endl;
                SET_COLOR(11);
                cout << "\t\t\t\t\t\t <<Normal>>" << endl;
                SET_COLOR(7);
                cout << "\t\t\t\t\t\t   Hard" << endl;
                cout << "\t\t\t\t\t\t   Crazy" << endl;
            }
            else if (Choice == 3)
            {
                cout << "\t\t\t\t\t\t   Easy" << endl;
                cout << "\t\t\t\t\t\t   Normal" << endl;
                SET_COLOR(11);
                cout << "\t\t\t\t\t\t  <<Hard>>" << endl;
                SET_COLOR(7);
                cout << "\t\t\t\t\t\t   Crazy" << endl;
            }
            else if (Choice == 4)
            {
                cout << "\t\t\t\t\t\t   Easy" << endl;
                cout << "\t\t\t\t\t\t   Normal" << endl;
                cout << "\t\t\t\t\t\t   Hard" << endl;
                SET_COLOR(11);
                cout << "\t\t\t\t\t\t  <<Crazy>>" << endl;
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
            cout << "Leader Board"; // Sẽ viết sau
            break;
        }
    }

}
void printCredit()
{
    gotoxy(0, 4);
    SET_COLOR(6);
    cout << "\t\t\t\t\t   ____                     _   _   _      \n"; 
    cout << "\t\t\t\t\t  / ___|  _ __    ___    __| | (_) | |_    \n"; 
    cout << "\t\t\t\t\t | |     | '__|  / _ `  / _` | | | | __|   \n"; 
    cout << "\t\t\t\t\t | |___  | |    |  __/ | (_| | | | | |_ .   \n"; 
    cout << "\t\t\t\t\t  `____| |_|     `___|  `__,_| |_| '__./   \n\n"; 

    cout << "\t\t\t\t\t\t\t Pikachu Game \n";
    cout << "\t\t\t\t\t Programming Technique's Course Project \n";
    SET_COLOR(13);
    cout << "\t\t\t\t\t Programmed and Designed by \n";
    cout << "\t\t\t\t\t" << left << setw(30) << " Ngo Van Khai" << setfill(' ')  << "22127174 \n";
    cout << "\t\t\t\t\t" << left << setw(30) << " Nguyen Quoc Tin" << setfill(' ')  << "22127416 \n";
    
    SET_COLOR(3);
    cout << "\t\t\t\t This is our first game. Hope you have good experience\n";
    cout << "\t\t\t\t\t\t\t Thank you!!";
    gotoxy(53,25);
    SET_COLOR(8);
    cout << " Press ESC to exit";

    SET_COLOR(7);
}