#include "LeaderBoard.h"

void printLeaderBoard(string FileName)
{
    vector <Player> Leader;
    Player temp;
    ifstream fin (FileName, ios::binary);
    if (!fin.is_open())
    {
        cout << "Error While Opening";
        exit(0);
    }
    fin.seekg(0, ios::end);     //point to the end of file
    int file_size = fin.tellg();    //size of file in bytes
    int numAcc = file_size/sizeof(struct Player);   //count the number of accounts signed up

    fin.seekg(0, ios::beg);        //point to the record of the indexth player
    for (int i = 0; i < numAcc; i++)
    {
        fin.read((char*) &temp, sizeof(Player));       //storing all players' info in vector Leader
        Leader.push_back(temp);
    }

    selectionSort(Leader, numAcc);

    SET_COLOR(6);
    cout << "\t\t\t\t    __                   __             ____                       __ " << endl;
    cout << "\t\t\t\t   / /   ___  ____  ____/ /__  _____   / __ )____  ____ __________/ / " << endl;
    cout << "\t\t\t\t  / /   / _ `/ __ `/ __  / _ `/ ___/  / __  / __ `/ __ `/ ___/ __  /  " << endl;
    cout << "\t\t\t\t / /___/  __/ /_/ / /_/ /  __/ /     / /_/ / /_/ / /_/ / /  / /_/ /   " << endl;
    cout << "\t\t\t\t/_____/.___/.__,_/.__,_/.___/_/     /_____/.____/.__,_/_/   .__,_/    " << endl;

    SET_COLOR(12);
    cout << "\t\t\t\t\t" << left << setw(30) << Leader[0].username << setfill(' ')  << Leader[0].record << endl;
    SET_COLOR(9);
    cout << "\t\t\t\t\t" << left << setw(30) << Leader[1].username << setfill(' ')  << Leader[1].record << endl;
    SET_COLOR(10);
    cout << "\t\t\t\t\t" << left << setw(30) << Leader[2].username << setfill(' ')  << Leader[2].record << endl;
    SET_COLOR(15);
    cout << "\t\t\t\t\t" << left << setw(30) << Leader[3].username << setfill(' ')  << Leader[3].record << endl;
    SET_COLOR(3);
    cout << "\t\t\t\t\t" << left << setw(30) << Leader[4].username << setfill(' ')  << Leader[4].record << endl;

    SET_COLOR(7);

    fin.close();
}

void selectionSort(vector <Player> Leader, int numAcc)
{
    int max_idx;
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < 5; i++)     //find 5 highest score players
    {
        // Find the maximumelement in
        // unsorted array
        max_idx = i;
        for (int j = i+1; j < numAcc; j++)
        {
            if (Leader[j].record > Leader[max_idx].record)
                max_idx = j;
        }
        // Swap the found maximum element
        // with the first element
        if (max_idx != i)
        {
            swap (Leader[i], Leader[max_idx]);
        }
    }
}

void swap(Player *a, Player *b)
{   
    Player *temp = a;
    *a = *b;
    b = temp;
}