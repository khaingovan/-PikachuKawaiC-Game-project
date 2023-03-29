#include "board.h"
#include "showing.h"

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

void checkLineX(int **board, int x1, int x2, int y, bool testing, int &matchShape, int *pcharacterLost){ //check theo hang ngang
	matchShape = 1;

	if(x1 > x2){
		int key = x1;
		x1 = x2;
		x2 = key;
	}
	for(int i = x1 + 1; i <= x2 - 1; i++)
		if(board[y][i] != -1){
			matchShape = 0;
			i = 100;
		}

	//drawing line
	if(matchShape != 0 && !testing){
		*pcharacterLost = board[y][x2];
		board[y][x1] = (int)'2';
		for(int i = x1 + 1; i <= x2 - 1; i++)
			board[y][i] = (int)'5';
		board[y][x2] = (int)'3';
	}
}

void checkLineY(int **board, int y1, int y2, int x, bool testing, int &matchShape, int *pcharacterLost){ //check theo hang doc
	matchShape = 2;

	if(y1 > y2){
		int key = y1;
		y1 = y2;
		y2 = key;
	}
	for(int i = y1 + 1; i <= y2 - 1; i++)
		if(board[i][x] != -1){
			matchShape = 0;
			i = 100;
		}

	//drawing line
	if(matchShape != 0 && !testing){
		*pcharacterLost = board[y2][x];
		board[y1][x] = (int)'0';
		for(int i = y1 + 1; i <= y2 - 1; i++)
			board[i][x] = (int)'4';
		board[y2][x] = (int)'1';
	}
}

void checkLShape(int **board, int y1, int x1, int y2, int x2, bool testing, int &matchShape, int *pcharacterLost){
	//	A	 ___________________	B
	//		|					|
	//		|					|
	//		|					|
	//		|					|
	//		|					|
	//	D	|___________________|	C

	matchShape = 0;

	if( (y1 < y2 && x1 < x2) || (y1 > y2 && x1 > x2) ){
		int Ay, Ax , Cy, Cx;
		if(y1 < y2){
			Ay = y1; Ax = x1; Cy = y2; Cx = x2;
		}
		else{
			Ay = y2; Ax = x2; Cy = y1; Cx = x1;
		}
		
		if(board[Ay][Cx] == -1){
			matchShape = 3;
			for(int i = Ax + 1; i < Cx; i++)
				if(board[Ay][i] != -1){
					matchShape = 0;
					i = 100;
				}
			for(int i = Cy - 1; i > Ay; i--)
				if(board[i][Cx] != -1){
					matchShape = 0;
					i = -5;
				}
			
			//drawing line
			if(matchShape != 0 && !testing){
				*pcharacterLost = board[y2][x2];
				board[Ay][Ax] = (int)'2';
				board[Cy][Cx] = (int)'1';
				board[Ay][Cx] = (int)'7';
				for(int i = Cy - 1; i > Ay; i--)
					board[i][Cx] = (int)'4';
				for(int i = Ax + 1; i < Cx; i++)
					board[Ay][i] = (int)'5';
			}
		}
		else if(board[Cy][Ax] == -1){
			matchShape = 3;
			for(int i = Cx - 1; i > Ax; i--)
				if(board[Cy][i] != -1){
					matchShape = 0;
					i = -5;
				}
			for(int i = Ay + 1; i < Cy; i++)
				if(board[i][Ax] != -1){
					matchShape = 0;
					i = 100;
				}
			
			//drawing line
			if(matchShape != 0 && !testing){
				*pcharacterLost = board[y2][x2];
				board[Ay][Ax] = (int)'0';
				board[Cy][Cx] = (int)'3';
				board[Cy][Ax] = (int)'8';
				for(int i = Cx - 1; i > Ax; i--)
					board[Cy][i] = (int)'5';
				for(int i = Ay + 1; i < Cy; i++)
					board[i][Ax] = (int)'4';
			}
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
			matchShape = 3;
			for(int i = Bx - 1; i > Dx; i--)
				if(board[By][i] != -1){
					matchShape = 0;
					i = -5;
				}
			for(int i = Dy - 1; i > By; i--)
				if(board[i][Dx] != -1){
					matchShape = 0;
					i = -5;
				}
			
			//drawing line
			if(matchShape != 0 && !testing){
				*pcharacterLost = board[y2][x2];
				board[By][Bx] = (int)'3';
				board[Dy][Dx] = (int)'1';
				board[By][Dx] = (int)'6';
				for(int i = Dy - 1; i > By; i--)
					board[i][Dx] = (int)'4';
				for(int i = Bx - 1; i > Dx; i--)
					board[By][i] = (int)'5';
			}
		}
		else if(board[Dy][Bx] == -1){
			matchShape = 3;
			for(int i = Dx + 1; i < Bx; i++)
				if(board[Dy][i] != -1){
					matchShape = 0;
					i = 100;
				}
			for(int i = By + 1; i < Dy; i++)
				if(board[i][Bx] != -1){
					matchShape = 0;
					i = 100;
				}
			
			//drawing line
			if(matchShape != 0 && !testing){
				*pcharacterLost = board[y2][x2];
				board[By][Bx] = (int)'0';
				board[Dy][Dx] = (int)'2';
				board[Dy][Bx] = (int)'9';
				for(int i = Dx + 1; i < Bx; i++)
					board[Dy][i] = (int)'5';
				for(int i = By + 1; i < Dy; i++)
					board[i][Bx] = (int)'4';
			}
		}
	}
}

void checkUAndZShape(int **board, int row, int col, int y1, int x1, int y2, int x2, bool testing, int &matchShape, int *pcharacterLost){
	matchShape = 0;
	
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
	
	int iU = 0, iZ = 0;
	while(iU < row + 2){ // check dang U, ^, N
		if(board[iU][colL] == -1 && board[iU][colR] == -1){
			matchShape = 4;
			
			//check canh day chu U 
			for(int j = colL + 1; j <= colR - 1; j++)
				if(board[iU][j] != -1){
					matchShape = 0;
					j = colR;
				}
			
			//check 2 canh ben chu U
			
			if(y1 - 1 > iU && matchShape != 0)
				for(int j = y1 - 1; j > iU; j--)
					if(board[j][x1] != -1){
						matchShape = 0;
						j = -1;
					}
			
			if(y1 + 1 < iU && matchShape != 0)
				for(int j = y1 + 1; j < iU; j++)
					if(board[j][x1] != -1){
						matchShape = 0;
						j = 100;
					}
			
			if(y2 - 1 > iU && matchShape != 0)
				for(int j = y2 - 1; j > iU; j--)
					if(board[j][x2] != -1){
						matchShape = 0;
						j = -1;
					}
			
			if(y2 + 1 < iU && matchShape != 0)
				for(int j = y2 + 1; j < iU; j++)
					if(board[j][x2] != -1){
						matchShape = 0;
						j = 100;
					}
		}

		if(matchShape != 0)
			break;
		else
			iU++;
	}
	
	if(matchShape == 0){
		while(iZ < col + 2){ //check dang [, ], Z
			if(board[rowT][iZ] == -1 && board[rowB][iZ] == -1){
				matchShape = 5;
				
				//check canh ben cua [ 
				for(int j = rowT + 1; j <= rowB - 1; j++)
					if(board[j][iZ] != -1){
						matchShape = 0;
						j = rowB;
					}
				
				//check 2 canh tren duoi cua [
				
				if(x1 - 1 > iZ && matchShape != 0)
					for(int j = x1 - 1; j >= iZ; j--)
						if(board[y1][j] != -1){
							matchShape = 0;
							j = -1;
						}
				
				if(x1 + 1 < iZ && matchShape != 0)
					for(int j = x1 + 1; j <= iZ; j++)
						if(board[y1][j] != -1){
							matchShape = 0;
							j = 100;
						}
				
				if(x2 - 1 > iZ && matchShape != 0)
					for(int j = x2 - 1; j >= iZ; j--)
						if(board[y2][j] != -1){
							matchShape = 0;
							j = -1;
						}
				
				if(x2 + 1 < iZ && matchShape != 0)
					for(int j = x2 + 1; j <= iZ; j++)
						if(board[y2][j] != -1){
							matchShape = 0;
							j = 100;
						}
			}

			if(matchShape != 0)
				break;
			else
				iZ++;
		}
	}

	//drawing line
	if(matchShape == 4 && !testing){
		*pcharacterLost = board[y2][x2];

		for(int j = colL + 1; j <= colR - 1; j++)
			board[iU][j] = (int)'5';
		
		if(y1 > iU){
			board[y1][x1] = (int)'1';
			for(int j = y1 - 1; j > iU; j--)
				board[j][x1] = (int)'4';
			board[iU][x1] = (int)'6';
		}
		
		if(y1 < iU){
			board[y1][x1] = (int)'0';
			for(int j = y1 + 1; j < iU; j++)
				board[j][x1] = (int)'4';
			board[iU][x1] = (int)'8';
		}
		
		if(y2 > iU){
			board[y2][x2] = (int)'1';
			for(int j = y2 - 1; j > iU; j--)
				board[j][x2] = (int)'4';
			board[iU][x2] = (int)'7';
		}
		
		if(y2 < iU){
			board[y2][x2] = (int)'0';
			for(int j = y2 + 1; j < iU; j++)
				board[j][x2] = (int)'4';
			board[iU][x2] = (int)'9';
		}
		
		if(x1 > x2 && (iU < min(y1, y2) || iU > max(y1, y2)) ){
			int swap;
			swap = board[iU][x1];
			board[iU][x1] = board[iU][x2];
			board[iU][x2] = swap;
		}
		else if(x1 > x2){
			if(board[iU][x1] == (int)'7'){
				board[iU][x1] = (int)'6';
				board[iU][x2] = (int)'9';
			}
			else{
				board[iU][x1] = (int)'7';
				board[iU][x2] = (int)'8';
			}
		}
	}
	else if(matchShape == 5 && !testing){
		*pcharacterLost = board[y2][x2];

		for(int j = rowT + 1; j <= rowB - 1; j++)
			board[j][iZ] = (int)'4';
		
		if(x1 > iZ){
			board[y1][x1] = (int)'3';
			for(int j = x1 - 1; j >= iZ; j--)
				board[y1][j] = (int)'5';
			board[y1][iZ] = (int)'6';
		}
		
		if(x1 < iZ){
			board[y1][x1] = (int)'2';
			for(int j = x1 + 1; j <= iZ; j++)
				board[y1][j] = (int)'5';
			board[y1][iZ] = (int)'7';
		}
		
		if(x2 > iZ){
			board[y2][x2] = (int)'3';
			for(int j = x2 - 1; j >= iZ; j--)
				board[y2][j] = (int)'5';
			board[y2][iZ] = (int)'8';
		}
		
		if(x2 < iZ){
			board[y2][x2] = (int)'2';
			for(int j = x2 + 1; j <= iZ; j++)
				board[y2][j] = (int)'5';
			board[y2][iZ] = (int)'9';
		}
		
		if(y1 > y2 && (iZ < min(y1, y2) || iZ > max(y1, y2)) ){
			int swap;
			swap = board[y1][iZ];
			board[y1][iZ] = board[y2][iZ];
			board[y2][iZ] = swap;
		}
		else if(y1 > y2){
			if(board[y1][iZ] == (int)'7'){
				board[y1][iZ] = (int)'6';
				board[y2][iZ] = (int)'9';
			}
			else{
				board[y1][iZ] = (int)'7';
				board[y2][iZ] = (int)'8';
			}
		}
	}
	else
		*pcharacterLost = -3;
}

void isLegalMatch(int **board, int row, int col, int y1, int x1, int y2, int x2, bool testing, bool &legalMatch, int *pcharacterLost){
	legalMatch = true;
	int matchShape = 0;
	if(y1 == y2 && x1 == x2)
		legalMatch = false;
	if(board[y1][x1] == -1 || board[y2][x2] == -1) 
		legalMatch = false;
	if(board[y1][x1] != board[y2][x2])
		legalMatch = false;
	
	if(legalMatch != false){
		legalMatch = false;

		if(y1 == y2){
			checkLineX(board, x1, x2, y1, testing, matchShape, pcharacterLost);
			legalMatch = matchShape;
		}
		else if(x1 == x2){
			checkLineY(board, y1, y2, x1, testing, matchShape, pcharacterLost);
			legalMatch = matchShape;
		}
		else if(board[y1][x2] == -1 || board[y2][x1] == -1){
			checkLShape(board, y1, x1, y2, x2, testing, matchShape, pcharacterLost);
			legalMatch = matchShape;
		}
		
		// Xet U Shape va Z Shape sau khi nhung dang kia khong di dung
		if(legalMatch == false){
			checkUAndZShape(board, row, col, y1, x1, y2, x2, testing, matchShape, pcharacterLost);
			legalMatch = matchShape;
		}
	}
}

bool testingBoard(int **board, int row, int col, int totalCharacter, int *pcharacterLost){
	bool legalMatch;
	if(totalCharacter == 0)
		return true;

	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= col; j++){
			for(int m = 1; m <= row; m++){
				for(int n = 1; n <= col; n++){
					//i, j la toa do diem thu nhat board [i][j]
					//m, n la toa do diem thu hai  board [m][n]

					isLegalMatch(board, row, col, i, j, m, n, 1, legalMatch, pcharacterLost);
					if(legalMatch)
						return true;
				}
			}
		}
	}

	return false;
}

void drawingLine(int **board, int row, int col, int level){
	drawingBoard(board, row, col, level);
}

void matching(int **board, int row, int col, int characterBlock[], int &totalCharacter, int totalDifferentCharacter, int &level){
	int y1, x1, y2, x2;
	bool legalMatch = false;
	int characterLost = -3;
	int *pcharacterLost;
	pcharacterLost = &characterLost;

	//chu va nen mau mac dinh
    cout << "\033[0m";
	cout << endl << "Input for matching: ";
	cin >> y1 >> x1 >> y2 >> x2;

	//cai nay chi de kiem tra chuc nang shuffle
	if(y1 == 1 && x1 == 1 && y2 == 1 && x2 == 1)
		shuffleBoard(board, row, col, characterBlock, totalCharacter, totalDifferentCharacter);
	else if(board[y1][x1] == board[y2][x2]){
		isLegalMatch(board, row, col, y1, x1, y2, x2, 0, legalMatch, pcharacterLost);
		
		if( legalMatch ){
			drawingBoard(board, row, col, level);
			cout << endl << *pcharacterLost << endl;
			board[y1][x1] = -1;
			board[y2][x2] = -1;
			characterBlock[ characterLost ]--;
			totalCharacter-=2;
			for(int i = 0; i < row + 2; i++)
				for(int j = 0; j < col + 2; j++)
					if(board[i][j] >= (int)'0' && board[i][j] <= (int)'9')// && !(board[i][j] >= 0 && board[i][j] <= totalDifferentCharacter))
						board[i][j] = -1;
		}
	}
	cout << endl << *pcharacterLost << endl;
	Sleep(500);
}

//neu khong con nuoc di kha thi, bang se tu trao cac toa do
void shuffleBoard(int **board, int row, int col, int characterBlock[], int totalCharacter, int totalDifferentCharacter){
	srand(time(0));

	//replace la mang phu cua characterBlock, thon bao so luong ky tu khac nhau theo tung loai
	int *replace;
	replace = new int [totalDifferentCharacter];
	for(int i = 0; i < totalDifferentCharacter; i++){
		replace[i] = characterBlock[i];
	}

	//nhung toa do truoc day co gia tri se bi thay the thanh -2
	for(int i = 1; i <= row; i++)
		for(int j = 1; j <= col; j++)
			if( (board[i][j] >= 0 && board[i][j] <= totalDifferentCharacter) )
				board[i][j] = -2;

	int value = 0;
	for(int count = 0; count < totalCharacter/2;){
		int y1 = rand()%row + 1;
		int x1 = rand()%col + 1;
		int y2 = rand()%row + 1;
		int x2 = rand()%col + 1;

		//thuat toan tim ra 2 toa do bat ky, neu chung khac nhau va co gia tri la -2 thi se duoc them gia tri tu replace[]
		if( (y1 != y2 || x1 != x2) && board[y1][x1] == -2 && board[y2][x2] == -2 && replace[value] != 0){
			board[y1][x1] = value;
			board[y2][x2] = value;
			replace[value]--;
			count++;
		}
		if(replace[value] == 0){
			value++;
		}
	}

	delete [] replace;
}

void deleteBoard(int **board, int col){
	delete [] board;
	for(int i = 0; i < col + 2; i++){
		delete [] board[i];
	}
}
