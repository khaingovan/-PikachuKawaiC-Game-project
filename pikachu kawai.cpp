#include "header.h"
#include "board.cpp"
#include "showing.cpp"
#include "addingArt.cpp"

//https://www.codeincodeblock.com/2011/03/move-console-windows-using-codeblock.html
HWND WINAPI GetConsoleWindowNT(void)
{
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;
    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib, TEXT("GetConsoleWindow"));
    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}

void createBoard(int **board, int &row, int &col, int characterBlock[], int &totalCharacter, int &totalDifferentCharacter){
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
	}
}

int main(){
	//resize font
	//fontsize(22, 22);
	//resize console window
    HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd, 0, 0, 1500, 800,TRUE);

	showTitleArt();

	int row, col;
	
	//15 = 0*16 + 15 white text black background
	setColor(15);
    cout << "Input number of rows (even number, 3<x<11): ";
	while(true){
		cin >> row;
		if( row > 3 && row < 11 && row%2 == 0 )
			break;
		else{
			//4 = 0*16 + 4 red text black background
			setColor(4);
    		cout << "Invalid value, please try again: ";
		}
	}
	
	//15 = 0*16 + 15 white text black background
	setColor(15);
    cout << "Input number of columns (even number, 3<x<11): ";
	while(true){
		cin >> col;
		if( col > 3 && col < 11 && col%2 == 0 )
			break;
		else{
			//4 = 0*16 + 4 red text black background
			setColor(4);
    		cout << "Invalid value, please try again: ";
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
		int *pcharacterLost, characterLost = -3;
		pcharacterLost = &characterLost;

		//
		drawingBoard(board, row, col, level, 1);
		while( !testingBoard(board, row, col, totalCharacter, pcharacterLost) ){
			shuffleBoard(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter);
			drawingBoard(board, row, col, level);
		}
		for(int i = 0; i < row + 2; i++)
			for(int j = 0; j < col + 2; j++)
				if(board[i][j] >= (int)'0' && board[i][j] <= (int)'9')
					board[i][j] = -1;
		cout << endl;
		
		matching(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter, level);

		if(totalCharacter == 0 && level == 5)
			break;
		if(totalCharacter == 0){
			drawingBoard(board, row, col, level);

			//15 = 0*16 + 15 white text black background
			setColor(15);
    		cout << "Congratulate!" << endl;

			if(level < 5){
				cout << "Play level " << level + 1 << " ? (Y/N) ";

				while(cin >> yn){
					if(yn == 'Y' || yn == 'y'){
						level++;
						createBoard(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter);
						break;
					}
					else if(yn == 'N' || yn == 'n')
						break;
					else{
						//4 = 0*16 + 4 red text black background
						setColor(4);
    					cout << "Invalid value, please try again: ";
					}
				}
			}
		}
		if(yn == 'N' || yn == 'n' || (totalCharacter == 0 && level == 5))
			break;
	}

	//15 = 0*16 + 15 white text black background
	setColor(15);
    cout << "Game ended!";
	
	deleteBoard(board, col);
	
	return 0;
}
