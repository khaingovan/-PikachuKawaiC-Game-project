#include "header.h"
#include "board.cpp"
#include "showing.cpp"

void createBoard(int **board, int row, int col, int characterBlock[],int &totalCharacter, int totalDifferentCharacter){
	//so luong ky tu con lai trong mang, sau khi noi dung 2 ky tu thi bien nay tu giam di 2
	//len 1 level, mang khoi phuc lai thi totalCharacter cung khoi phuc lai
	totalCharacter = row*col;
	for(int i = 0; i < totalDifferentCharacter; i++){
		characterBlock[i] = 0;
	}
	for(int count = 0; count < row*col;){
		//thuat toan tim ra 2 toa do bat ky, neu chung khac nhau va chua co gia tri thi se duoc them gia tri ngau nhien vao
		int y1 = rand()%row + 1;
		int x1 = rand()%col + 1;
		int y2 = rand()%row + 1;
		int x2 = rand()%col + 1;
		if( (y1 != y2 || x1 != x2) && board[y1][x1] == -1 && board[y2][x2] == -1){
			int character = rand()%totalDifferentCharacter;
			characterBlock[character]+=1;
			board[y1][x1] = character;
			board[y2][x2] = character;
			//cu them duoc gia tri vao 2 toa do thi count tu +2, neu cham nguong so luong toa do cua bang choi thi vong for tu thoat ra
			count+=2;
		}
	}}

int main(){
	//https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
	int row, col;
	
	//chu va nen mau mac dinh
    cout << "\033[0m" << "Input number of rows (even number, 3<x<11): ";
	while(true){
		cin >> row;
		if( row > 3 && row < 11 && row%2 == 0 )
			break;
		else{
			//[31m la chu do nen den
			cout << "\033[31m" << "Invalid value, please try again: ";
		}
	}
	
	//chu va nen mau mac dinh
    cout << "\033[0m" << "Input number of columns (even number, 3<x<15): ";
	while(true){
		cin >> col;
		if( col > 3 && col < 15 && col%2 == 0 )
			break;
		else{
			//[31m la chu do nen den
			cout << "\033[31m" << "Invalid value, please try again: ";
		}
	}

	//KHOI TAO MANG TOAN BO LA -1
	int **board;
	board = new int *[row + 2];
	for(int i = 0; i < row + 2; i++){
		board[i] = new int [col + 2];
	}
	for(int i = 0; i < row + 2; i++)
		for(int j = 0; j < col + 2; j++)
			board[i][j] = -1;
	
	int level = 1;
	srand(time(0));
	//mang cang nho thi cang can it ky tu, cu the mang 4x4 co toi da 6 ky tu khac nhau
	int totalDifferentCharacter = 4 + min((row*col)/2 - 6, 22);
	int characterBlock[totalDifferentCharacter];
	//so luong ky tu con lai trong mang, sau khi noi dung 2 ky tu thi bien nay tu giam di 2
	int totalCharacter;
	createBoard(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter);
	
	char yn;
	while(true){
		drawingBoard(board, row, col, level);
		/*if( !testingBoard(board, row, col, totalCharacter) ){
			/*cout << "Error." << endl;
			break;
			shuffleBoard(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter);
		}*/
		matching(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter);

		/*if(totalCharacter == 0 && level == 5)
			break;*/
		if(totalCharacter == 0){
			//chu va nen mau mac dinh
    		cout << "\033[0m" << "Congratulate!" << endl;

			if(level < 5){
				cout << "Play level " << level + 1 << " ? (Y/N) ";

				while(cin >> yn){
					if(yn == 'Y' || yn == 'y'){
						level++;
						createBoard(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter);
						break;
					}
					else if(yn == 'N' || yn == 'n'){
						break;
					}
					else{
						//[31m la chu do nen den
						cout << "\033[31m" << "Invalid value, please try again: ";
					}
				}
			}
		}
		if(yn == 'N' || yn == 'n' || (totalCharacter == 0 && level == 5))
			break;
	}

	//chu va nen mau mac dinh
    cout << "\033[0m" << "Game ended!";
	
	deleteBoard(board, col);
	
	return 0;
}

