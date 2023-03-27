#include <iostream>
#include <fstream>
using namespace std;

ofstream fout;
ifstream fin;

int main(){
	ofstream fout;
    ifstream fin;

    char *background;
    background = new char [500];
    fin.open("art1.txt");
    int count = 0;
	while(count < 500){
		fin.get( background[count] );
		count++;
	}
    fin.close();
	
	cout << background;
    
    delete [] background;
}
