#include <windows.h>
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )
using namespace std;

int main()
{
	//Replace C:\\Users\\iD Student\\Downloads\\HarryPotter.wav with the location of your file
	PlaySound(TEXT("ES_Sunday_Coffee_Rebecca_Mardal.wav"), 0, SND_FILENAME);
	return 0;
}
