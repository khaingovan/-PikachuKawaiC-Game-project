#include "header.h"
#include "linkedList.h"

// This function should be put inside other function print in4 game
void countdown(time_t originalTime, int timeLeft, bool &overTime){
	time_t nowTime = time(0);
	// Calculate time left
    timeLeft -= difftime(nowTime, originalTime);
    if (timeLeft <= 0)
        overTime = true; 
    
	//15 = 0*16 + 15 white text black background
	setColor(15);
    gotoxy(96, 0);
    // Time left
	cout << timeLeft << "   ";
}

void createBoard(mainScreen &game, characterBlockInfor &CBI, int roundSelect){
	int maxSame;
	//the larger the board is, the more different characters needed.
	//for exmaple 4x4 board (hard mode) needs 6 different characters.
	if(roundSelect == -1){
		maxSame = 4;
		CBI.TDiffer = min(( (game.row - 2)*(game.col - 8) ) - 12, 20);
		CBI.TChar = (game.row - 2)*(game.col - 8);
	}
	else if(roundSelect == -2){
		maxSame = 4;
		CBI.TDiffer = min(( (game.row - 2)*(game.col - 2) ) - 12, 25);
		CBI.TChar = (game.row - 2)*(game.col - 2);
	}
	else{
		maxSame = 2;
		CBI.TDiffer = min((game.row*game.col) - 10, 40);
		CBI.TChar = game.row*game.col;
	}
	CBI.charBlock = new int [ CBI.TDiffer ];

	fill_n(CBI.charBlock, CBI.TDiffer, 0);
	
	//for easy mode
	if(roundSelect == -1){
		for(int count = 0; count < (game.row - 2)*(game.col - 8);){
			int y1 = rand()%(game.row - 2) + 2;
			int x1 = rand()%(game.col - 8) + 5;
			int y2 = rand()%(game.row - 2) + 2;
			int x2 = rand()%(game.col - 8) + 5;
			if( (y1 != y2 || x1 != x2) && getData(game.pHead[y1], x1) == -1 && getData(game.pHead[y2], x2) == -1){
				int character = rand()%CBI.TDiffer;
				while(CBI.charBlock[character] > maxSame){
					character = rand()%CBI.TDiffer;
				}
				CBI.charBlock[character]++;
				changePosData(game.pHead[y1], x1, character);
				changePosData(game.pHead[y2], x2, character);
				count+=2;
			}
		}
	}
	//for normal mode
	else if(roundSelect == -2){
		for(int count = 0; count < (game.row - 2)*(game.col - 2);){
			int y1 = rand()%(game.row - 2) + 2;
			int x1 = rand()%(game.col - 2) + 2;
			int y2 = rand()%(game.row - 2) + 2;
			int x2 = rand()%(game.col - 2) + 2;
			if( (y1 != y2 || x1 != x2) && getData(game.pHead[y1], x1) == -1 && getData(game.pHead[y2], x2) == -1){
				int character = rand()%CBI.TDiffer;
				while(CBI.charBlock[character] > maxSame){
					character = rand()%CBI.TDiffer;
				}
				CBI.charBlock[character]++;
				changePosData(game.pHead[y1], x1, character);
				changePosData(game.pHead[y2], x2, character);
				count+=2;
			}
		}
	}
	//for hard mode
	else if(roundSelect == -3){
		//for(int count = 0; count < game.row*game.col;){
		for(int count = 0; count < 8*20;){
			int y1 = rand()%game.row + 1;
			int x1 = rand()%game.col + 1;
			int y2 = rand()%game.row + 1;
			int x2 = rand()%game.col + 1;
			if( (y1 != y2 || x1 != x2) && getData(game.pHead[y1], x1) == -1 && getData(game.pHead[y2], x2) == -1){
				int character = rand()%CBI.TDiffer;
				while(CBI.charBlock[character] > maxSame){
					character = rand()%CBI.TDiffer;
				}
				CBI.charBlock[character]++;
				changePosData(game.pHead[y1], x1, character);
				changePosData(game.pHead[y2], x2, character);
				count+=2;
			}
		}
	}
}

void playPikachu(Player &user, mainScreen &game, int roundSelect, bool accountLogedIn, int &scoreWhenOutGame){
	characterBlockInfor CBI;
	int level = 1;
	int score = 0;
	scoreWhenOutGame = 0;
	
	//Timer_____
	time_t originalTime = time(0);
    time_t nowTime = time(0);
	bool overTime = false;
	int timeLeft;
	if(roundSelect == -1)
		timeLeft = 240;
	else if(roundSelect == -2)
		timeLeft = 270;
	else
		timeLeft = 300;
	cout << 20;

	//all blocks' value in board become -1
	game.board = new int *[game.row + 2];
	game.pHead = new Node*[game.row + 2];
	for(int i = 0; i < game.row + 2; i++){
		game.board[i] = new int [game.col + 2];
		*(game.pHead + i) = NULL;
	}
	for(int i = 0; i < game.row + 2; i++){
		game.pHead[i] = NULL;
		fill_n(game.board[i], game.col + 2, -1);
		for(int j = 0; j < game.col + 2; j++)
			addTail(game.pHead[i], -1);
	}
	
	srand(time(0));
	createBoard(game, CBI, roundSelect);

	//create background
	ifstream fi("BackgroundArt/bg4.txt");
	char bgArt[40][120];
	int countLine = 0;
	while(!fi.eof()){
		fi.getline(bgArt[countLine], 120);
		countLine++;
	}

	char yn;
	clearScreen();
	drawOutsideBoard(level);
	setColor(15);
	gotoxy(67, 0);
	cout << left << setw(10) << score;
	drawingBoard(game, bgArt);
	double numTime = 0;
	int xr = 1, yr = 1;
	drawKey(game, yr, xr, game.row + 2, game.col + 2);
	
	bool getButton = true;
	int move;
	int y1 = game.row + 2, x1 = game.col + 2;
	int y2 = game.row + 2, x2 = game.col + 2;
	while(getButton){
		int *pcharacterLost, characterLost = -3;
		pcharacterLost = &characterLost;
		
		bool legalMatch = false;
		bool autoShuffle = false;

		//time out
		if(overTime){
			scoreWhenOutGame = score;
			//4 = 0*16 + 4 red text black background
			setColor(4);
			gotoxy(0, 36);
			cout << "Time out! Press any key to go to back to menu.";
			char ch = getch();
			getButton = false;
			break;
		}
		
		//when game end
		if(CBI.TChar == 0 && level == 5){
			scoreWhenOutGame = score;
			//10 = 0*16 + 10 bright green text black background
			setColor(10);
			gotoxy(0, 36);
    		cout << "You won! Press any key to go to back to menu.";
			char ch = getch();
			getButton = false;
			break;
		}
		if(CBI.TChar == 0){
			//15 = 0*16 + 15 white text black background
			setColor(15);
			clearScreen();
			
			scoreWhenOutGame = score;
			//15 = 0*16 + 15 white text black background
			setColor(15);
			drawOutsideBoard(level);
			drawingBoard(game, bgArt);
			
			//Output score
			//15 = 0*16 + 15 white text black background
			setColor(15);
			gotoxy(67, 0);
			cout << left << setw(10) << score;

			//15 = 0*16 + 15 white text black background
			setColor(15);
			gotoxy(0, 36);
    		cout << "Congratulate!" << endl;

			if(level < 5){
				cout << "Play level " << level + 1 << " ? (Y/N) ";
				char buttonContinuePlay = getch();
				switch(buttonContinuePlay){
					case 'y':
					{
						level++;
						if(roundSelect == -1)
							timeLeft = 240;
						else if(roundSelect == -2)
							timeLeft = 270;
						else
							timeLeft = 300;
						originalTime = time(0);
						nowTime = time(0);
						countdown(originalTime, timeLeft, overTime);
						createBoard(game, CBI, roundSelect);
						clearScreen();
						drawOutsideBoard(level);
						drawingBoard(game, bgArt);
						yr = 1; xr = 1;
						break;
					}
					case 'n':
					{
						getButton = false;
						break;
					}
				}
			}
		}
		if(!getButton || (CBI.TChar == 0 && level == 5))
			break;
		
		if(CBI.TChar != 0){
			if( !testingBoard(game, CBI, pcharacterLost) ){
				autoShuffle = true;
				//79 = 4*16 + 15 white text red background
				setColor(79);
				gotoxy( (game.col + 2)*5/2 - 8 , (game.row + 2)*3/2 - 1);
				cout << (char)(201) << (char)(205) << (char)(205) << (char)(205) << (char)(205)
					 << (char)(205) << (char)(205) << (char)(205) << (char)(205) << (char)(205)
					 << (char)(205) << (char)(205) << (char)(205) << (char)(205) << (char)(205)
					 << (char)(187);
				gotoxy( (game.col + 2)*5/2 - 8 , (game.row + 2)*3/2 );
				cout << (char)(186) << " Auto Shuffle "                          << (char)(186);
				gotoxy( (game.col + 2)*5/2 - 8 , (game.row + 2)*3/2 + 1);
				cout << (char)(200) << (char)(205) << (char)(205) << (char)(205) << (char)(205)
					 << (char)(205) << (char)(205) << (char)(205) << (char)(205) << (char)(205)
					 << (char)(205) << (char)(205) << (char)(205) << (char)(205) << (char)(205)
					 << (char)(188);
				Sleep(500);
			}
			while( !testingBoard(game, CBI, pcharacterLost) ){
				shuffleBoard(game, CBI);
			}
			if(autoShuffle){
				drawingBoard(game, bgArt);
				autoShuffle = false;
			}
			drawKey(game, yr, xr, game.row + 2, game.col + 2);

			//getting arrow button
			if(kbhit()){
				char button = getch();
				switch(button){
					case KeyUp: {
						drawUnKey(game, yr, xr, bgArt, y1, x1);
						yr--;
						if(yr < 1)
							yr = game.row;
						drawKey(game, yr, xr, y1, x1);
						break;
					}
					case KeyDown: {
						drawUnKey(game, yr, xr, bgArt, y1, x1);
						yr++;
						if(yr > game.row)
							yr = 1;
						drawKey(game, yr, xr, y1, x1);
						break;
					}
					case KeyLeft: {
						drawUnKey(game, yr, xr, bgArt, y1, x1);
						xr--;
						if(xr < 1)
							xr = game.col;
						drawKey(game, yr, xr, y1, x1);
						break;
					}
					case KeyRight: {
						drawUnKey(game, yr, xr, bgArt, y1, x1);
						xr++;
						if(xr > game.col)
							xr = 1;
						drawKey(game, yr, xr, y1, x1);
						break;
					}
					case 's': {//Shuffle
						shuffleBoard(game, CBI);
						drawingBoard(game, bgArt);
						break;
					}
					case 'a': {//Auto play
						for(int i = 1; i <= game.row; i++){
							for(int j = 1; j <= game.col; j++){
								for(int m = 1; m <= game.row; m++){
									for(int n = 1; n <= game.col; n++){
										//i, j is coordinate of game.board[i][j]
										//m, n is coordinate of game.board[m][n]

										isLegalMatch(game, i, j, m, n, CBI, 1, legalMatch, pcharacterLost);
										if(legalMatch){
											drawHint(game, i, j);
											drawHint(game, m, n);
											score-=50;
											//15 = 0*16 + 15 white text black background
											setColor(15);
											gotoxy(67, 0);
											cout << left << setw(10) << score;
											i = game.row + 2;
											j = game.col + 2;
											m = game.row + 2;
											n = game.col + 2;
										}
									}
								}
							}
						}
						drawKey(game, yr, xr, y1, x1);
						break;
					}
					case Space: {
						if(game.board[yr][xr] == -1 && getData(game.pHead[yr], xr) == -1){}
						else if(y1 == game.row + 2){
							y1 = yr;
							x1 = xr;
							drawKey(game, yr, xr, y1, x1);
						}
						else{
							y2 = yr;
							x2 = xr;
							isLegalMatch(game, y1, x1, y2, x2, CBI, 0, legalMatch, pcharacterLost);
							if(*pcharacterLost != -3){
								selectSound();
								Sleep(200);
								levelMove(game, level, roundSelect);
								
								if(level == 1)
									score+=10;
								else if(level >= 2 && level <= 5)
									score+=20;
								//15 = 0*16 + 15 white text black background
								setColor(15);
								gotoxy(67, 0);
								cout << left << setw(10) << score;
							}
							drawingBoard(game, bgArt);
							y1 = game.row + 2, x1 = game.col + 2;
							y2 = game.row + 2, x2 = game.col + 2;
							drawKey(game, yr, xr, y1, x1);
						}

						break;
					}
					case Esc:
						getButton = false;
				}
			}
			countdown(originalTime, timeLeft, overTime);
			Sleep(5);
		}
	}

	//15 = 0*16 + 15 white text black background
	setColor(15);
	
	fi.close();
	deleteBoard(game, CBI);
	delete [] game.pHead;
}
