#include "Menu.h"

void printMenu(int line, int col, int roundSelect, int Choice, int gameMode)
{
    system("cls");
    char botton;

    cout << "_|_|_|    _|  _|                            _|                 "<< endl;                                                                                                                                                                               
    cout << "_|    _|      _|  _|      _|_|_|    _|_|_|  _|_|_|    _|     _| "<< endl;
    cout << "_|_|_|    _|  _|_|      _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "_|        _|  _|  _|    _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "_|        _|  _|    _|    _|_|_|    _|_|_|  _|    _|    _|_|_|  \n\n";
    cout << "\t Press any button to continue!!";


    if(getch()) // kiểm tra nếu người dùng nhập phím hay không
        system("cls");
    
    cout << "\t\t Pikachu" << endl;
    roundSelect = 3;
    cin >> Choice;
    switch (roundSelect)
    {
        case 1:
        {
            if (Choice == 1)
            {
                cout << "\t\t <<Play>>" << endl;
                cout << "\t\t  Credit" << endl;
                cout << "\t\t  Quit" << endl;
            }
            else if (Choice == 2)
            {
                cout << "\t\t Play" << endl;
                cout << "\t\t<<Credit>>" << endl;
                cout << "\t\t Quit" << endl;
            }
            else if (Choice == 3)
            {
                cout << "\t\t Play" << endl;
                cout << "\t\t Credit" << endl;
                cout << "\t\t<<Quit>>" << endl;
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
            cout << "credit";
        }
        case 4:
        {
            break;
        }
    }

}
  