#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include "FrontEnd.h"
#include "BackEnd.h"
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

struct NODE
{
	string title;
	string year;
	int greyCode = 0;
	string place;
	string latitude;
	string longitude;
	string description;
	NODE* next = NULL;
};

struct FORM
{
	string username;
	string password;
	FORM* next = NULL;
};

void addNode(NODE* head, string nodeDataTitle, string nodeDataYear, int nodeDataGreyCode, string nodeDataPlace, string nodeDataLatitude, string nodeDataLongitude, string nodeDataDescription)
{
	NODE* newNode = new NODE;
	newNode->title = nodeDataTitle;
	newNode->year = nodeDataYear;
	newNode->greyCode = nodeDataGreyCode;
	newNode->place = nodeDataPlace;
	newNode->latitude = nodeDataLatitude;
	newNode->longitude = nodeDataLongitude;
	newNode->description = nodeDataDescription;
	newNode->next = NULL;
	NODE* temp = head;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = newNode;
			return;
		}
		temp = temp->next;
	}
}

void addUsers(FORM* head, string newusername, string newPassword)
{
	FORM* newNode = new FORM;
	newNode->username = newusername;
	newNode->password = newPassword;
	newNode->next = NULL;
	FORM* temp = head;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = newNode;
			return;
		}
		temp = temp->next;
	}
}

bool checkPasswordForSpecialCharecter(char password[], int n)
{
	bool aUpper = false, aLower = false, aDigit = false, aChar = false;
	char character[] = "!@#$%^&*()_+-=,.<>?/|:;";
	for (int i = 0; i < n; i++)
	{
		if (isupper(password[i]))
		{
			aUpper = true;
		}
		else if (islower(password[i]))
		{
			aLower = true;
		}
		else if (isdigit(password[i]))
		{
			aDigit = true;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < 23; j++)
				{
					if (character[j] == password[i])
					{
						aChar = true;
					}
				}
			}
		}
	}
	if (aUpper && aLower && aDigit && n >= 8 && n <= 20 && aChar)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkPassword(string str)
{
	char ch[20];
	for (int i = 0; i < str.size(); i++)
	{
		ch[i] = str.at(i);
	}
	if (checkPasswordForSpecialCharecter(ch, size(str)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void signUp()
{
	FORM* data = new FORM;
	string username, password;
	string sign;
	ofstream fileUser("UsersData.txt", ios_base::app);
	cout << "          ___ _             _   _      " << endl;
	cout << "         / __(_)__ _ _ _   | | | |_ __ " << endl;
	cout << "         \\__ \\ / _` | ' \\  | |_| | '_ \\" << endl;
	cout << "         |___/_\\__, |_||_|  \\___/| .__/" << endl;
	cout << "               |___/             |_|   " << endl << endl << endl;
	cout << "      Enter user name : ";
	getline(cin, username);
	cout << endl << endl << "\x1b[1;31m" "The password must contain uppercase, lowercase letters and special characters. It must be not less than 8 and not more than 20 characters" << "\x1b[1;37m";
	cout << endl << endl << "      Enter your password : ";
	getline(cin, password);
	if (checkPassword(password))
	{
		fileUser << username << " " << password << endl;
		fileUser.close();
		addUsers(data, username, password);
		system("CLS");
		cout << "Your account has been added correctly!" << endl << endl;
	}
	else
	{
		system("CLS");
		cout << "\x1b[1;31m" "The password must contain uppercase, lowercase letters and special characters. It must be not less than 8 and not more than 20 characters" << "\x1b[1;37m" << endl << endl;
		system("pause");
		system("read -n 1 -p \"Press any key to continue . . .\"");
		system("CLS");
		signUp();
	}
}

bool chechProfile()
{
	string sign;
	cout << "Do you have a profile? [Y/N]    ";
	getline(cin, sign);
	if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
	{
		system("CLS");
		return true;
	}
	return false;
}

bool searchUsers(FORM* head, string findUser, string findPassword)
{
	FORM* temp = head;
	while (temp != NULL)
	{
		if (temp->username == findUser && temp->password == findPassword)
		{
			system("CLS");
			cout << "You Sign In sucsesfully!";
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void signIn(bool* successfullySignIn)
{
	FORM* data = new FORM;
	ifstream output("UsersData.txt", ios_base::app);
	string username, password;
	int counter = 0;
	string sign;
	string str;
	int firstRow = 0;
	if (chechProfile())
	{


		while (!output.eof())
		{
			getline(output, str);
			counter = 0;
			username = password = "";
			for (size_t i = 0; i < str.size(); i++)
			{
				if (str[i] == ' ')
				{
					counter++;
					str.erase(i, 0);
				}
				else if (counter == 0)
				{
					username += str[i];
				}
				else if (counter == 1)
				{
					password += str[i];
				}
			}
			addUsers(data, username, password);
		}
		output.close();
		cout << "          ___ _             ___      " << endl;
		cout << "         / __(_)__ _ _ _   |_ _|_ _  " << endl;
		cout << "         \\__ \\ / _` | ' \\   | || ' \\ " << endl;
		cout << "         |___/_\\__, |_||_| |___|_||_|" << endl;
		cout << "               |___/     " << endl << endl << endl;
		cout << "      Enter user name : ";
		getline(cin, username);
		cout << endl << endl << "      Enter your password : ";
		getline(cin, password);
		if (searchUsers(data, username, password) == false)
		{
			system("CLS");
			cout << "Your username or password is invalid" << endl;
			cout << "Do you want to sign up[Y/N]";
			sign = "";
			getline(cin, sign);
			if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
			{
				system("CLS");
				signUp();
			}
		}
		else if (searchUsers(data, username, password) == true)
		{
			*successfullySignIn = true;
		}
	}
	else
	{
		system("CLS");
		signUp();
	}
}

int decToGrayCode(int number)
{
	return number ^ (number >> 1);
}

void deleteTtitle(NODE* head, string nodeDataTitle)
{
	NODE* newNode = new NODE;
	newNode->title = nodeDataTitle;
	head->next = NULL;
	head = newNode;
}

void deleteYear(NODE* head, string nodeDataYear)
{
	NODE* newNode = new NODE;
	newNode->year = nodeDataYear;
	head->next = NULL;
	head = newNode;
}

void deletePlace(NODE* head, string nodeDataPlace)
{
	NODE* newNode = new NODE;
	newNode->place = nodeDataPlace;
	head->next = NULL;
	head = newNode;
}

void deleteLatitude(NODE* head, string nodeDataLatitude)
{
	NODE* newNode = new NODE;
	newNode->latitude = nodeDataLatitude;
	head->next = NULL;
	head = newNode;
}

void deleteLongitude(NODE* head, string nodeDataLongitude)
{
	NODE* newNode = new NODE;
	newNode->longitude = nodeDataLongitude;
	head->next = NULL;
	head = newNode;
}

void deleteDescription(NODE* head, string nodeDataDescription)
{
	NODE* newNode = new NODE;
	newNode->description = nodeDataDescription;
	head->next = NULL;
	head = newNode;
}

void printList(NODE* head)
{
	NODE* temp = head->next;
	if (temp != NULL) {
		while (temp != NULL) {
			cout << endl << "Title : " << temp->title << endl;
			cout << "Year : " << temp->year << endl;
			cout << "Grey code of the year : " << temp->greyCode << endl;
			cout << "Place : " << temp->place << endl;
			cout << "Latitude : " << temp->latitude << endl;
			cout << "Longitude : " << temp->longitude << endl;
			cout << "Description : " << temp->description << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	else {
		cout << "The list is empty.\n";
	}
}

void check(bool dataAddCorrectly, string& data)
{
	string check = data;
	while (dataAddCorrectly == false)
	{
		if (check.find(',') != string::npos || check.find(':') != string::npos || check.find(';') != string::npos)
		{
			system("CLS");
			cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m";
			getline(cin, check);
			data = check;
		}
		else
		{
			dataAddCorrectly = true;
			system("CLS");
		}
	}
}

void checkDigit(bool dataAddCorrectly, string& data)
{
	string check = data;
	while (dataAddCorrectly == false)
	{
		if (check.find_first_not_of("0123456789.-") != string::npos)
		{
			system("CLS");
			cout << "\x1b[1;31m" << "  !!! USE ONLY DIGITS !!!  " << "\x1b[1;37m";
			getline(cin, check);
			data = check;
		}
		else
		{
			dataAddCorrectly = true;
			system("CLS");
		}
	}
}

void cinTitle(string* title, bool dataAddCorrectly)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter the title of the History event : ";
	getline(cin, *title);
	check(dataAddCorrectly, *title);
	dataAddCorrectly = false;
}

void cinYear(string* year, bool dataAddCorrectly)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "\x1b[1;31m" << "           !!! USE ONLY DIGITS !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter the year of the History event : ";
	getline(cin, *year);
	check(dataAddCorrectly, *year);
	dataAddCorrectly = false;
	checkDigit(dataAddCorrectly, *year);
	dataAddCorrectly = false;
}

void cinPlace(string* place, bool dataAddCorrectly)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter where exactly happened this event : ";
	getline(cin, *place);
	check(dataAddCorrectly, *place);
	dataAddCorrectly = false;
}

void cinLatitude(string* latitude, bool dataAddCorrectly)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "\x1b[1;31m" << "           !!! USE ONLY DIGITS !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter the latitude of this place : ";
	getline(cin, *latitude);
	check(dataAddCorrectly, *latitude);
	dataAddCorrectly = false;
	checkDigit(dataAddCorrectly, *latitude);
	dataAddCorrectly = false;
}

void cinLongitude(string* longitude, bool dataAddCorrectly)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "\x1b[1;31m" << "           !!! USE ONLY DIGITS !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter the longitude of this place : ";
	getline(cin, *longitude);
	check(dataAddCorrectly, *longitude);
	dataAddCorrectly = false;
	checkDigit(dataAddCorrectly, *longitude);
	dataAddCorrectly = false;
}

void cinDescription(string* description, bool dataAddCorrectly)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter what's happened in this place : ";
	getline(cin, *description);
	check(dataAddCorrectly, *description);
	dataAddCorrectly = false;
}

void inputDataInFile()
{
	NODE* data = new NODE;
	string title, year, place, latitude, longitude, description;
	bool dataAddCorrectly = false, truth = true, question;
	int greyCode, choice = 1;
	string sign;
	ofstream file("Data.csv", ios_base::app);
	while (truth)
	{
		switch (choice)
		{
		case 1:
			cinTitle(&title, dataAddCorrectly);
			cinYear(&year, dataAddCorrectly);
			greyCode = decToGrayCode(stoi(year));
			cinPlace(&place, dataAddCorrectly);
			cinLatitude(&latitude, dataAddCorrectly);
			cinLongitude(&longitude, dataAddCorrectly);
			cinDescription(&description, dataAddCorrectly);
			addNode(data, title, year, greyCode, place, latitude, longitude, description);
			system("CLS");
			printTitleAddStory();
			cout << "Do you want to see what you add? [Y/N]" << endl;
			getline(cin, sign);
			if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
			{
				printList(data);
				question = true;
				while (question)
				{
					cout << endl << "Do you want to change any data? [Y/N]" << endl;
					getline(cin, sign);
					if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
					{
						cout << endl << "Which data do you want to change?  [title/year/place/latitude/description] " << endl;
						getline(cin, sign);
						cout << endl;
						if (sign == "title" || sign == "Title")
						{
							cinTitle(&title, dataAddCorrectly);
							deleteTtitle(data, title);
						}
						else if (sign == "year" || sign == "Year")
						{
							cinYear(&year, dataAddCorrectly);
							greyCode = decToGrayCode(stoi(year));
							deleteYear(data, year);
						}
						else if (sign == "place" || sign == "Place")
						{
							cinPlace(&year, dataAddCorrectly);
							deletePlace(data, place);
						}
						else if (sign == "latitude" || sign == "Latitude")
						{
							cinLatitude(&latitude, dataAddCorrectly);
							deleteLatitude(data, latitude);
						}
						else if (sign == "longitude" || sign == "Longitude")
						{
							cinLongitude(&longitude, dataAddCorrectly);
							deleteLongitude(data, longitude);
						}
						else if (sign == "description" || sign == "Description")
						{
							cinDescription(&year, dataAddCorrectly);
							deleteDescription(data, description);
						}
						cout << "Do you want to see what you add? [Y/N]" << endl;
						getline(cin, sign);
						if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
						{
							addNode(data, title, year, greyCode, place, latitude, longitude, description);
							printList(data);
						}
					}
					else
					{
						question = false;
					}
				}
			}

			file << title << "," << year << "," << greyCode << "," << place << "," << latitude << "," << longitude << "," << description << endl;

			system("CLS");
			printTitleAddStory();
			cout << "Do you want to add another data? [Y/N]" << endl;
			getline(cin, sign);
			if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
			{
				system("CLS");
				choice = 1;
				break;
			}
			else
			{
				system("CLS");
				choice = 2;
				break;
			}
		case 2:
			cout << "The Data added correctly!" << endl << endl;
			file.close();
			truth = false;
			break;
		default:
			break;
		}
	}
}

bool searchTitle(NODE* head, string find)
{
	NODE* temp = head->next;
	while (temp != NULL)
	{
		if (temp->title == find)
		{
			cout << endl << "\x1b[1;33m" << "Title : " << temp->title << "\x1b[1;37m" << endl;
			cout << "Year : " << temp->year << endl;
			cout << "Grey code of the year : " << temp->greyCode << endl;
			cout << "Place : " << temp->place << endl;
			cout << "Latitude : " << temp->latitude << endl;
			cout << "Longitude : " << temp->longitude << endl;
			cout << "Description : " << temp->description << endl;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool searchYear(NODE* head, string find)
{
	NODE* temp = head;
	while (temp != NULL)
	{
		if (temp->year == find)
		{
			cout << endl << "Title : " << temp->title << endl;
			cout << "\x1b[1;33m" << "Year : " << temp->year << "\x1b[1;37m" << endl;
			cout << "Grey code of the year : " << temp->greyCode << endl;
			cout << "Place : " << temp->place << endl;
			cout << "Latitude : " << temp->latitude << endl;
			cout << "Longitude : " << temp->longitude << endl;
			cout << "Description : " << temp->description << endl;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool searchPlace(NODE* head, string find)
{
	NODE* temp = head->next;
	while (temp != NULL)
	{
		if (temp->place == find)
		{
			cout << endl << "Title : " << temp->title << endl;
			cout << "Year : " << temp->year << endl;
			cout << "Grey code of the year : " << temp->greyCode << endl;
			cout << "\x1b[1;33m" << "Place : " << temp->place << "\x1b[1;37m" << endl;
			cout << "Latitude : " << temp->latitude << endl;
			cout << "Longitude : " << temp->longitude << endl;
			cout << "Description : " << temp->description << endl;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void SearchData()
{
	NODE* data = new NODE;
	ifstream output("Data.csv", ios_base::app);
	string title, year, greyCode, place, latitude, longitude, description;
	int counter = 0;
	string sign, enter;
	string str;
	int firstRow = 0;
	if (!output.is_open())
	{
		cout << "Error opening file";
	}
	else
	{
		while (!output.eof())
		{
			getline(output, str);
			if (firstRow > 0 && str != "")
			{
				counter = 0;
				title = year = greyCode = place = latitude = longitude = description = "";
				for (size_t i = 0; i < str.size(); i++)
				{
					if (str[i] == ',' && counter < 6)
					{
						counter++;
						str.erase(i, 0);
					}
					else if (str[i] == '"')
					{
						str.erase(i, 0);
					}
					else if (counter == 0)
					{
						title += str[i];
					}
					else if (counter == 1)
					{
						year += str[i];
					}
					else if (counter == 2)
					{
						greyCode += str[i];
					}
					else if (counter == 3)
					{
						place += str[i];
					}
					else if (counter == 4)
					{
						latitude += str[i];
					}
					else if (counter == 5)
					{
						longitude += str[i];
					}
					else if (counter == 6)
					{
						description += str[i];
					}
				}
				addNode(data, title, year, stoi(greyCode), place, latitude, longitude, description);
			}
			firstRow++;
		}
		output.close();
	}
	cout << "By which data do you want to search? [title / year / place]" << endl;
	getline(cin, sign);
	if (sign == "title" || sign == "Title")
	{
		system("CLS");
		cout << "Enter what you want to search : ";
		getline(cin, enter);
		searchTitle(data, enter);
	}
	else if (sign == "year" || sign == "Year")
	{
		system("CLS");
		cout << "Enter what you want to search : ";
		getline(cin, enter);
		searchYear(data, enter);
	}
	else if (sign == "place" || sign == "Place")
	{
		system("CLS");
		cout << "Enter what you want to search : ";
		getline(cin, enter);
		searchPlace(data, enter);
	}
}

void sortList(NODE** head)
{
	NODE* temp = *head;
	string tempNode, sign;
	NODE* tempHead = new NODE;
	NODE* tempNext = NULL;
	head = &(*head)->next;
	int swapped;
	do
	{
		swapped = 0;
		tempHead = *head;
		while (tempHead->next != tempNext)
		{
			if (tempHead->year >= tempHead->next->year)
			{
				tempNode = tempHead->year;
				tempHead->year = tempHead->next->year;
				tempHead->next->year = tempNode;
				swapped = 1;
			}
			tempHead = tempHead->next;
		}
		tempNext = tempHead;

	} while (swapped);


}

void printSortData(NODE** head, NODE** find)
{
	NODE** temp = &(*head)->next;
	string findStr = "";
	while (*find)
	{
		findStr = (*find)->year;
		searchYear(*temp, findStr);
		find = &(*find)->next;
	}
}

void readDataFromFile()
{
	NODE* data = new NODE;
	NODE* temp = new NODE;
	ifstream output("Data.csv", ios_base::app);
	string title, year, greyCode, place, latitude, longitude, description;
	int counter = 0;
	string sign;
	string str;
	int firstRow = 0;
	if (!output.is_open())
	{
		cout << "Error opening file";
	}
	else
	{
		while (!output.eof())
		{
			getline(output, str);
			if (firstRow > 0 && str != "")
			{
				counter = 0;
				title = year = greyCode = place = latitude = longitude = description = "";
				for (size_t i = 0; i < str.size(); i++)
				{
					if (str[i] == ',' && counter < 6)
					{
						counter++;
						str.erase(i, 0);
					}
					else if (str[i] == '"')
					{
						str.erase(i, 0);
					}
					else if (counter == 0)
					{
						title += str[i];
					}
					else if (counter == 1)
					{
						year += str[i];
					}
					else if (counter == 2)
					{
						greyCode += str[i];
					}
					else if (counter == 3)
					{
						place += str[i];
					}
					else if (counter == 4)
					{
						latitude += str[i];
					}
					else if (counter == 5)
					{
						longitude += str[i];
					}
					else if (counter == 6)
					{
						description += str[i];
					}
				}
				addNode(data, title, year, stoi(greyCode), place, latitude, longitude, description);
				addNode(temp, title, year, stoi(greyCode), place, latitude, longitude, description);
			}
			firstRow++;
		}
		output.close();

	}
	printTitleSeeStory();
	cout << "Do you want to see all data? [Y/N]" << endl;
	getline(cin, sign);
	if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
	{
		printList(data);
		cout << "Do you want to sort data by year? [Y/N]" << endl;
		getline(cin, sign);
		if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
		{
			system("CLS");
			printTitleSeeStory();
			sortList(&data);
			printSortData(&temp, &data);
		}

	}
}

bool loopmovement(int choice)
{
	bool successfullySignIn = false;
	printActiveSignIn();
	choice = 1;
	while (true) {
		switch (_getch()) {
		case KEY_UP:
			if (choice == 2)
			{
				system("CLS");
				printActiveSignIn();
				choice = 1;
				break;
			}
			if (choice == 3)
			{
				system("CLS");
				printActiveSeeStory();
				choice = 2;
				break;
			}
			if (choice == 4)
			{
				system("CLS");
				printActiveAddStory();
				choice = 3;
				break;
			}
			if (choice == 5)
			{
				system("CLS");
				printActiveSearch();
				choice = 4;
				break;
			}
			if (choice == 6)
			{
				system("CLS");
				printActiveHowItWorks();
				choice = 5;
				break;
			}
			if (choice == 7)
			{
				system("CLS");
				printActiveAboutUs();
				choice = 6;
				break;
			}
			break;
		case KEY_DOWN:
			if (choice == 1)
			{
				system("CLS");
				printActiveSeeStory();
				choice = 2;
				break;
			}
			if (choice == 2)
			{
				system("CLS");
				printActiveAddStory();
				choice = 3;
				break;
			}
			if (choice == 3)
			{
				system("CLS");
				printActiveSearch();
				choice = 4;
				break;
			}
			if (choice == 4)
			{
				system("CLS");
				printActiveHowItWorks();
				choice = 5;
				break;
			}
			if (choice == 5)
			{
				system("CLS");
				printActiveAboutUs();
				choice = 6;
				break;
			}
			if (choice == 6)
			{
				system("CLS");
				printActiveExit();
				choice = 7;
				break;
			}
			break;
		case KEY_ENTER:
			if (choice == 1)
			{
				system("CLS");
				signIn(&successfullySignIn);
				writeBackWhite();
				choice = 8;
				break;
			}
			if (choice == 2 && successfullySignIn == true)
			{
				system("CLS");
				readDataFromFile();
				choice = 8;
				writeBackWhite();
				break;
			}
			if (choice == 3 && successfullySignIn == true)
			{
				system("CLS");
				inputDataInFile();
				choice = 8;
				writeBackWhite();
				break;
			}
			if (choice == 4 && successfullySignIn == true)
			{
				system("CLS");
				SearchData();
				choice = 8;
				writeBackWhite();
				break;
			}
			if (choice == 5 && successfullySignIn == true)
			{
				system("CLS");
				printTitleHowItWorks();
				printHowItWorks();
				choice = 8;
				writeBackWhite();
				break;
			}
			if (choice == 6 && successfullySignIn == true)
			{
				system("CLS");
				printAboutUs();
				writeBackWhite();
				choice = 8;
				break;
			}
			if (choice == 7)
			{
				return 0;
				break;
			}
			if (choice == 8)
			{
				system("CLS");
				printActiveSignIn();
				choice = 1;
				break;
			}
			break;
		default:
			break;
		}
	}
}