#pragma once
#include "leaderBoard.h"

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
    int directX = 85, directY = 15;
    gotoxy(0, 10);
    setColor(6);
    cout << "\t\t\t\t\t\t        __                   __             ____                       __ " << endl;
    cout << "\t\t\t\t\t\t       / /   ___  ____  ____/ /__  _____   / __ )____  ____  _________/ / " << endl;
    cout << "\t\t\t\t\t\t      / /   / _ `/ __ `/ __  / _ `/ ___/  / __  / __ `/ __ `/ ___/ __  /  " << endl;
    cout << "\t\t\t\t\t\t     / /___/  __/ /_/ / /_/ /  __/ /     / /_/ / /_/ / /_/ / /  / /_/ /   " << endl;
    cout << "\t\t\t\t\t\t    /_____/.___/.__,_/.__,_/.___/_/     /_____/.____/.__,_/_/   .__,_/    " << endl;
    cout << endl << endl;
    gotoxy(directX - 20, directY + 3);
    cout << "NAME";
    gotoxy(directX + 10, directY + 3);
    cout << "SCORE";
    
    int numOfLeader;
    if(numAcc > 5)
        numOfLeader = 5;
    else numOfLeader = numAcc;
    int color[5] = {12, 9, 10, 15, 3};
    for(int i = 0; i < numOfLeader; i++)
    {
        gotoxy(directX - 20, directY + 5 + i*3);
        setColor(color[i]);
        cout << left << setw(30) << Leader[i].username << setfill(' ')  << Leader[i].record << endl;
    }
    
    setColor(7);

    fin.close();
}

void selectionSort(vector <Player> &Leader, int numAcc)
{
    int maxIndex;
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < 5; i++)     //find 5 highest score players
    {
        // Find the maximumelement in
        // unsorted array
        maxIndex = i;
        for (int j = i + 1; j < numAcc; j++)
        {
            if (Leader[j].record > Leader[maxIndex].record)
                maxIndex = j;
        }
        // Swap the found maximum element
        // with the first element
        Player temp;
        strcpy(temp.username, Leader[i].username);
        temp.record = Leader[i].record;

        strcpy(Leader[i].username, Leader[maxIndex].username);
        Leader[i].record = Leader[maxIndex].record;

        strcpy(Leader[maxIndex].username, temp.username);
        Leader[maxIndex].record = temp.record;
    }
}

void swap(Player &a, Player &b)
{   
    Player temp;
    strcpy(temp.username, a.username);
    temp.record = a.record;

    strcpy(a.username, b.username);
    a.record = b.record;

    strcpy(b.username, temp.username);
    b.record = temp.record;
}
