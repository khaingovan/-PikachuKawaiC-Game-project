#include "header.h"


inline void wait ( short seconds )
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait);
}

inline void countDown()
{
	for (short minutes = 3; minutes >= 0; --minutes)
	{
		for (short seconds = 59; seconds >= 0; --seconds)
		{
			setColor(15);
            gotoxy(96, 0);
			cout << minutes << ':' << seconds;
			wait(1);
		}
	}
}

void createBoard(mainScreen &game, characterBlockInfor &CBI, int roundSelect){
	//number of remaining blocks in game
	CBI.TChar = game.row*game.col;

	int maxSame;
	//the larger the board is, the more different characters needed.
	//for exmaple 4x4 board (hard mode) needs 6 different characters.
	if(roundSelect == -1){
		maxSame = 4;
		CBI.TDiffer = min(( (game.row - 2)*(game.col - 6) ) - 12, 25);
		CBI.TChar = (game.row - 2)*(game.col - 6);
	}
	else if(roundSelect == -2){
		maxSame = 4;
		CBI.TDiffer = min((game.row*game.col) - 12, 25);
	}
	else{
		maxSame = 2;
		CBI.TDiffer = min((game.row*game.col) - 10, 40);
	}
	CBI.charBlock = new int [ CBI.TDiffer ];

	fill_n(CBI.charBlock, CBI.TDiffer, 0);
	if(roundSelect <= -2 ){
		for(int count = 0; count < game.row*game.col;){
			int y1 = rand()%game.row + 1;
			int x1 = rand()%game.col + 1;
			int y2 = rand()%game.row + 1;
			int x2 = rand()%game.col + 1;
			if( (y1 != y2 || x1 != x2) && game.board[y1][x1] == -1 && game.board[y2][x2] == -1){
				int character = rand()%CBI.TDiffer;
				while(CBI.charBlock[character] > maxSame){
					character = rand()%CBI.TDiffer;
				}
				CBI.charBlock[character]++;
				game.board[y1][x1] = character;
				game.board[y2][x2] = character;
				count+=2;
			}
		}
	}
	//for easy mode only
	else{
		for(int count = 0; count < (game.row - 2)*(game.col - 6);){
			int y1 = rand()%(game.row - 2) + 2;
			int x1 = rand()%(game.col - 6) + 4;
			int y2 = rand()%(game.row - 2) + 2;
			int x2 = rand()%(game.col - 6) + 4;
			if( (y1 != y2 || x1 != x2) && game.board[y1][x1] == -1 && game.board[y2][x2] == -1){
				int character = rand()%CBI.TDiffer;
				while(CBI.charBlock[character] > maxSame){
					character = rand()%CBI.TDiffer;
				}
				CBI.charBlock[character]++;
				game.board[y1][x1] = character;
				game.board[y2][x2] = character;
				count+=2;
			}
		}
	}
}

void playPikachu(Player &user, mainScreen &game, int roundSelect){
	characterBlockInfor CBI;
	int level = 1;
	user.record = 0;

	//all blocks' value in board become -1
	game.board = new int *[game.row + 2];
	for(int i = 0; i < game.row + 2; i++){
		game.board[i] = new int [game.col + 2];
	}
	for(int i = 0; i < game.row + 2; i++)
		fill_n(game.board[i], game.col + 2, -1);
	
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
	drawOutsideBoard(level, user);
	drawingBoard(game, bgArt);
	int numTime = 0;
	//drawTimer(true, numTime);
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
		
		//when game end
		if(CBI.TChar == 0 && level == 5)
			break;
		if(CBI.TChar == 0){
			//drawTimer(false, numTime);
			//15 = 0*16 + 15 white text black background
			setColor(15);
			clearScreen();
			
			//15 = 0*16 + 15 white text black background
			setColor(15);
			drawOutsideBoard(level, user);
			drawingBoard(game, bgArt);

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
						createBoard(game, CBI, roundSelect);
						clearScreen();
						drawOutsideBoard(level, user);
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
			char button = getch();
			switch(button){
				case KeyUp: {
					drawUnKey(game, yr, xr, bgArt, y1, x1);
					yr--;
					if(yr < 1)
						yr = game.row;
					//yr = max(yr - 1, 1);
					drawKey(game, yr, xr, y1, x1);
					break;
				}
				case KeyDown: {
					drawUnKey(game, yr, xr, bgArt, y1, x1);
					yr++;
					if(yr > game.row)
						yr = 1;
					//yr = min(yr + 1, row);
					drawKey(game, yr, xr, y1, x1);
					break;
				}
				case KeyLeft: {
					drawUnKey(game, yr, xr, bgArt, y1, x1);
					xr--;
					if(xr < 1)
						xr = game.col;
					//xr = max(xr - 1, 1);
					drawKey(game, yr, xr, y1, x1);
					break;
				}
				case KeyRight: {
					drawUnKey(game, yr, xr, bgArt, y1, x1);
					xr++;
					if(xr > game.col)
						xr = 1;
					//xr = min(xr + 1, col);
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

									isLegalMatch(game, i, j, m, n, CBI, 0, legalMatch, pcharacterLost);
									if(legalMatch){
										Sleep(200);
										levelMove(game, level);
										user.record-=50;
										//15 = 0*16 + 15 white text black background
										setColor(15);
										gotoxy(67, 0);
										cout << user.record;
										drawingBoard(game, bgArt);
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
					if(game.board[yr][xr] == -1){}
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
							Sleep(200);
							levelMove(game, level);
							
							if(level == 1)
								user.record+=10;
							else if(level >= 2 && level <= 5)
								user.record+=20;
							//15 = 0*16 + 15 white text black background
							setColor(15);
							gotoxy(67, 0);
							cout << user.record;
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
	}

	//15 = 0*16 + 15 white text black background
	setColor(15);
	gotoxy(0, 36);
	cout << "\t\t\t\t \n \t\t\t\t \n \t\t\t\t \n \t\t\t\t \n \t\t\t\t \n \t\t\t\t";
	setColor(15);
	gotoxy(0, 36);
    cout << "Game ended!";
	
	fi.close();
	deleteBoard(game, CBI);
}