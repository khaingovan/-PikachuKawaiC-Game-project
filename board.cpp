#include "board.h"

/*void drawingBoard(int **board, int row, int col){
	for(int i = 0; i <= row + 1; i++){
		for(int j = 0; j <= col + 1; j++){
			if(board[i][j] == -1)
				cout << "  ";
			else
				cout << (char)(board[i][j] + (int)'A')<< " ";
		}
		cout << endl;
	}
}*/

bool checkLineY(int **board, int x1, int x2, int y){ //check theo hang ngang
	if(x1 > x2){
		int key = x1;
		x1 = x2;
		x2 = key;
	}
	if(x2 - x1 == 1) return true;
	for(int i = x1 + 1; i <= x2 - 1; i++){
		if(board[y][i] != -1)
			return false;
	}
	return true;
}

bool checkLineX(int **board, int y1, int y2, int x){ //check theo hang doc
	if(y1 > y2){
		int key = y1;
		y1 = y2;
		y2 = key;
	}
	if(y2 - y1 == 1) return true;
	for(int i = y1 + 1; i <= y2 - 1; i++){
		if(board[i][x] != -1)
			return false;
	}
	return true;
}

bool checkLShape(int **board, int y1, int x1, int y2, int x2){
	/*if(board[y1][x2] == -1){
		if(x1 < x2 && y1 < y2){
			for(int i = x1 + 1; i < x2; i++){
				if(board[y1][i] != -1)
					return false;
			}
			for(int i = y1 + 1; i < y2; i++){
				if(board[i][y2] != -1)
					return false;
			}
		}
		else if(x1 > x2 && y1 < y2){
			for(int i = x1 - 1; i > x2; i--){
				if(board[y1][i] != -1)
					return false;
			}
			for(int i = y1 + 1; i < y2; i++){
				if(board[i][y2] != -1)
					return false;
			}
		}
		else if(x1 < x2 && y1 > y2){
			for(int i = x1 + 1; i < x2; i++){
				if(board[y1][i] != -1)
					return false;
			}
			for(int i = y1 - 1; i < y2; i--){
				if(board[i][y2] != -1)
					return false;
			}
		}
		else if(x1 > x2 && y1 > y2){
			for(int i = x1 - 1; i > x2; i--){
				if(board[y1][i] != -1)
					return false;
			}
			for(int i = y1 - 1; i < y2; i--){
				if(board[i][y2] != -1)
					return false;
			}
		}
	}
	else{
		if(x1 < x2 && y1 < y2){
			for(int i = y1 + 1; i < y2; i++){
				if(board[i][y2] != -1)
					return false;
			}
			for(int i = x1 + 1; i < x2; i++){
				if(board[y1][i] != -1)
					return false;
			}
		}
		else if(x1 > x2 && y1 < y2){
			for(int i = y1 + 1; i < y2; i++){
				if(board[i][y2] != -1)
					return false;
			}
			for(int i = x1 - 1; i > x2; i--){
				if(board[y1][i] != -1)
					return false;
			}
		}
		else if(x1 < x2 && y1 > y2){
			for(int i = y1 - 1; i < y2; i--){
				if(board[i][y2] != -1)
					return false;
			}
			for(int i = x1 + 1; i < x2; i++){
				if(board[y1][i] != -1)
					return false;
			}
		}
		else if(x1 > x2 && y1 > y2){
			for(int i = y1 - 1; i < y2; i--){
				if(board[i][y2] != -1)
					return false;
			}
			for(int i = x1 - 1; i > x2; i--){
				if(board[y1][i] != -1)
					return false;
			}
		}
	}*/

	//	A	 ___________________	B
	//		|					|
	//		|					|
	//		|					|
	//		|					|
	//		|					|
	//	D	|___________________|	C

	if( (y1 < y2 && x1 < x2) || (y1 > y2 && x1 > x2) ){
		int Ay, Ax , Cy, Cx;
		if(y1 < y2){
			Ay = y1; Ax = x1; Cy = y2; Cx = x2;
		}
		else{
			Ay = y2; Ax = x2; Cy = y1; Cx = x1;
		}
		
		if(board[Ay][Cx] == -1){
			for(int i = Ax + 1; i < Cx; i++)
				if(board[Ay][i] != -1)
					return false;
			for(int i = Cy - 1; i > Ay; i--)
				if(board[i][Cx] != -1)
					return false;
		}
		else if(board[Cy][Ax] == -1){
			for(int i = Cx - 1; i > Ax; i--)
				if(board[Cy][i] != -1)
					return false;
			for(int i = Ay + 1; i < Cy; i++)
				if(board[i][Ax] != -1)
					return false;
		}
	}
	else if( (y1 < y2 && x1 > x2) || (y1 > y2 && x1 < x2) ){
		int By, Bx, Dy, Dx;
		if(y1 < y2){
			By = y1; Bx = x1; Dy = y2; Dx = x2;
		}
		else{
			By = y2; Bx = x2; Dy = y1; Dx = x1;
		}

		if(board[By][Dx] == -1){
			for(int i = Bx - 1; i > Dx; i--)
				if(board[By][i] != -1)
					return false;
			for(int i = Dy - 1; i > Dx; i--)
				if(board[i][Dx] != -1)
					return false;
		}
		else if(board[Dy][Bx] == -1){
			for(int i = Dx + 1; i < Bx; i++)
				if(board[Dy][i] != -1)
					return false;
			for(int i = By + 1; i < Dy; i++)
				if(board[i][Bx] != -1)
					return false;
		}
	}
	return true;
}

bool checkUAndZShape(int **board, int y1, int x1, int y2, int x2, int row, int col){
	int colL, colR, rowT, rowB;
	if(x1 < x2){
		colL = x1;
		colR = x2;
	}
	else{
		colL = x2;
		colR = x1;
	}
	if(y1 < y2){
		rowT = y1;
		rowB = y2;
	}
	else{
		rowT = y2;
		rowB = y1;
	}
	
	for(int i = 0; i < row + 2; i++){ // check dang U, ^, N
		bool key = false;
		
		if(board[i][colL] == -1 && board[i][colR] == -1){
			key = true;
			
			//check canh day chu U 
			for(int j = colL + 1; j <= colR - 1; j++){
				if(board[i][j] != -1){
					key = false;
					j = colR;
				}
			}
			
			//check 2 canh ben chu U
			
			if(y1 > i && key == true){
				for(int j = y1 - 1; j >= i; j--){
					if(board[j][x1] != -1){
						key = false;
						j = -1;
					}
				}
			}
			
			if(y1 < i && key == true){
				for(int j = y1 + 1; j <= i; j++){
					if(board[j][x1] != -1){
						key = false;
						j = 100;
					}
				}
			}
			
			if(y2 > i && key == true){
				for(int j = y2 - 1; j >= i; j--){
					if(board[j][x2] != -1){
						key = false;
						j = -1;
					}
				}
			}
			
			if(y2 < i && key == true){
				for(int j = y2 + 1; j <= i; j++){
					if(board[j][x2] != -1){
						key = false;
						j = 100;
					}
				}
			}
		}
		
		if(key) return true;
	}
	
	for(int i = 0; i < col + 2; i++){ //check dang [, ], Z
		bool key = false;
		
		if(board[rowT][i] == -1 && board[rowB][i] == -1){
			key = true;
			
			//check canh ben cua [ 
			for(int j = rowT + 1; j <= rowB - 1; j++){
				if(board[j][i] != -1){
					key = false;
					j = rowB;
				}
			}
			
			//check 2 canh tren duoi cua [
			
			if(x1 > i && key == true){
				for(int j = x1 - 1; j >= i; j--){
					if(board[y1][j] != -1){
						key = false;
						j = -1;
					}
				}
			}
			
			if(x1 < i && key == true){
				for(int j = x1 + 1; j <= i; j++){
					if(board[y1][j] != -1){
						key = false;
						j = 100;
					}
				}
			}
			
			if(x2 > i && key == true){
				for(int j = x2 - 1; j >= i; j--){
					if(board[y2][j] != -1){
						key = false;
						j = -1;
					}
				}
			}
			
			if(x2 < i && key == true){
				for(int j = x2 + 1; j <= i; j++){
					if(board[y2][j] != -1){
						key = false;
						j = 100;
					}
				}
			}
		}
		
		if(key) return true;
	}
	return false;
}

bool isLegalMatch(int **board, int row, int col, int y1, int x1, int y2, int x2){
	bool legalMatch = false;
	if(y1 == y2 && x1 == x2)
		return false;
	if(board[y1][x1] == -1 || board[y2][x2] == -1) 
		return false;
	if(board[y1][x1] != board[y2][x2])
		return false;

	if(y1 == y2){
		legalMatch = checkLineY(board, x1, x2, y1);
	}
	else if(x1 == x2){
		legalMatch = checkLineX(board, y1, y2, x1);
	}
	else if(board[y1][x2] == -1 || board[y2][x1] == -1){
		legalMatch = checkLShape(board, y1, x1, y2, x2);
	}
	
	// Xet U Shape va Z Shape sau khi nhung dang kia khong di dung
	if(legalMatch == false)
		legalMatch = checkUAndZShape(board, y1, x1, y2, x2, row, col);
	return legalMatch;
}

bool testingBoard(int **board, int row, int col, int totalCharacter){
	bool legalMatch = false;

	if(totalCharacter == 0)
		return true;

	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= col; j++){
			for(int m = 1; m <= row; m++){
				for(int n = 1; n <= col; n++){
					//i, j la toa do diem thu nhat board [i][j]
					//m, n la toa do diem thu hai  board [m][n]

					if( isLegalMatch(board, row, col, i, j, m, n) )
						return true;

					/*if((i != m || j != n) && board[i][j] == board[m][n]){
						// Neu thay diem dang xet la -1 thi bo qua
						if(board[i][j] == -1 || board[m][n] == -1){
							m = row + 5;
							n = col + 5;
						}

						if(i == m)
							legalMatch = checkLineY(board, j, n, m);
						else if(j == n)
							legalMatch = checkLineX(board, i, m, j);
						else if(board[i][n] == -1 || board[m][j] == -1)
							legalMatch = checkLShape(board, i, j, m, n);
						
						// Xet U Shape va Z Shape sau khi nhung dang kia khong di dung
						if(legalMatch == false)
							legalMatch = checkUAndZShape(board, i, j, m, n, row, col);

						//
						if(legalMatch)
							return true;
					}*/
				}
			}
		}
	}

	return false;
}

void matching(int **board, int row, int col, int characterBlock[], int &totalCharacter, int totalDifferentCharacter){
	int y1, x1, y2, x2;

	//https://www.codespeedy.com/color-text-output-in-console-in-cpp
	HANDLE coloring;
    coloring = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//15 la chu trang nen den
    SetConsoleTextAttribute(coloring, 15);
	cout << endl << "Input for matching: ";
	cin >> y1 >> x1 >> y2 >> x2;

	//cai nay chi de kiem tra chuc nang shuffle
	if(y1 == 1 && x1 == 1 && y2 == 1 && x2 == 1)
		shuffleBoard(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter);
	
	//bool legalMatch = isLegalMatch(board, row, col, y1, x1, y2, x2);
	/*if( (board[y1][x1] == board[y2][x2]) && (x1 != x2 || y1 != y2) ){
		if(y1 == y2)
			legalMatch = checkLineY(board, x1, x2, y1);
		else if(x1 == x2)
			legalMatch = checkLineX(board, y1, y2, x1);
		
		else if(board[y1][x2] == -1 || board[y2][x1] == -1)
			legalMatch = checkLShape(board, y1, x1, y2, x2);
		
		// Xet U Shape va Z Shape sau khi nhung dang kia khong di dung
		if(legalMatch == false)
			legalMatch = checkUAndZShape(board, y1, x1, y2, x2, row, col);
	}*/
	if( isLegalMatch(board, row, col, y1, x1, y2, x2) ){
		characterBlock[ board[y1][x1] ]--;
		totalCharacter-=2;
		board[y1][x1] = -1;
		board[y2][x2] = -1;
	}
}

//neu khong con nuoc di kha thi, bang se tu trao cac toa do
void shuffleBoard(int **board, int row, int col, int characterBlock[], int totalCharacter, int totalDifferentCharacter){
	srand(time(0));

	int *a;
	a = new int [totalDifferentCharacter];
	for(int i = 0; i < totalDifferentCharacter; i++){
		a[i] = characterBlock[i];
	}
	for(int i = 0; i < totalDifferentCharacter; i++)
		cout << a[i] << endl;

	for(int i = 1; i <= row; i++)
		for(int j = 1; j <= col; j++)
			if(board[i][j] != -1)
				board[i][j] = -2;

	for(int count = 0; count < totalCharacter;){
		//thuat toan tim ra 2 toa do bat ky, neu chung khac nhau va chua co gia tri thi se duoc them gia tri ngau nhien vao
		int y1 = rand()%row + 1;
		int x1 = rand()%col + 1;
		int y2 = rand()%row + 1;
		int x2 = rand()%col + 1;
		if( (y1 != y2 || x1 != x2) && board[y1][x1] == -2 && board[y2][x2] == -2){
			int character = rand()%totalDifferentCharacter;
			//thuat toan xao tron hoat dong dua tren cac ky tu con lai cua bang choi
			if(a[character] > 0){
				board[y1][x1] = character;
				board[y2][x2] = character;
				a[character]--;
				//cu them duoc gia tri vao 2 toa do thi count tu +2, neu cham nguong so luong toa do cua bang choi thi vong for tu thoat ra
				count+=2;
			}
		}
	}

	delete [] a;
}

void deleteBoard(int **board, int col){
	delete [] board;
	for(int i = 0; i < col + 2; i++){
		delete [] board[i];
	}
}

