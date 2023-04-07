#include "header.h"
#include "board.cpp"
#include "showing.cpp"
#include "addingArt.cpp"
//#include "Menu.cpp"

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

void createBoard(int **board, int &row, int &col, characterBlockInfor &CBI){
	//mang cang nho thi cang can it ky tu, cu the mang 4x4 co toi da 6 ky tu khac nhau
	CBI.TDiffer = 4 + min((row*col)- 14, 30);
	//so luong ky tu con lai trong mang, sau khi noi dung 2 ky tu thi bien nay tu giam di 2
	CBI.TChar = row*col;
	CBI.charBlock = new int [ CBI.TDiffer ];

	/*for(int i = 0; i < CBI.TDiffer; i++){
		CBI.charBlock[i] = 0;
	}*/
	fill_n(CBI.charBlock, CBI.TDiffer, 0);
	for(int count = 0; count < row*col;){
		//thuat toan tim ra 2 toa do bat ky, neu chung khac nhau va chua co gia tri thi se duoc them gia tri ngau nhien vao
		int y1 = rand()%row + 1;
		int x1 = rand()%col + 1;
		int y2 = rand()%row + 1;
		int x2 = rand()%col + 1;
		if( (y1 != y2 || x1 != x2) && board[y1][x1] == -1 && board[y2][x2] == -1){
			int character = rand()%CBI.TDiffer;
			while(CBI.charBlock[character] > 2){
				character = rand()%CBI.TDiffer;
			}
			CBI.charBlock[character]++;
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
    MoveWindow(hWnd, 0, 0, 1500, 760,TRUE);

	showTitleArt();

	int row, col;
	characterBlockInfor CBI;
	int level = 1;
	
	//15 = 0*16 + 15 white text black background
	setColor(15);
    cout << "Input number of rows (even number, 3<x<9): ";
	while(true){
		cin >> row;
		if( row > 3 && row < 9 && row%2 == 0 )
			break;
		else{
			//4 = 0*16 + 4 red text black background
			setColor(4);
    		cout << "Invalid value, please try again: ";
		}
	}
	
	//15 = 0*16 + 15 white text black background
	setColor(15);
    cout << "Input number of columns (even number, 3<x<21): ";
	while(true){
		cin >> col;
		if( col > 3 && col < 21 && col%2 == 0 )
			break;
		else{
			//4 = 0*16 + 4 red text black background
			setColor(4);
    		cout << "Invalid value, please try again: ";
		}
	}

	//all blocks' value in board become -1
	int **board;
	board = new int *[row + 2];
	for(int i = 0; i < row + 2; i++){
		board[i] = new int [col + 2];
	}
	for(int i = 0; i < row + 2; i++)
		fill_n(board[i], col + 2, -1);
		/*for(int j = 0; j < col + 2; j++)
			board[i][j] = -1;*/
	
	srand(time(0));
	createBoard(board, row, col, CBI);

	//create background
	ifstream fi("BackgroundArt/bg4.txt");
	char bgArt[40][120];
	int countLine = 0;
	while(!fi.eof()){
		fi.getline(bgArt[countLine], 120);
		countLine++;
	}
	/*char **bgArt;
	bgArt = new char *[40];
	for(int i = 0; i < 40; i++)
		bgArt[i] = new char [120];
	bgArt = creatBackground();*/


	char yn;
	clearScreen();
	drawingBoard(board, row, col, level, bgArt);
	int xr = 1, yr = 1;
	drawKey(board, yr, xr, row + 2, col + 2);
	
	bool getButton = true;
	int move;
	int y1 = row + 2, x1 = col + 2;
	int y2 = row + 2, x2 = col + 2;
	while(getButton){
		int *pcharacterLost, characterLost = -3;
		pcharacterLost = &characterLost;
		while( !testingBoard(board, row, col, CBI, pcharacterLost) ){
			shuffleBoard(board, row, col, CBI);
			drawingBoard(board, row, col, level, bgArt);
		}
		drawKey(board, yr, xr, y1, x1);
		
		bool legalMatch = false;

		//when game end
		if(CBI.TChar == 0 && level == 5)
			break;
		if(CBI.TChar == 0){
			//15 = 0*16 + 15 white text black background
			setColor(15);
			clearScreen();
			
			//15 = 0*16 + 15 white text black background
			setColor(15);
			drawingBoard(board, row, col, level, bgArt);

			//15 = 0*16 + 15 white text black background
			setColor(15);
			gotoxy(0, 36);
    		cout << "Congratulate!" << endl;

			if(level < 5){
				cout << "Play level " << level + 1 << " ? (Y/N) ";

				while(cin >> yn){
					if(yn == 'Y' || yn == 'y'){
						level++;
						createBoard(board, row, col, CBI);
						clearScreen();
						drawingBoard(board, row, col, level, bgArt);
						drawKey(board, 1, 1, row + 2, col + 2);

						break;
					}
					else if(yn == 'N' || yn == 'n')
						break;
					else{
						//4 = 0*16 + 4 red text black background
						setColor(4);
    					cout << "Invalid character, please try again: ";
					}
				}
			}
		}
		if(yn == 'N' || yn == 'n' || (CBI.TChar == 0 && level == 5))
			break;

		char button = getch();
		switch(button){
			case KeyUp: {
				drawUnKey(board, yr, xr, bgArt, y1, x1);
				yr = max(yr - 1, 1);
				drawKey(board, yr, xr, y1, x1);
				break;
			}
			case KeyDown: {
				drawUnKey(board, yr, xr, bgArt, y1, x1);
				yr = min(yr + 1, row);
				drawKey(board, yr, xr, y1, x1);
				break;
			}
			case KeyLeft: {
				drawUnKey(board, yr, xr, bgArt, y1, x1);
				xr = max(xr - 1, 1);
				drawKey(board, yr, xr, y1, x1);
				break;
			}
			case KeyRight: {
				drawUnKey(board, yr, xr, bgArt, y1, x1);
				xr = min(xr + 1, col);
				drawKey(board, yr, xr, y1, x1);
				break;
			}
			case 's': {
				shuffleBoard(board, row, col, CBI);
				drawingBoard(board, row, col, level, bgArt);
				break;
			}
			case 'a': {
				for(int i = 1; i <= row; i++){
					for(int j = 1; j <= col; j++){
						for(int m = 1; m <= row; m++){
							for(int n = 1; n <= col; n++){
								//i, j la toa do diem thu nhat board [i][j]
								//m, n la toa do diem thu hai  board [m][n]

								isLegalMatch(board, row, col, i, j, m, n, CBI, 0, legalMatch, pcharacterLost);
								if(legalMatch){
									Sleep(300);
									levelMove(board, row, col, level);
									drawingBoard(board, row, col, level, bgArt);
									i = row + 2;
									j = col + 2;
									m = row + 2;
									n = col + 2;
								}
							}
						}
					}
				}
				drawKey(board, yr, xr, y1, x1);
				break;
			}
			case Space: {
				if(y1 == row + 2){
					y1 = yr;
					x1 = xr;
					drawKey(board, yr, xr, y1, x1);
				}
				else{
					y2 = yr;
					x2 = xr;
					isLegalMatch(board, row, col, y1, x1, y2, x2, CBI, 0, legalMatch, pcharacterLost);
					if(*pcharacterLost != -3){
						Sleep(300);
						levelMove(board, row, col, level);
					}
					drawingBoard(board, row, col, level, bgArt);
					y1 = row + 2, x1 = col + 2;
					y2 = row + 2, x2 = col + 2;
					drawKey(board, yr, xr, y1, x1);
				}

				break;
			}
			case Esc:
				getButton = false;
		}
	}
	
	/*while(true){
		int *pcharacterLost, characterLost = -3;
		pcharacterLost = &characterLost;

		levelMove(board, row, col, level);
		//15 = 0*16 + 15 white text black background
		setColor(15);
		drawingBoard(board, row, col, level, bgArt);//, 1);
		while( !testingBoard(board, row, col, CBI, pcharacterLost) ){
			shuffleBoard(board, row, col, CBI);
			drawingBoard(board, row, col, level, bgArt);
		}
		
		cout << endl << CBI.TChar << endl;
		for(int i = 0; i < CBI.TDiffer; i++)
			cout << CBI.charBlock[i] << " ";
		cout << endl;
		
		matching(board, row, col, CBI, level);

		if(CBI.TChar == 0 && level == 5)
			break;
		if(CBI.TChar == 0){
			clearScreen();
			drawingBoard(board, row, col, level, bgArt);

			//15 = 0*16 + 15 white text black background
			setColor(15);
    		cout << "Congratulate!" << endl;

			if(level < 5){
				cout << "Play level " << level + 1 << " ? (Y/N) ";

				while(cin >> yn){
					if(yn == 'Y' || yn == 'y'){
						level++;
						createBoard(board, row, col, CBI);
						break;
					}
					else if(yn == 'N' || yn == 'n')
						break;
					else{
						//4 = 0*16 + 4 red text black background
						setColor(4);
    					cout << "Invalid character, please try again: ";
					}
				}
			}
		}
		if(yn == 'N' || yn == 'n' || (CBI.TChar == 0 && level == 5))
			break;
	}*/

	//15 = 0*16 + 15 white text black background
	setColor(15);
	gotoxy(0, 36);
	cout << "\t\t\t\t \n \t\t\t\t \n \t\t\t\t \n \t\t\t\t \n \t\t\t\t \n \t\t\t\t";
	setColor(15);
	gotoxy(0, 36);
    cout << "Game ended!";
	
	deleteBoard(board, col, CBI);

	/*int a=1,b=1,c=1,d=1;
	generateMenu (a,b,c,d);*/
	
	return 0;

}
