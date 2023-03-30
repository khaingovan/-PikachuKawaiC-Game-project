#include "Account.h"

void signUp(string FileName)
{
    ofstream fout(FileName, ios::binary|ios::app);
    if (!fout.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }

    //New Account store nothing exept username and password
    Player newguy;
    newguy.record = 0;
    newguy.savedStage.numCol = 0;
    newguy.savedStage.numRow = 0;
    newguy.savedStage.Board[0] = {NULL};
    
    //get Username and Password
    cout << "Please input Username (less than 16 characters): ";
    cin.getline (newguy.username, 17);
    cout << "Please input Password (no more than 14 characters): ";
    cin.getline (newguy.password, 15);

    //check if the username exists,
    bool valid = isExistAcc(FileName, newguy.username);
    if (valid)
    {
        cout << "Existed Username!!";
        signUp(FileName);           //username is used then user need to type new username
    }
    else cout << "Welcom New Player";

    // Storing info in binary file
    fout.seekp(0, ios::end);
    fout.write(newguy.username, 17);
    fout.write(newguy.password, 15);
    fout.write((char*) &newguy.record, sizeof(unsigned int));
    fout.write((char*) &newguy.savedStage, sizeof(State));

    fout.close();
}
void signIn(string FileName);

bool isExistAcc(string FileName, char username[17])
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
            return true;
    }
    
    return false;

}