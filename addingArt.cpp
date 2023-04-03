#include "addingArt.h"
#include "showing.h"

void showTitleArt(){
	ifstream fi("BackgroundArt/titleArt.txt");
    string titleArt[100];
    
    int count = 0;
	while(!fi.eof()){
		getline(fi, titleArt[count] );
		count++;
	}
	
	for(int i = 0; i < count; i++){
		for(int j = 0; titleArt[i][j] != '\0'; j++){
			if(titleArt[i][j] == '#')
				setColor(4);
			else
				setColor(10);
				cout << titleArt[i][j];
		}
		cout << endl;
	}
    fi.close();
}