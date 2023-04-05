#include "Account.h"

void generateAccScreen(int &roundSelect, int &Choice, string FileName, Player &oldMan, unsigned int &index)
{
    roundSelect = 0;

    gotoxy(0,10);
    SET_COLOR(6);
    cout << "\t\t\t\t _|_|_|    _|  _|                            _|                 "<< endl;                                                                                                                                                                               
    cout << "\t\t\t\t _|    _|      _|  _|      _|_|_|    _|_|_|  _|_|_|    _|     _| "<< endl;
    cout << "\t\t\t\t _|_|_|    _|  _|_|      _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "\t\t\t\t _|        _|  _|  _|    _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "\t\t\t\t _|        _|  _|    _|    _|_|_|    _|_|_|  _|    _|    _|_|_|  \n\n";
    cout << "\t\t\t\t\t\t Press Space to continue!!" << endl;
    char button = getch();
    if (button = Space)
        clearScreen();

    SET_COLOR(7);
    while(true)
    {
        
        clearScreen();
        if (roundSelect == 0)           //Print Login menu to choose to play as guest or member
        {
            gotoxy(0,10);                               
            printAccChoice(Choice);                     //show user screen
            selectAccChoice(roundSelect, Choice);       //get input from keyboard
        }
        
        if (roundSelect == -1)          //out screen to Menu 
            break;
        else if (roundSelect == 1)      //player choose Login
        {
            clearScreen();
            signIn(FileName, oldMan, index);    //login and get player info to Player oldMan
            break;
        }
        else if (roundSelect == 2)      //player choose Sign up
        {
            clearScreen();
            signUp(FileName);                   //new account
            roundSelect = 0;                    //back to login menu for player to choose log in
        }
    }

}

void printAccChoice(int Choice)
{
    switch(Choice)
    {
        case 1:
        {
            SET_COLOR(11);
            cout << "\t\t\t\t\t\t   <<Play as Guest>>  " << endl;
            cout << "\t\t\t\t\t\t  (Data will be lost) " << endl;
            SET_COLOR(7);
            cout << "\t\t\t\t\t\t        Log In        " << endl;
            cout << "\t\t\t\t\t\t        Sign Up       " << endl;
            break;
        }
        case 2:
        {
            cout << "\t\t\t\t\t\t     Play as Guest" << endl;
            SET_COLOR(11);
            cout << "\t\t\t\t\t\t      <<Log In>>" << endl;
            SET_COLOR(7);
            cout << "\t\t\t\t\t\t        Sign Up" << endl;
            break;
        }
        case 3:
        {
            cout << "\t\t\t\t\t\t     Play as Guest" << endl;
            cout << "\t\t\t\t\t\t        Log In " << endl;
            SET_COLOR(11);
            cout << "\t\t\t\t\t\t      <<Sign Up>>" << endl;
            SET_COLOR(7);
            break;
        }
    }
}

void selectAccChoice(int &roundSelect, int &Choice)
{
    char button = getch();
    switch (button)
    {
        case KeyUp: //point to upper choice
        {
            Choice--;
            if (Choice == 0)
            Choice = 3;
            break;                  
        }
        case KeyDown:   //point to below choice
        {
            Choice++;
            if (Choice == 4)
            Choice = 1;
            break;
        }        
        case Space:     //accept choice
        {
            if (Choice == 1)
            {
                roundSelect = -1;
            }              
            else if (Choice == 2)
            {
                roundSelect = 1;
            }
            else if (Choice == 3)
            {
                roundSelect = 2;
            }
            break;
        }
        case Esc:       //turn off console
        {
            exit(0);
        }
    }
}
void signUp(string FileName)
{
    Player newguy;
    unsigned index = 0;

    char confirm[17];           //check if user type wrong letter

    cout << "\t\t\t\t\t\t\tSIGN UP" << endl;
    //get Username and Password
    cout << "\t\t\t\tUsername (less than 16 characters): ";
    cin.getline (newguy.username, 17);
    cout << "\t\t\t\tPassword (no more than 14 characters): ";
    cin.getline (newguy.password, 15);
    cout << "\t\t\t\t\tConfirm password: ";
    cin.getline (confirm, 17);

    //check if the username exists,
    bool valid = isExistAcc(FileName, newguy.username, index);
    if (valid)
    {
        cout << "\t\t\t\t\t\t\tExisted Username!!";
        clearScreen();
        signUp(FileName);           //username is used then user need to type new username
    }
    else if (strcmp(confirm, newguy.password) != 0)     // check if confirm password is different from password
    {
        cout << "\t\t\t\t\t\t\tPassword is incorrect!!";
        Sleep(1000);
        clearScreen();              
        signUp(FileName);           //redo sign up if information provided is invalid
    }
    else
    {
        clearScreen();
        cout << "\t\t\t\t\t\t\tWelcome New Player";     // sign up successfully
    }
    
    // open file to store new user's account
    ofstream fout(FileName, ios::binary|ios::app);
    if (!fout.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }

    //New Account store nothing exept username and password
    newguy.record = 0;
    newguy.savedStage.numCol = 0;
    newguy.savedStage.numRow = 0;

    // Storing info in binary file
    fout.seekp(0, ios::end);
    fout.write(newguy.username, 17);
    fout.write(newguy.password, 15);
    fout.write((char*) &newguy.record, sizeof(unsigned int));
    fout.write((char*) &newguy.savedStage, sizeof(State));

    fout.close();
}

void signIn(string FileName, Player &oldMan, unsigned int &index)
{
    index = 0;  // index of account to search for password quickly
    
    cout << "\t\t\t\t\t\t\tLOGIN" << endl;
    cout << "\t\t\t\t\tUsername: ";
    cin.getline(oldMan.username, sizeof(oldMan.username));
    if(isExistAcc(FileName, oldMan.username, index))        //Check username if it is signed up then Check password is correct (similar to storing in file)
    {  
        cout << "\t\t\t\t\tPassword: ";
        cin.getline(oldMan.password, sizeof(oldMan.password));
        if(isPasswordCorrect(FileName, oldMan.password, index))        //compare the password with the stored one in SaveFile.dat
        {
            cout << "\t\t\t\t\t\t\tSuccess!!";
            getInfo(FileName, oldMan, index);                   //store info from file to variable (oldMan
        }
        else
        {
            cout << "\t\t\t\t\t\t\tWrong Password";
            clearScreen();
            signIn(FileName, oldMan, index);                    //sign in again
        }
    }    
    else                                                         
    {
        cout << "\t\t\t\t\t\t\tInvalid Account" << endl;
        cout << "\t\t\t\t\t\t\tPlease Sign Up" << endl;
        cout << "\t\t\t\t\tPress Space to try Login again Or Esc to SignUp" << endl;
        char button = getch();
        if (button == Esc)                                      //if players type wrong account, they can choose to sig in again or make the new one
        {
            clearScreen();
            signUp(FileName);                                   
            signIn(FileName, oldMan, index);
        }
        else if (button == Space)
        {
            clearScreen();
            signIn(FileName, oldMan, index);
        }

    }
    
    
}

bool isExistAcc(string FileName, char username[17], unsigned int &index)
{
    ifstream fin(FileName, ios::binary);
    if (!fin.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }
    
    fin.seekg(0, ios::end);     //point to the end of file
    int file_size = fin.tellg();    //size of file in bytes
    int numAcc = file_size/sizeof(struct Player);   //count a number of account signed up

    vector <string> name;   //Storing the signed Account
    char nameTemp[17];
    
    //if there is no acc signed up before, test will be skipped
    if (file_size == 0)
        return false;
    else
    {
        for (int i = 0; i < numAcc; i++)
        {
            fin.seekg(sizeof(struct Player) * i,ios::beg);  //point to the first element of the username
            fin.read(nameTemp, 17);         //read username
            name.push_back((string)nameTemp);
        }
    }
    fin.close();

    //check if a new username is similar with the valid username
    for (int i = 0; i < numAcc; i++)
    {
        if (strcmp(username, name[i].c_str()) == 0) 
        {
            index = i;
            return true;
        }
    }
    
    return false;

}

bool isPasswordCorrect(string FileName, char password[15], unsigned int index)
{
    char passTemp[15];
    bool Correct = false;
    ifstream fin(FileName, ios::binary);
    if (!fin.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }
    
    fin.seekg(17 + (sizeof(struct Player) * index) ,ios::beg);  //point to the first element of the password
    fin.read(passTemp, 15);         //read password (15 is size of password)
    
    if (strcmp(password, passTemp) == 0) 
        Correct = true;

    fin.close();
    return Correct;
}

void getInfo (string FileName, Player &oldMan, unsigned int index)
{
    ifstream fin(FileName, ios::binary);
    if (!fin.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }
    
    fin.seekg((sizeof(oldMan.username) + sizeof(oldMan.password)) + sizeof(Player)*index, ios::beg);        //point to the record of the indexth player
    fin.read((char*) &oldMan.record, sizeof(int));                                                      //read score and size of stage to Player oldMan
    fin.read((char*) &oldMan.savedStage, sizeof(oldMan.savedStage));
}

void updateScore(string FileName, Player &oldMan, unsigned int index, unsigned int newscore)
{
    vector <Player> List;
    Player temp;
    ifstream fin(FileName, ios::binary);
    if (!fin.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }
    
    fin.seekg(0, ios::end);     //point to the end of file
    int file_size = fin.tellg();    //size of file in bytes
    int numAcc = file_size/sizeof(struct Player);   //count the number of accounts signed up

    fin.seekg(0, ios::beg);
    for (int i = 0; i < numAcc; i++)
    {
        fin.read((char*) &temp, sizeof(Player));        //store all user's info to array List
        List.push_back(temp);
    }

    fin.close();

    List[index].record = newscore;      //update a new score , storing in file
    oldMan.record = newscore;           //in play time
    ofstream fout(FileName, ios::binary);
    if (!fout.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }

    fout.seekp(0, ios::beg);
    for (int i = 0; i < numAcc; i++)
    {
        fout.write((char*) &List[i], sizeof(Player));       //overwriting SaveFile
    }

    fout.close();
}
