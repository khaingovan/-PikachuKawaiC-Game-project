#include "Menu.h"
void generateMenu (int &line, int &col, int &roundSelect, int &Choice)
{
    roundSelect = 1;
    Choice = 1;

    cout << "_|_|_|    _|  _|                            _|                 "<< endl;                                                                                                                                                                               
    cout << "_|    _|      _|  _|      _|_|_|    _|_|_|  _|_|_|    _|     _| "<< endl;
    cout << "_|_|_|    _|  _|_|      _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "_|        _|  _|  _|    _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "_|        _|  _|    _|    _|_|_|    _|_|_|  _|    _|    _|_|_|  \n\n";
    cout << "\t Press Space to continue!!" << endl;
    char button = getch();
    if (button = Space)
        clearScreen();

    Sleep(500); // menu screen will stop in 500 millisecond
    while (true)
    {  
        if (roundSelect == 5)   // out while loop
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
        case 1:
        {
            switch(button)
            {
                case KeyUp:
                {
                    Choice--;
                    if (Choice == 0)
                        Choice = 3;
                    break;                  
                }
                case KeyDown:
                {
                    Choice++;
                    if (Choice == 4)
                        Choice = 1;
                    break;
                }
                case Space:
                {
                    if (Choice == 1)
                    {
                        roundSelect = 2; // chọn độ khó
                        Choice = 1;
                    }
                    else if (Choice == 2)
                    {
                        roundSelect = 3; //Credit
                    }
                    else if (Choice == 3)     // Quit
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
                            line = 4;
                            col = 4;
                            roundSelect = 5;        
                            break;
                        }
                        case (2):
                        {
                            line = 6;
                            col = 6;
                            roundSelect = 5;
                            break;
                        }
                        case (3):
                        {
                            line = 10;
                            col = 10;
                            roundSelect = 5;
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
        case 3:
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
    cout << "\t\t Pikachu" << endl;
    switch (roundSelect)
    {
        case 1:
        {
            if (Choice == 1)
            {
                cout << "\t\t <<Play>>" << endl;
                cout << "\t\t  Credit" << endl;
                cout << "\t\t  Quit      " << endl;
            }
            else if (Choice == 2)
            {
                cout << "\t\t Play" << endl;
                cout << "\t\t<<Credit>>" << endl;
                cout << "\t\t Quit        " << endl;
            }
            else if (Choice == 3)
            {
                cout << "\t\t Play" << endl;
                cout << "\t\t Credit" << endl;
                cout << "\t\t<<Quit>>      " << endl;
            }
            break;
        }
        case 2:
        {
            if (Choice == 1)
            {
                cout << "\t\t<<Easy>>" << endl;
                cout << "\t\t Normal" << endl;
                cout << "\t\t Hard" << endl;
                cout << "\t\t Crazy" << endl;
                
            }
            else if (Choice == 2)
            {
                cout << "\t\t Easy" << endl;
                cout << "\t\t<<Normal>>" << endl;
                cout << "\t\t Hard" << endl;
                cout << "\t\t Crazy" << endl;
            }
            else if (Choice == 3)
            {
                cout << "\t\t Easy" << endl;
                cout << "\t\t Normal" << endl;
                cout << "\t\t<<Hard>>" << endl;
                cout << "\t\t Crazy" << endl;
            }
            else if (Choice == 4)
            {
                cout << "\t\t Easy" << endl;
                cout << "\t\t Normal" << endl;
                cout << "\t\t Hard" << endl;
                cout << "\t\t<<Crazy>>" << endl;
            }
            break;
        }
        case 3:
        {
            clearScreen();
            printCredit();
            break;
        }
    }

}
void printCredit()
{
    SET_COLOR(6);
    cout << "\t\t\t   ____                     _   _   _      \n"; 
    cout << "\t\t\t  / ___|  _ __    ___    __| | (_) | |_    \n"; 
    cout << "\t\t\t | |     | '__|  / _ `  / _` | | | | __|   \n"; 
    cout << "\t\t\t | |___  | |    |  __/ | (_| | | | | |_ .   \n"; 
    cout << "\t\t\t  `____| |_|     `___|  `__,_| |_| '__./   \n\n"; 

    cout << "\t\t\t\t\t Pikachu Game \n";
    cout << "\t\t\t Programming Technique's Course Project \n";
    SET_COLOR(13);
    cout << "\t\t\t Programmed and Designed by \n";
    cout << "\t\t\t" << left << setw(30) << " Ngo Van Khai" << setfill(' ')  << "22127174 \n";
    cout << "\t\t\t" << left << setw(30) << " Nguyen Quoc Tin" << setfill(' ')  << "22127416 \n";
    
    SET_COLOR(3);
    cout << "\t\t This is our first game. Hope you have good experience\n";
    cout << "\t\t\t\t\t Thank you!!";
}
  
