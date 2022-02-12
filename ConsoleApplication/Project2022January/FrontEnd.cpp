#include <iostream>
#include "FrontEnd.h"
using namespace std;

//Sets on Sign In and prints a part of the menu
void activeSignIn() 
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
	cout << "                                              |                                                      /" << endl;
	cout << "                                              /                                                      \\" << endl;
	cout << "                                              |                  " << "\x1b[1;33m" << "-> Sign In" << "\x1b[1;37m" << "                          |" << endl;
	cout << "                                              \\                                                      /   " << endl;
}

//Prints Sign In on the start menu and prints a part of the menu
void writeSignIn()
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
	cout << "                                              |                                                      /" << endl;
	cout << "                                              /                                                      \\" << endl;
	cout << "                                              |                    Sign In                           |" << endl;
	cout << "                                              \\                                                      /   " << endl;
}

//Sets arrow on See Story
void activeSeeStory()
{
	cout << "                                              |                                                      \\ " << endl;
	cout << "                                               \\                  " << "\x1b[1;33m" << "-> See Story" << "\x1b[1;37m" << "                        | " << endl;
	cout << "                                                |                                                    /" << endl;
}

//Prints See Story on the start menu
void writeSeeStory()
{
	cout << "                                              |                                                      \\ " << endl;
	cout << "                                               \\                   See Story                          | " << endl;
	cout << "                                                |                                                    /" << endl;
}

//Prints Add Story on the start menu
void writeAddStory()
{
	cout << "                                                /                                                    \\" << endl;
	cout << "                                               |                   Add Story                          |" << endl;
	cout << "                                               |                                                      |" << endl;
}

//Sets arrow on Add Story
void activeAddStory()
{
	cout << "                                                /                                                    \\" << endl;
	cout << "                                               |                  " << "\x1b[1;33m" << "-> Add Story" << "\x1b[1;37m" << "                        |" << endl;
	cout << "                                               |                                                      |" << endl;
}

//Prints Search Story on the start menu
void writeSearch()
{
	cout << "                                               |                                                      |" << endl;
	cout << "                                               \\                   Search Story                       /" << endl;
	cout << "                                               |                                                      \\" << endl;
}

//Sets arrow on Search Story
void activeSearch()
{
	cout << "                                               |                                                      |" << endl;
	cout << "                                               \\                  " << "\x1b[1;33m" << "-> Search Story" << "\x1b[1;37m" << "                     /" << endl;
	cout << "                                               |                                                      \\" << endl;
}

//Print How it works on the start menu
void writeHowItWorks()
{
	cout << "                                               \\                                                       /" << endl;
	cout << "                                               /                   How it works                        |" << endl;
}

//Sets arrow on How it works
void activeHowItWorks()
{
	cout << "                                               \\                                                       /" << endl;
	cout << "                                               /                  " << "\x1b[1;33m" << "-> How it works" << "\x1b[1;37m" << "                      | " << endl;
}

//Prints About us on the start menu
void writeAboutUs()
{
	cout << "                                              \\                                                       /" << endl;
	cout << "                                               \\                                                       \\  " << endl;
	cout << "                                               /                   About us                            |  " << endl;
	cout << "                                               |                                                       | " << endl;
	cout << "                                               |                                                       |  " << endl;

}

//Sets arrow on About us
void activeAboutUs()
{
	cout << "                                              \\                                                       /" << endl;
	cout << "                                               \\                                                       \\  " << endl;
	cout << "                                               /                  " << "\x1b[1;33m" << "-> About us" << "\x1b[1;37m" << "                          |  " << endl;
	cout << "                                               |                                                       | " << endl;
	cout << "                                               |                                                       |  " << endl;
}

//Prints Exit on the start menu
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

//Sets arrow on Exit
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

//Prints "Back" on a selected option allowing you to return
void writeBackWhite()
{
	cout << endl << endl;
	cout << "<- Back" << endl;
}

//Prints ASCII Art title and information about the team
void printAboutUs()
{
	cout << "\x1b[1;33m" << "                         _   _              _     _   _    " << endl;
	cout << "                        /_\\ | |__  ___ _  _| |_  | | | |___" << endl;
	cout << "                       / _ \\| '_ \\/ _ \\ || |  _| | |_| (_-<" << endl;
	cout << "                      /_/ \\_\\_.__/\\___/\\_,_|\\__|  \\___//__/" << "\x1b[1;37m" << endl;
	cout << endl << endl << endl;
	cout << "Our team is made of 4 people:" << endl;
	cout << "       Stefan Hristov - Back End" << endl;
	cout << "       Daniel Kolev - Front End" << endl;
	cout << "       Zlatomir Kostadinov - QA" << endl;
	cout << "       Todor Zafirov - Scrum Trainer" << endl;
}

//Prints ASCII Art title of Add Story in yellow
void printTitleHowItWorks()
{
	cout << "\x1b[1;33m" << "                                     _  _              _ _                    _       " << endl;
	cout << "                                    | || |_____ __ __ (_) |_  __ __ _____ _ _| |__ ___" << endl;
	cout << "                                    | __ / _ \\ V  V / | |  _| \\ V  V / _ \\ '_| / /(_-<" << endl;
	cout << "                                    |_||_\\___/\\_/\\_/  |_|\\__|  \\_/\\_/\\___/_| |_\\_\\/__/" << "\x1b[1;37m" << endl << endl << endl << endl; 
}

//Prints information about the program and how it must be used
void printHowItWorks()
{
	cout << "                   1. You have to sign in in order to have access!" << endl;
	cout << "                   2. The program is used to sort historical events by year that you can add and later on search them." << endl;
	cout << "                   3. To add an event you have to click on Add story and input all the data." << endl;
	cout << "                   4. Then you can see it or search it using See Story or Search story options." << endl;
}

//Prints ASCII Art title of Add Story in yellow
void printTitleAddStory()
{
	cout << "\x1b[1;33m" << "                                       _      _    _   ___ _                " << endl;
	cout << "                                      /_\\  __| |__| | / __| |_ ___ _ _ _  _ " << endl;
	cout << "                                     / _ \\/ _` / _` | \\__ \\  _/ _ \\ '_| || |" << endl;
	cout << "                                    /_/ \\_\\__,_\\__,_| |___/\\__\\___/_|  \\_, |" << endl;
	cout << "                                                                       |__/ " << "\x1b[1;37m" << endl << endl << endl << endl;
}

//Prints ASCII Art title of See story in yellow
void printTitleSeeStory()
{
	cout << "\x1b[1;33m" << "                                     ___            ___ _                " << endl;
	cout << "                                    / __| ___ ___  / __| |_ ___ _ _ _  _ " << endl;
	cout << "                                    \\__ \\/ -_) -_) \\__ \\  _/ _ \\ '_| || |" << endl;
	cout << "                                    |___/\\___\\___| |___/\\__\\___/_|  \\_, |" << endl;
	cout << "                                                                    |__/" << "\x1b[1;37m" << endl << endl << endl << endl;
}

//Prints ASCII Art title of Search Story in yellow
void printTitleSearchStory()
{
	cout << "\x1b[1;33m" << "                                     ___                  _      ___ _                " << endl;
	cout << "                                    / __| ___ __ _ _ _ __| |_   / __| |_ ___ _ _ _  _ " << endl;
	cout << "                                    \\__ \\/ -_) _` | '_/ _| ' \\  \\__ \\  _/ _ \\ '_| || |" << endl;
	cout << "                                    |___/\\___\\__,_|_| \\__|_||_| |___/\\__\\___/_|  \\_, |" << endl;
	cout << "                                                                                 |__/ " << "\x1b[1;37m" << endl << endl << endl << endl;
}

//Moves arrow on Sign in
void printActiveSignIn()
{
	activeSignIn();
	writeSeeStory();
	writeAddStory();
	writeSearch();
	writeHowItWorks();
	writeAboutUs();
	writeExit();
}

//Moves arrow on See Story
void printActiveSeeStory()
{
	writeSignIn();
	activeSeeStory();
	writeAddStory();
	writeSearch();
	writeHowItWorks();
	writeAboutUs();
	writeExit();
}

//Moves arrow on Add Story
void printActiveAddStory()
{
	writeSignIn();
	writeSeeStory();
	activeAddStory();
	writeSearch();
	writeHowItWorks();
	writeAboutUs();
	writeExit();
}

//Moves arrow on Search Story
void printActiveSearch()
{
	writeSignIn();
	writeSeeStory();
	writeAddStory();
	activeSearch();
	writeHowItWorks();
	writeAboutUs();
	writeExit();
}

//Moves arrow on How it works
void printActiveHowItWorks()
{
	writeSignIn();
	writeSeeStory();
	writeAddStory();
	writeSearch();
	activeHowItWorks();
	writeAboutUs();
	writeExit();
}

//Moves arrow on About us
void printActiveAboutUs()
{
	writeSignIn();
	writeSeeStory();
	writeAddStory();
	writeSearch();
	writeHowItWorks();
	activeAboutUs();
	writeExit();
}

//Moves arrow on Exit
void printActiveExit()
{
	writeSignIn();
	writeSeeStory();
	writeAddStory();
	writeSearch();
	writeHowItWorks();
	writeAboutUs();
	activeExit();
}