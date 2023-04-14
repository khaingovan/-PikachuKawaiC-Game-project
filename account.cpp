#pragma once
#include "account.h"
#include "printDesign.h"

void generateAccScreen(int &roundSelect, int Choice, string FileName, Player &oldMan, unsigned int &index)
{
    roundSelect = 0;

    //7 = 0*16 + 7 default white text black background
    setColor(7);
    while(true)
    {
        //Print Login menu to choose to play as guest or member
        if (roundSelect == 0)
        {
            gotoxy(0,10);                               
            printAccChoice(Choice);                 //show user screen
            selectAccChoice(roundSelect, Choice);   //get input from keyboard
        }
        
        //out screen to Menu
        if (roundSelect == -1)
            break;
        //player choose Login
        else if (roundSelect == 1)
        {
            clearScreen();
            signIn(FileName, oldMan, index);        //login and get player info to Player oldMan
            break;
        }
        //player choose Sign up
        else if (roundSelect == 2)
        {
            clearScreen();
            signUp(FileName);                       //new account
            roundSelect = 0;                        //back to login menu for player to choose log in
        }
    }

}

void printAccChoice(int Choice)
{
    int directX = 85, directY = 19;
    //6 = 0*16 + 6 yellow text black background
    setColor(6);
    cout << "\t\t\t\t\t\t\t\t __________  .__   __                       .__            "<< endl;                                                                                                                                                                               
    cout << "\t\t\t\t\t\t\t\t \\______   \\ |__| |  | __ _____      ____   |  |__    __ __ "<< endl;                                                                                                                                                                               
    cout << "\t\t\t\t\t\t\t\t  |     ___/ |  | |  |/ / \\__  \\   _/ ___\\  |  |  \\  |  |  \\"<< endl;                                                                                                                                                                               
    cout << "\t\t\t\t\t\t\t\t  |    |     |  | |    <   / __ \\_ \\  \\___  |   Y  \\ |  |  /"<< endl;
    cout << "\t\t\t\t\t\t\t\t  |____|     |__| |__|_ \\ /____  /  \\___  > |___|  / |____/ "<< endl;
    cout << "\t\t\t\t\t\t\t\t                       \\/      \\/       \\/       \\/        "<< endl;
    
    //7 = 0*16 + 7 default white text black background
    setColor(7);
    switch(Choice)
    {
        case 1:
        {
            //clear old boxs
            deleteChoiceBox(directX, directY + 4);
            deleteChoiceBox(directX, directY + 8);

            gotoxy(directX - 5, directY);
            setColor(11);
            cout << "  << Play as Guest >>  " << endl;
            gotoxy(directX - 6, directY + 1);
            cout << "   (Data will be lost) " << endl;
            printChoiceBox(directX, directY);

            //7 = 0*16 + 7 default white text black background
            setColor(7);
            gotoxy(directX, directY + 4);
            cout << "   Log In        " << endl;
            gotoxy(directX, directY + 8);
            cout << "   Sign Up       " << endl;
            break;
        }
        case 2:
        {
            //clear old boxs
            deleteChoiceBox(directX, directY);
            deleteChoiceBox(directX, directY + 8);

            gotoxy(directX - 3, directY);
            cout << "   Play as Guest       " << endl;
            gotoxy(directX - 6, directY + 1);
            cout << "                      " << endl;
            
            gotoxy(directX - 2, directY + 4);
            setColor(11);
            cout << "  << Log In >>        " << endl;
            printChoiceBox(directX, directY + 4);

            //7 = 0*16 + 7 default white text black background
            setColor(7);
            gotoxy(directX, directY + 8);
            cout << "   Sign Up            " << endl;
            break;
        }
        case 3:
        {
            //clear old boxs
            deleteChoiceBox(directX, directY);
            deleteChoiceBox(directX, directY + 4);

            gotoxy(directX - 3, directY);
            cout << "   Play as Guest           "<< endl;
            gotoxy(directX - 6, directY + 1);
            cout << "                      " << endl;

            gotoxy(directX, directY + 4);
            cout << "   Log In               " << endl;
    
            gotoxy(directX - 2, directY + 8);
            setColor(11);
            cout << "  << Sign Up >>            " << endl;
            printChoiceBox(directX, directY + 8);
            //7 = 0*16 + 7 default white text black background
            setColor(7);
            break;
        }
    }
}

void selectAccChoice(int &roundSelect, int &Choice)
{
    char button = getch();
    moveSound();
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
    int directX = 85, directY = 10;
    char confirm[17];           //check if user type wrong letter
    setColor(11);
    printSignUpBoard(directX, directY);

    gotoxy(directX + 2, directY);
    setColor(10);
    cout << "SIGN UP" << endl;
    
    //7 = 0*16 + 7 default white text black background
    setColor(7);
    gotoxy(directX - 8, directY + 3);
    
    cout << "Username " << endl;   //(less than 16 characters)

    gotoxy(directX - 8, directY + 7);
    cout << "Password " << endl;   //(no more than 14 characters)
    
    gotoxy(directX - 8, directY + 11);
    cout << "Confirm ";

    //4 = 0*16 + 4 red text black background
    setColor(4);
    gotoxy(directX - 8, directY + 15);
    cout << "Username must be LESS than 16 characters";
    gotoxy(directX - 8, directY + 16);
    cout << "Password is NO MORE THAN 14 characters";

    //7 = 0*16 + 7 default white text black background
    setColor(7);
    //get Username and Password
    gotoxy(directX + 10, directY + 3);
    cin.getline (newguy.username, 17);

    gotoxy(directX + 10, directY + 7);
    cin.getline (newguy.password, 15);

    gotoxy(directX + 10,directY + 11);
    cin.getline (confirm, 15);

    //check if the username exists,
    bool valid = isExistAcc(FileName, newguy.username, index);
    if (valid)
    {
        //4 = 0*16 + 4 red text black background
        setColor(4);
        gotoxy(directX, directY + 22);
        cout << "Existed Username!!          ";
        //7 = 0*16 + 7 default white text black background
        setColor(7);
        Sleep(1000);
        clearScreen();
        signUp(FileName);           //username is used then user need to type new username
    }
    else if (strcmp(confirm, newguy.password) != 0)     // check if confirm password is different from password
    {
        gotoxy(directX, directY + 22);
        //4 = 0*16 + 4 red text black background
        setColor(4);
        cout << "Password is incorrect!!        ";
        Sleep(1000);
        clearScreen();              
        signUp(FileName);           //redo sign up if information provided is invalid
    }
    else
    {
        //6 = 0*16 + 6 yellow text black background
        setColor(6);
        gotoxy(directX, directY + 22);
        cout << "Welcome New Player             ";     // sign up successfully
        Sleep(2000);
        clearScreen();
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
    int directX = 85, directY = 10;
    printSignInBoard(directX, directY);
    gotoxy(directX + 2, directY);
    setColor(10);
    cout << "LOGIN" << endl;

    //7 = 0*16 + 7 default white text black background
    setColor(7);
    gotoxy(directX - 8, directY + 3);
    cout << "Username " << endl;   //(less than 16 characters)

    gotoxy(directX - 8, directY + 7);
    cout << "Password " << endl;   //(no more than 14 characters)

    gotoxy(directX + 10, directY + 3);
    cin.getline(oldMan.username, sizeof(oldMan.username));

    gotoxy(directX + 10, directY + 7);
    cin.getline(oldMan.password, sizeof(oldMan.password));

    if(isExistAcc(FileName, oldMan.username, index))        //Check username if it is signed up then Check password is correct (similar to storing in file)
    {  
        if(isPasswordCorrect(FileName, oldMan.password, index))        //compare the password with the stored one in SaveFile.dat
        {
            //6 = 0*16 + 6 yellow text black background
            setColor(6);
            gotoxy(directX, directY + 22);
            cout << "Success!!";
            //7 = 0*16 + 7 default white text black background
            setColor(7);
            getInfo(FileName, oldMan, index);                   //store info from file to variable (oldMan
        }
        else
        {
            //4 = 0*16 + 4 red text black background
            setColor(4);
            gotoxy(directX, directY + 22);
            cout << "Wrong Password";
            Sleep(1000);
            //7 = 0*16 + 7 default white text black background
            setColor(7);
            signIn(FileName, oldMan, index);                    //sign in again
        }
    }    
    else                                                         
    {
        //4 = 0*16 + 4 red text black background
        setColor(4);
        gotoxy(directX, directY + 10);
        cout << "Invalid Account" << endl;
        gotoxy(directX, directY + 11);
        cout << "Please Sign Up" << endl;
        gotoxy(directX - 15, directY + 12);
        cout << "Press Space to try Login again Or Esc to SignUp" << endl;
        //7 = 0*16 + 7 default white text black background
        setColor(7);
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

void updateScore(string FileName, Player &oldMan, unsigned int index, int newscore)
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
