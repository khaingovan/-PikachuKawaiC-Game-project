#include "Account.h"

void signUp(string FileName)
{
    fstream fout(FileName, ios::binary|ios::app);

    if (!fout.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }

    Player newguy;
    cout << "Please input Username (less than 16 characters): ";
    cin.getline (newguy.username, 16);
    bool valid = isValidAcc(FileName, newguy.username);

    if (sizeof(newguy.username) > 17 || valid)
        signUp(FileName);
    
    cout << "Please input Password (only 8 characters): ";
    cin.getline (newguy.password, 8);
    if (sizeof(newguy.username) > 9)
        signUp(FileName);

    int zero = 0;
    while (!fout.eof())
    {
        fout.seekp(ios::end);
        fout.write((char*)&newguy.username, 16);
        fout.write((char*)&newguy.password, 8);
        fout.write((char*)&zero,4);
        fout.write((char*)&newguy.savedStage, 108);
    }
    
}
void signIn(string FileName);

bool isValidAcc(string FileName, char username[16])
{
    fstream fout(FileName, ios::binary|ios::in);
    if (!fout.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }
    bool valid = false;
    string *name = new string[100];
    int i = 0;

    while (!fout.eof())
    {
        fout.read((char*)&name[i], 16);
        i++;
        fout.seekg(144, ios::cur);
    }

    int size = i; //number of account in File

    for (int i = 0; i < size; i++)
    {
        if (strcmp(username, name[i].c_str()) == 0)
            valid = true;
    }

    delete[] name;
    return valid;
}