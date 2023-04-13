#include "board.h"
#include "showing.h"

void checkLineX(mainScreen &game, int x1, int x2, int y, bool testing, int &matchShape, int *pcharacterLost){//check horizontal I Shape
	matchShape = 1;

	if(x1 > x2){
		int key = x1;
		x1 = x2;
		x2 = key;
	}
	for(int i = x1 + 1; i <= x2 - 1; i++)
		if(game.board[y][i] != -1){
			matchShape = 0;
			i = 100;
		}

	//drawing line
	if(matchShape != 0 && !testing){
		*pcharacterLost = game.board[y][x2];
		game.board[y][x1] = (int)'2';
		for(int i = x1 + 1; i <= x2 - 1; i++)
			game.board[y][i] = (int)'5';
		game.board[y][x2] = (int)'3';
	}
}

void checkLineY(mainScreen &game, int y1, int y2, int x, bool testing, int &matchShape, int *pcharacterLost){//check vertical I Shape
	matchShape = 2;

	if(y1 > y2){
		int key = y1;
		y1 = y2;
		y2 = key;
	}
	for(int i = y1 + 1; i <= y2 - 1; i++)
		if(game.board[i][x] != -1){
			matchShape = 0;
			i = 100;
		}

	//drawing line
	if(matchShape != 0 && !testing){
		*pcharacterLost = game.board[y2][x];
		game.board[y1][x] = (int)'0';
		for(int i = y1 + 1; i <= y2 - 1; i++)
			game.board[i][x] = (int)'4';
		game.board[y2][x] = (int)'1';
	}
}

void checkLShape(mainScreen &game, int y1, int x1, int y2, int x2, bool testing, int &matchShape, int *pcharacterLost){
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
		
		if(game.board[Ay][Cx] == -1){
			matchShape = 3;
			for(int i = Ax + 1; i < Cx; i++)
				if(game.board[Ay][i] != -1){
					matchShape = 0;
					i = 100;
				}
			for(int i = Cy - 1; i > Ay; i--)
				if(game.board[i][Cx] != -1){
					matchShape = 0;
					i = -5;
				}
			
			//drawing line
			if(matchShape != 0 && !testing){
				*pcharacterLost = game.board[y2][x2];
				game.board[Ay][Ax] = (int)'2';
				game.board[Cy][Cx] = (int)'1';
				game.board[Ay][Cx] = (int)'7';
				for(int i = Cy - 1; i > Ay; i--)
					game.board[i][Cx] = (int)'4';
				for(int i = Ax + 1; i < Cx; i++)
					game.board[Ay][i] = (int)'5';
			}
		}
		else if(game.board[Cy][Ax] == -1){
			matchShape = 3;
			for(int i = Cx - 1; i > Ax; i--)
				if(game.board[Cy][i] != -1){
					matchShape = 0;
					i = -5;
				}
			for(int i = Ay + 1; i < Cy; i++)
				if(game.board[i][Ax] != -1){
					matchShape = 0;
					i = 100;
				}
			
			//drawing line
			if(matchShape != 0 && !testing){
				*pcharacterLost = game.board[y2][x2];
				game.board[Ay][Ax] = (int)'0';
				game.board[Cy][Cx] = (int)'3';
				game.board[Cy][Ax] = (int)'8';
				for(int i = Cx - 1; i > Ax; i--)
					game.board[Cy][i] = (int)'5';
				for(int i = Ay + 1; i < Cy; i++)
					game.board[i][Ax] = (int)'4';
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

		if(game.board[By][Dx] == -1){
			matchShape = 3;
			for(int i = Bx - 1; i > Dx; i--)
				if(game.board[By][i] != -1){
					matchShape = 0;
					i = -5;
				}
			for(int i = Dy - 1; i > By; i--)
				if(game.board[i][Dx] != -1){
					matchShape = 0;
					i = -5;
				}
			
			//drawing line
			if(matchShape != 0 && !testing){
				*pcharacterLost = game.board[y2][x2];
				game.board[By][Bx] = (int)'3';
				game.board[Dy][Dx] = (int)'1';
				game.board[By][Dx] = (int)'6';
				for(int i = Dy - 1; i > By; i--)
					game.board[i][Dx] = (int)'4';
				for(int i = Bx - 1; i > Dx; i--)
					game.board[By][i] = (int)'5';
			}
		}
		else if(game.board[Dy][Bx] == -1){
			matchShape = 3;
			for(int i = Dx + 1; i < Bx; i++)
				if(game.board[Dy][i] != -1){
					matchShape = 0;
					i = 100;
				}
			for(int i = By + 1; i < Dy; i++)
				if(game.board[i][Bx] != -1){
					matchShape = 0;
					i = 100;
				}
			
			//drawing line
			if(matchShape != 0 && !testing){
				*pcharacterLost = game.board[y2][x2];
				game.board[By][Bx] = (int)'0';
				game.board[Dy][Dx] = (int)'2';
				game.board[Dy][Bx] = (int)'9';
				for(int i = Dx + 1; i < Bx; i++)
					game.board[Dy][i] = (int)'5';
				for(int i = By + 1; i < Dy; i++)
					game.board[i][Bx] = (int)'4';
			}
		}
	}
}

void checkUAndZShape(mainScreen &game, int y1, int x1, int y2, int x2, bool testing, int &matchShape, int *pcharacterLost){
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
	
	int iUposible[game.row + 2], iZposible[game.col + 2];
	fill_n(iUposible, game.row + 2, 0);
	fill_n(iZposible, game.col + 2, 0);
	int iU = game.row + 2, iZ = game.col + 2;
	
	for(iU = 0; iU < game.row + 2;){//check U, ^, N shape
		if(game.board[iU][colL] == -1 && game.board[iU][colR] == -1){
			matchShape = 4;
			
			//check 1 horizontal line of U
			for(int j = colL + 1; j <= colR - 1; j++)
				if(game.board[iU][j] != -1){
					matchShape = 0;
					j = colR;
				}
			
			//check 2 vertical lines of  U
			
			if(y1 - 1 > iU && matchShape != 0)
				for(int j = y1 - 1; j > iU; j--)
					if(game.board[j][x1] != -1){
						matchShape = 0;
						j = -1;
					}
			
			if(y1 + 1 < iU && matchShape != 0)
				for(int j = y1 + 1; j < iU; j++)
					if(game.board[j][x1] != -1){
						matchShape = 0;
						j = 100;
					}
			
			if(y2 - 1 > iU && matchShape != 0)
				for(int j = y2 - 1; j > iU; j--)
					if(game.board[j][x2] != -1){
						matchShape = 0;
						j = -1;
					}
			
			if(y2 + 1 < iU && matchShape != 0)
				for(int j = y2 + 1; j < iU; j++)
					if(game.board[j][x2] != -1){
						matchShape = 0;
						j = 100;
					}

			if(matchShape != 0){
				iUposible[iU]++;
			}
		}
		matchShape = 0;
		++iU;
	}

	for(int i = 0; i < game.row + 2; i++){
		if(iUposible[i] == 1){
			matchShape = 4;
			if(iU == game.row + 2)
				iU = i;
			else if(i > rowT && i < rowB){
				iU = i;
				i = game.row + 5;
			}
			else if( (i < rowT || i > rowB) && 
			min( abs(rowB - i) , abs(rowT - i) ) < min( abs(rowB - iU) , abs(rowT - iU) ) ){
				iU = i;
			}
		}
	}
	
	if(iU == game.row + 2){
		for(iZ = 0; iZ < game.col + 2;){//check [, ], Z shape
			if(game.board[rowT][iZ] == -1 && game.board[rowB][iZ] == -1){
				matchShape = 5;
				
				//check 1 vertical line of [ 
				for(int j = rowT + 1; j <= rowB - 1; j++)
					if(game.board[j][iZ] != -1){
						matchShape = 0;
						j = rowB;
					}
				
				//check 2 horizontal lines of [
				
				if(x1 - 1 > iZ && matchShape != 0)
					for(int j = x1 - 1; j >= iZ; j--)
						if(game.board[y1][j] != -1){
							matchShape = 0;
							j = -1;
						}
				
				if(x1 + 1 < iZ && matchShape != 0)
					for(int j = x1 + 1; j <= iZ; j++)
						if(game.board[y1][j] != -1){
							matchShape = 0;
							j = 100;
						}
				
				if(x2 - 1 > iZ && matchShape != 0)
					for(int j = x2 - 1; j >= iZ; j--)
						if(game.board[y2][j] != -1){
							matchShape = 0;
							j = -1;
						}
				
				if(x2 + 1 < iZ && matchShape != 0)
					for(int j = x2 + 1; j <= iZ; j++)
						if(game.board[y2][j] != -1){
							matchShape = 0;
							j = 100;
						}
				
				if(matchShape != 0){
					iZposible[iZ]++;
				}
			}
			matchShape = 0;
			++iZ;
		}
	}

	for(int i = 0; i < game.col + 2; i++){
		if(iZposible[i] == 1){
			matchShape = 5;
			if(iZ == game.col + 2)
				iZ = i;
			else if(i > colL && i < colR){
				iZ = i;
				i = game.col + 5;
			}
			else if( (i < colL || i > colR) && 
			min( abs(colL - i) , abs(colR - i) ) < min( abs(colL - iZ) , abs(colR - iZ) ) ){
				iZ = i;
			}
		}
	}

	if(testing){
		if(iU != game.row + 2 || iZ != game.col + 2){
			matchShape = 7;
			return;
		}
		else{
			matchShape = 0;
			return;
		}
	}

	//drawing line
	else if(iU != game.row + 2 && !(iZ > colL && iZ < colR)){
		matchShape = 4;
		*pcharacterLost = game.board[y2][x2];

		for(int j = colL + 1; j <= colR - 1; j++)
			game.board[iU][j] = (int)'5';
		
		if(y1 > iU){
			game.board[y1][x1] = (int)'1';
			for(int j = y1 - 1; j > iU; j--)
				game.board[j][x1] = (int)'4';
			game.board[iU][x1] = (int)'6';
		}
		
		if(y1 < iU){
			game.board[y1][x1] = (int)'0';
			for(int j = y1 + 1; j < iU; j++)
				game.board[j][x1] = (int)'4';
			game.board[iU][x1] = (int)'8';
		}
		
		if(y2 > iU){
			game.board[y2][x2] = (int)'1';
			for(int j = y2 - 1; j > iU; j--)
				game.board[j][x2] = (int)'4';
			game.board[iU][x2] = (int)'7';
		}
		
		if(y2 < iU){
			game.board[y2][x2] = (int)'0';
			for(int j = y2 + 1; j < iU; j++)
				game.board[j][x2] = (int)'4';
			game.board[iU][x2] = (int)'9';
		}
		
		if(x1 > x2 && (iU < rowT || iU > rowB) ){
			int swap;
			swap = game.board[iU][x1];
			game.board[iU][x1] = game.board[iU][x2];
			game.board[iU][x2] = swap;
		}
		else if(x1 > x2 && y1 < y2 && (iU > rowT && iU < rowB) ){
			game.board[iU][x1] = (int)'9';
			game.board[iU][x2] = (int)'6';
		}
		else if(x1 < x2 && y1 < y2 && (iU > rowT && iU < rowB) ){
			game.board[iU][x1] = (int)'8';
			game.board[iU][x2] = (int)'7';
		}
		else if(x1 > x2 && y1 > y2 && (iU > rowT && iU < rowB) ){
			game.board[iU][x1] = (int)'7';
			game.board[iU][x2] = (int)'8';
		}
		else if(x1 < x2 && y1 > y2 && (iU > rowT && iU < rowB) ){
			game.board[iU][x1] = (int)'6';
			game.board[iU][x2] = (int)'9';
		}
	}
	else if(iZ != game.col + 2){
		matchShape = 5;
		*pcharacterLost = game.board[y2][x2];

		for(int j = rowT + 1; j <= rowB - 1; j++)
			game.board[j][iZ] = (int)'4';
		
		if(x1 > iZ){
			game.board[y1][x1] = (int)'3';
			for(int j = x1 - 1; j >= iZ; j--)
				game.board[y1][j] = (int)'5';
			game.board[y1][iZ] = (int)'6';
		}
		
		if(x1 < iZ){
			game.board[y1][x1] = (int)'2';
			for(int j = x1 + 1; j <= iZ; j++)
				game.board[y1][j] = (int)'5';
			game.board[y1][iZ] = (int)'7';
		}
		
		if(x2 > iZ){
			game.board[y2][x2] = (int)'3';
			for(int j = x2 - 1; j >= iZ; j--)
				game.board[y2][j] = (int)'5';
			game.board[y2][iZ] = (int)'8';
		}
		
		if(x2 < iZ){
			game.board[y2][x2] = (int)'2';
			for(int j = x2 + 1; j <= iZ; j++)
				game.board[y2][j] = (int)'5';
			game.board[y2][iZ] = (int)'9';
		}
		
		if(y1 > y2 && (iZ < colL || iZ > colR) ){
			int swap;
			swap = game.board[y1][iZ];
			game.board[y1][iZ] = game.board[y2][iZ];
			game.board[y2][iZ] = swap;
		}
		else if(y1 > y2 && x1 < x2 && (iZ > colL && iZ < colR) ){
			game.board[y1][iZ] = (int)'9';
			game.board[y2][iZ] = (int)'6';
		}
		else if(y1 < y2 && x1 < x2 && (iZ > colL && iZ < colR) ){
			game.board[y1][iZ] = (int)'7';
			game.board[y2][iZ] = (int)'8';
		}
		else if(y1 > y2 && x1 > x2 && (iZ > colL && iZ < colR) ){
			game.board[y1][iZ] = (int)'8';
			game.board[y2][iZ] = (int)'7';
		}
		else if(y1 < y2 && x1 > x2 && (iZ > colL && iZ < colR) ){
			game.board[y1][iZ] = (int)'6';
			game.board[y2][iZ] = (int)'9';
		}
	}
	else{
		*pcharacterLost = -3;
		matchShape = 0;
	}
}

void isLegalMatch(mainScreen &game, int y1, int x1, int y2, int x2, characterBlockInfor &CBI, bool testing, bool &legalMatch, int *pcharacterLost){
	legalMatch = true;
	int matchShape = 0;
	if(y1 == y2 && x1 == x2)
		legalMatch = false;
	if(y1 > game.row || y2 > game.row || x1 > game.col || x2 > game.col || y1 < 1 || y2 < 1 || x1 < 1 || x2 < 1)
		legalMatch = false;
	if(game.board[y1][x1] == -1 || game.board[y2][x2] == -1) 
		legalMatch = false;
	if(game.board[y1][x1] != game.board[y2][x2])
		legalMatch = false;
	
	if(legalMatch != false){
		legalMatch = false;

		if(y1 == y2){
			checkLineX(game, x1, x2, y1, testing, matchShape, pcharacterLost);
			legalMatch = matchShape;
		}
		else if(x1 == x2){
			checkLineY(game, y1, y2, x1, testing, matchShape, pcharacterLost);
			legalMatch = matchShape;
		}
		else if(game.board[y1][x2] == -1 || game.board[y2][x1] == -1){
			checkLShape(game, y1, x1, y2, x2, testing, matchShape, pcharacterLost);
			legalMatch = matchShape;
		}
		
		//Check U Shape and Z Shape after other Shapes are not correct 
		if(legalMatch == false){
			checkUAndZShape(game, y1, x1, y2, x2, testing, matchShape, pcharacterLost);
			legalMatch = matchShape;
		}
	}

	if(!testing && legalMatch){
		for(int i = 0; i < (game.row + 2)*3; i++)
			for(int j = 0; j < game.col + 2; j++)
				drawingLine(game, i, j);
		CBI.charBlock[ *pcharacterLost ]--;
		CBI.TChar-=2;
		for(int i = 0; i < game.row + 2; i++)
			for(int j = 0; j < game.col + 2; j++)
				if(game.board[i][j] >= (int)'0' && game.board[i][j] <= (int)'9')
					game.board[i][j] = -1;
	}
}

bool testingBoard(mainScreen &game, characterBlockInfor CBI, int *pcharacterLost){
	bool legalMatch = false;
	if(CBI.TChar == 0)
		return true;

	for(int i = 1; i <= game.row; i++){
		for(int j = 1; j <= game.col; j++){
			for(int m = 1; m <= game.row; m++){
				for(int n = 1; n <= game.col; n++){
					//i, j is coordinate of game.board[i][j]
					//m, n is coordinate of game.board[m][n]

					isLegalMatch(game, i, j, m, n, CBI, 1, legalMatch, pcharacterLost);
					if(legalMatch)
						return true;
				}
			}
		}
	}

	return false;
}

//this function is used for shuffling the board by player and auto-shuffling because of unmatchable board
void shuffleBoard(mainScreen &game, characterBlockInfor CBI){
	srand(time(0));

	//replace is the clone-array of CBI.charBlock
	int *replace;
	replace = new int [CBI.TDiffer];
	for(int i = 0; i < CBI.TDiffer; i++){
		replace[i] = CBI.charBlock[i];
	}

	//all blocks which contains positive value would be replaced with -2
	for(int i = 1; i <= game.row; i++)
		for(int j = 1; j <= game.col; j++)
			if( (game.board[i][j] >= 0 && game.board[i][j] <= CBI.TDiffer) )
				game.board[i][j] = -2;

	int value = 0;
	for(int count = 0; count < CBI.TChar;){
		int y1 = rand()%game.row + 1;
		int x1 = rand()%game.col + 1;
		int y2 = rand()%game.row + 1;
		int x2 = rand()%game.col + 1;

		//the algorithm finds 2 different random coordinates, if their value are equal to -2, 1 chararcter will be marked as "used in the board"
		if( (y1 != y2 || x1 != x2) && game.board[y1][x1] == -2 && game.board[y2][x2] == -2 && replace[value] != 0){
			game.board[y1][x1] = value;
			game.board[y2][x2] = value;
			replace[value]--;
			count+=2;
		}
		if(replace[value] == 0){
			value++;
		}
	}

	delete [] replace;
}

void deleteBoard(mainScreen &game, characterBlockInfor CBI){
	delete [] CBI.charBlock;

	for(int i = 0; i < game.row + 2; i++){
		delete [] game.board[i];
	}
	delete [] game.board;
}
