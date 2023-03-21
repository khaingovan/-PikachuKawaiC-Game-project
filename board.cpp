#include "board.h"

void drawingBoard(int **board, int row, int col){
	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= col; j++){
			if(board[i][j] == -1)
				cout << "  ";
			else
				cout << (char)(board[i][j] + (int)'A')<< " ";
		}
		cout << endl;
	}
}

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
	if(board[y1][x2] == -1){
		if(x1 < x2 && y1 < y2){
			for(int i = x1 + 1; i < x2; i++){
				if(board[y1][i] != -1)
					return false;
			}
			for(int i = y1 + 1; i < y2 - 1; i++){
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
			for(int i = y1 + 1; i < y2 - 1; i++){
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
				if(board[i][j] != -1){
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

void matching(int **board, int row, int col, int characterBlock[], int &totalCharacter){
	int y1, x1, y2, x2;
	cout << endl << "Input for matching: ";
	cin >> y1 >> x1 >> y2 >> x2;
	bool legalMatch = false;
	if( (board[y1][x1] == board[y2][x2]) && (x1 != x2 || y1 != y2) ){
		if(y1 == y2){
			legalMatch = checkLineY(board, x1, x2, y1);
		}
		else if(x1 == x2){
			legalMatch = checkLineX(board, y1, y2, x1);
		}
		else if(board[y1][x2] == -1 || board[y2][x1] == -1){
			legalMatch = checkLShape(board, y1, x1, y2, x2);
		}
		if(legalMatch == false){
			legalMatch = checkUAndZShape(board, y1, x1, y2, x2, row, col);
		}
	}
	if(legalMatch){
		characterBlock[ board[y1][x1] ]--;
		totalCharacter-=2;
		board[y1][x1] = -1;
		board[y2][x2] = -1;
	}
}

