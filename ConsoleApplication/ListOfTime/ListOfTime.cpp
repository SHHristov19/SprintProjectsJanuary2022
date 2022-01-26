#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

//Declare button ^
#define KEY_UP 72

//Declare button v    
#define KEY_DOWN 80

//Declare button < 
#define KEY_LEFT 75

//Declare button >
#define KEY_RIGHT 77

//Declare button Enter
#define KEY_ENTER 13 

void activeSeeStory()
{
	cout << endl << endl << endl << endl << endl << endl;
	cout << "\x1b[0;33m" << "                                    _____ / \\ ========================================================== / \\ _____" << endl;
	cout << "                                   /     [   ]                                                          [   ]     \\" << endl;
	cout << "                                  {      [   ]                                                          [   ]      }" << endl;
	cout << "                                   \\_____[   ]                                                          [   ]_____/" << endl;
	cout << "                                          \\ / ========================================================== \\ /" << "\x1b[1;37m" << endl;
	cout << "                                             \\                                                          /  " << endl;
	cout << "                                              |                                                        |  " << endl;
	cout << "                                              |             __             _            _               |" << endl;
	cout << "                                              |            / /  ___   ___ | | __   __ _| |_             |" << endl;
	cout << "                                              |           / /  / _ \\ / _ \\| |/ /  / _` | __|           |" << endl;
	cout << "                                               |         / /__| (_) | (_) |   <  | (_| | |_            \\" << endl;
	cout << "                                               /         \\____/\\___/ \\___/|_|\\_\\  \\__,_|\\__|           |" << endl;
	cout << "                                              |                   _     _                              |" << endl;
	cout << "                                              |             /\\  /(_)___| |_ ___  _ __ _   _           /" << endl;
	cout << "                                             |             / /_/ / / __| __/ _ \\| '__| | | |          \\" << endl;
	cout << "                                              \\           / __  /| \\__ \\ || (_) | |  | |_| |           |" << endl;
	cout << "                                              /           \\/ /_/ |_|___/\\__\\___/|_|   \\__, |           |" << endl;
	cout << "                                              |                                       |___/           | " << endl;
	cout << "                                              |                                                       |" << endl;
	cout << "                                               |                                                     /   " << endl;
	cout << "                                              |                                                      \\ " << endl;
	cout << "                                               \\                  " << "\x1b[1;33m" << "-> See Story" << "\x1b[1;37m" << "                        | " << endl;
	cout << "                                                |                                                    /" << endl;
}

void writeSeeStory()
{
	cout << endl << endl << endl << endl << endl << endl;
	cout << "\x1b[0;33m" << "                                    _____ / \\ ========================================================== / \\ _____" << endl;
	cout << "                                   /     [   ]                                                          [   ]     \\" << endl;
	cout << "                                  {      [   ]                                                          [   ]      }" << endl;
	cout << "                                   \\_____[   ]                                                          [   ]_____/" << endl;
	cout << "                                          \\ / ========================================================== \\ /" << "\x1b[1;37m" << endl;
	cout << "                                             \\                                                          /  " << endl;
	cout << "                                              |                                                        |  " << endl;
	cout << "                                              |             __             _            _               |" << endl;
	cout << "                                              |            / /  ___   ___ | | __   __ _| |_             |" << endl;
	cout << "                                              |           / /  / _ \\ / _ \\| |/ /  / _` | __|           |" << endl;
	cout << "                                               |         / /__| (_) | (_) |   <  | (_| | |_            \\" << endl;
	cout << "                                               /         \\____/\\___/ \\___/|_|\\_\\  \\__,_|\\__|           |" << endl;
	cout << "                                              |                   _     _                              |" << endl;
	cout << "                                              |             /\\  /(_)___| |_ ___  _ __ _   _           /" << endl;
	cout << "                                             |             / /_/ / / __| __/ _ \\| '__| | | |          \\" << endl;
	cout << "                                              \\           / __  /| \\__ \\ || (_) | |  | |_| |           |" << endl;
	cout << "                                              /           \\/ /_/ |_|___/\\__\\___/|_|   \\__, |           |" << endl;
	cout << "                                              |                                       |___/           | " << endl;
	cout << "                                              |                                                       |" << endl;
	cout << "                                               |                                                     /   " << endl;
	cout << "                                              |                                                      \\ " << endl;
	cout << "                                               \\                   See Story                          | " << endl;
	cout << "                                                |                                                    /" << endl;
}

void writeAddStory()
{
	cout << "                                                /                                                    \\" << endl;
	cout << "                                               |                   Add Story                          |" << endl;
	cout << "                                               |                                                      |" << endl;
}

void activeAddStory()
{
	cout << "                                                /                                                    \\" << endl;
	cout << "                                               |                  " << "\x1b[1;33m" << "-> Add Story" << "\x1b[1;37m" << "                        |" << endl;
	cout << "                                               |                                                      |" << endl;
}

void writeSearch()
{
	cout << "                                               |                                                      |" << endl;
	cout << "                                               \\                   Search Story                       /" << endl;
	cout << "                                               |                                                      \\" << endl;
}

void activeSearch()
{
	cout << "                                               |                                                      |" << endl;
	cout << "                                               \\                  " << "\x1b[1;33m" << "-> Search Story" << "\x1b[1;37m" << "                     /" << endl;
	cout << "                                               |                                                      \\" << endl;
}

void writeHowItWorks()
{
	cout << "                                               \\                                                       /" << endl;
	cout << "                                               /                   How it works                        |" << endl;
}

void activeHowItWorks()
{
	cout << "                                               \\                                                       /" << endl;
	cout << "                                               /                  " << "\x1b[1;33m" << "-> How it works" << "\x1b[1;37m" << "                      | " << endl;
}

void writeAboutUs()
{
	cout << "                                              \\                                                       /" << endl;
	cout << "                                               \\                                                       \\  " << endl;
	cout << "                                               /                   About us                            |  " << endl;
	cout << "                                               |                                                       | " << endl;
	cout << "                                               |                                                       |  " << endl;

}

void activeAboutUs()
{
	cout << "                                              \\                                                       /" << endl;
	cout << "                                               \\                                                       \\  " << endl;
	cout << "                                               /                  " << "\x1b[1;33m" << "-> About us" << "\x1b[1;37m" << "                          |  " << endl;
	cout << "                                               |                                                       | " << endl;
	cout << "                                               |                                                       |  " << endl;
}

void writeExit()
{
	cout << "                                               |                   Exit                                \\" << endl;
	cout << "                                               \\                                                       |" << endl;
	cout << "                                              /                                                        |" << endl;
	cout << "                                             /                                                          \\  " << endl;
	cout << "\x1b[0;33m" << "                                    _____ / \\ ========================================================== / \\ _____" << endl;
	cout << "                                   /     [   ]                                                          [   ]     \\" << endl;
	cout << "                                  {      [   ]                                                          [   ]      }" << endl;
	cout << "                                   \\_____[   ]                                                          [   ]_____/" << endl;
	cout << "                                          \\ / ========================================================== \\ /" << "\x1b[1;37m" << endl;
}

void activeExit()
{
	cout << "                                               |                  " << "\x1b[1;33m" << "-> Exit" << "\x1b[1;37m" << "                              \\" << endl;
	cout << "                                               \\                                                       |" << endl;
	cout << "                                              /                                                        |" << endl;
	cout << "                                             /                                                          \\  " << endl;
	cout << "\x1b[0;33m" << "                                    _____ / \\ ========================================================== / \\ _____" << endl;
	cout << "                                   /     [   ]                                                          [   ]     \\" << endl;
	cout << "                                  {      [   ]                                                          [   ]      }" << endl;
	cout << "                                   \\_____[   ]                                                          [   ]_____/" << endl;
	cout << "                                          \\ / ========================================================== \\ /" << "\x1b[1;37m" << endl;
}

void writeBackWhite()
{
	cout << endl << endl;
	cout << "<- Back" << endl;
}

void printActiveSeeStory()
{
	activeSeeStory();
	writeAddStory();
	writeSearch();
	writeHowItWorks();
	writeAboutUs();
	writeExit();
}

void printActiveAddStory()
{
	writeSeeStory();
	activeAddStory();
	writeSearch();
	writeHowItWorks();
	writeAboutUs();
	writeExit();
}

void printActiveSearch()
{
	writeSeeStory();
	writeAddStory();
	activeSearch();
	writeHowItWorks();
	writeAboutUs();
	writeExit();
}

void printActiveHowItWorks()
{
	writeSeeStory();
	writeAddStory();
	writeSearch();
	activeHowItWorks();
	writeAboutUs();
	writeExit();
}

void printActiveAboutUs()
{
	writeSeeStory();
	writeAddStory();
	writeSearch();
	writeHowItWorks();
	activeAboutUs();
	writeExit();
}

void printActiveExit()
{
	writeSeeStory();
	writeAddStory();
	writeSearch();
	writeHowItWorks();
	writeAboutUs();
	activeExit();
}


void inputDataInFile()
{
	string title, year, place, latitude, longitude, description;
	bool dataAddCorrectly = false;
	ofstream file("Data.csv", ios_base::app);
	if (!file.is_open())
	{
		cout << "Error opening file";
	}
	else
	{
		cout << "Enter the title of the History event : ";
		getline(cin, title);
		file << title << ",";
		cout << "Enter the year of the History event : ";
		getline(cin, year);
		file << year << ",";
		cout << "Enter where exactly happened this event : ";
		getline(cin, place);
		file << place << ",";
		cout << "Enter the latitude of this place : ";
		getline(cin, latitude);
		file << latitude << ",";
		cout << "Enter the longitude of this place : ";
		getline(cin, longitude);
		file << longitude << ",";
		cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA !!!  ";
		cout << "\x1b[1;37m" << "Enter what's happened in this place : ";
		getline(cin, description);
		while (dataAddCorrectly == false)
		{
			if (description.find(',') != string::npos)
			{
				system("CLS");
				cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA !!!  ";
				cout << "\x1b[1;37m" << "Enter what's happened in this place : ";
				getline(cin, description);
			}
			else
			{
				dataAddCorrectly = true;
				file << description << endl;
				system("CLS");
				cout << "The data are added correctly" << endl;
			}
		}
		file.close();
	}
}
bool loopmovement(int choice)
{
	printActiveSeeStory();
	choice = 1;
	while (true) {
		switch (_getch()) {
		case KEY_UP:
			if (choice == 2)
			{
				system("CLS");
				printActiveSeeStory();
				choice = 1;
				break;
			}
			if (choice == 3)
			{
				system("CLS");
				printActiveAddStory();
				choice = 2;
				break;
			}
			if (choice == 4)
			{
				system("CLS");
				printActiveSearch();
				choice = 3;
				break;
			}
			if (choice == 5)
			{
				system("CLS");
				printActiveHowItWorks();
				choice = 4;
				break;
			}
			if (choice == 6)
			{
				system("CLS");
				printActiveAboutUs();
				choice = 5;
				break;
			}
			break;
		case KEY_DOWN:
			if (choice == 1)
			{
				system("CLS");
				printActiveAddStory();
				choice = 2;
				break;
			}
			if (choice == 2)
			{
				system("CLS");
				printActiveSearch();
				choice = 3;
				break;
			}
			if (choice == 3)
			{
				system("CLS");
				printActiveHowItWorks();
				choice = 4;
				break;
			}
			if (choice == 4)
			{
				system("CLS");
				printActiveAboutUs();
				choice = 5;
				break;
			}
			if (choice == 5)
			{
				system("CLS");
				printActiveExit();
				choice = 6;
				break;
			}
			break;
		case KEY_ENTER:
			if (choice == 1)
			{
				system("CLS");
				choice = 7;
				writeBackWhite();
				break;

			}
			if (choice == 2)
			{
				system("CLS");
				inputDataInFile();
				choice = 7;
				writeBackWhite();
				break;
			}
			if (choice == 3)
			{
				system("CLS");
				choice = 7;
				writeBackWhite();
				break;
			}
			if (choice == 4)
			{
				system("CLS");
				choice = 7;
				writeBackWhite();
				break;
			}
			if (choice == 5)
			{
				system("CLS");
				writeBackWhite();
				choice = 7;
				break;
			}
			if (choice == 6)
			{
				return 0;
				break;
			}
			if (choice == 7)
			{
				system("CLS");
				printActiveSeeStory();
				choice = 1;
				break;
			}
			break;
		default:
			break;
		}
	}
}
int main()
{
	int choice = 1;
	loopmovement(choice);
}