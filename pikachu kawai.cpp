#include "header.h"
#include "board.cpp"

int main(){
	int row, col;
	
	cout << "Input number of rows (even number, 3<x<11): ";
	while(true){
		cin >> row;
		if( row > 3 && row < 11 && row%2 == 0 )
			break;
		else
			cout << "Invalid value, please try again: ";
	}
	
	cout << "Input number of columns (even number, 3<x<15): ";
	while(true){
		cin >> col;
		if( col > 3 && col < 15 && col%2 == 0 )
			break;
		else
			cout << "Invalid value, please try again: ";
	}
	//tao mang toan so -1
	//vector<vector<int>> board(row + 2 , vector<int> (col + 2, -1));
	int **board;
	board = new int *[row + 2];
	for(int i = 0; i < col + 2; i++){
		board[i] = new int [col + 2];
	}
	for(int i = 0; i < row + 2; i++)
		for(int j = 0; j < col + 2; j++)
			board[i][j] = -1;
	
	srand(time(0));
	int totalDifferentCharacter = 2 + min(row*col - 12, 24); //mang cang nho thi cang can it ky tu
	int characterBlock[totalDifferentCharacter];
	int totalCharacter = row*col; //so luong ky tu con lai trong mang
	for(int i = 0; i < totalDifferentCharacter; i++){
		characterBlock[i] = 0;
	}
	for(int count = 0; count < row*col;){
		int y1 = rand()%row + 1;
		int x1 = rand()%col + 1;
		int y2 = rand()%row + 1;
		int x2 = rand()%col + 1;
		if( (y1 != y2 || x1 != x2) && board[y1][x1] == -1 && board[y2][x2] == -1){
			int character = rand()%totalDifferentCharacter;
			characterBlock[character]+=1;
			board[y1][x1] = character;
			board[y2][x2] = character;
			count+=2;
		}
	}
	
	while(true){
		drawingBoard(board, row, col);
		matching(board, row, col, characterBlock, totalCharacter);
		if(totalCharacter == 0)
			break;
	}

	cout << "Congratulate!";
	
	delete [] board;
	for(int i = 0; i < col + 2; i++){
		delete [] board[i];
	}
	
	return 0;
}
