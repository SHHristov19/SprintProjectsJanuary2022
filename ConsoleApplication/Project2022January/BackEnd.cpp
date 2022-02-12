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

//Inserts new node in linked list
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

//Adds new node in linked list
void addUsers(FORM* head, string newUsername, string newPassword)
{
	FORM* newNode = new FORM;
	newNode->username = newUsername;
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

//This function checks if the password contains the followin special characters
bool checkPasswordForSpecialCharacter(char password[], int n)
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

//This function converts the password from type string to type char and checks with checkPasswordForSpecialCharacter()
bool checkPassword(string str)
{
	char ch[20];
	for (int i = 0; i < str.size(); i++)
	{
		ch[i] = str.at(i);
	}
	if (checkPasswordForSpecialCharacter(ch, size(str)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//This function signs the user up and adds data to UsersData.txt
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
		system("CLS");
		signUp();
	}
}

//This function checks if the user has a profile
bool checkProfile()
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

//This function checks if the username and password match with the linked list
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

//This function checks if the username and password are contained in UsersData.txt
void signIn(bool* successfullySignIn)
{
	FORM* data = new FORM;
	ifstream output("UsersData.txt", ios_base::app);
	string username, password;
	int counter = 0;
	string sign;
	string str;
	int firstRow = 0;
	if (checkProfile())
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

//This function converts the year from type int to gray code
int decToGrayCode(int number)
{
	return number ^ (number >> 1);
}

//This function deletes title node data from linked list
void deleteTitle(NODE* head, string nodeDataTitle)
{
	NODE* newNode = new NODE;
	newNode->title = nodeDataTitle;
	head->next = NULL;
	head = newNode;
}

//This function deletes year node data from linked list
void deleteYear(NODE* head, string nodeDataYear)
{
	NODE* newNode = new NODE;
	newNode->year = nodeDataYear;
	head->next = NULL;
	head = newNode;
}

//This function deletes place node data from linked list
void deletePlace(NODE* head, string nodeDataPlace)
{
	NODE* newNode = new NODE;
	newNode->place = nodeDataPlace;
	head->next = NULL;
	head = newNode;
}

//This function deletes latitude node data from linked list
void deleteLatitude(NODE* head, string nodeDataLatitude)
{
	NODE* newNode = new NODE;
	newNode->latitude = nodeDataLatitude;
	head->next = NULL;
	head = newNode;
}

//This function deletes longitude node data from linked list
void deleteLongitude(NODE* head, string nodeDataLongitude)
{
	NODE* newNode = new NODE;
	newNode->longitude = nodeDataLongitude;
	head->next = NULL;
	head = newNode;
}

//This function deletes description node data from linked list
void deleteDescription(NODE* head, string nodeDataDescription)
{
	NODE* newNode = new NODE;
	newNode->description = nodeDataDescription;
	head->next = NULL;
	head = newNode;
}

//This function prints the entier linked list
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

//Checks if data contains comma,colon or semicolon
bool check(string& data)
{
	string sign = data;
	if (sign.find(',') != string::npos || sign.find(':') != string::npos || sign.find(';') != string::npos)
	{
		system("CLS");
		cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m";
		system("pause");
		system("CLS");
		return false;
	}
	else
	{
		system("CLS");
		return true;
	}
}

//Checks if year contains characters other than digits
bool checkDigit(string& data)
{
	string sign = data;
	if (sign.find_first_not_of("0123456789.-") != string::npos)
	{
		system("CLS");
		cout << "\x1b[1;31m" << "  !!! USE ONLY DIGITS !!!  " << "\x1b[1;37m";
		system("pause");
		system("CLS");
		return false;
	}
	else
	{
		system("CLS");
		return true;
	}
}

//Checks if year node data exists in Data.csv file
bool searchExistingYear(string* find)
{
	NODE* data = new NODE;
	ifstream output("Data.csv", ios_base::app);
	string title, year, greyCode, place, latitude, longitude, description;
	int counter = 0;
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
	while (data != NULL)
	{
		if (*find == data->year)
		{
			return true;
		}
		data = data->next;
	}
	return false;
}

//This function inputs title node data by the user
void cinTitle(string* title)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter the title of the History event : ";
	getline(cin, *title);
	if (check(*title) == false)
	{
		cinTitle(title);
	}
}

//This function inputs year node data by the user
void cinYear(string* year)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "\x1b[1;31m" << "           !!! USE ONLY DIGITS !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter the year of the History event : ";
	getline(cin, *year);
	if (check(*year) == false)
	{
		cinYear(year);
	}
	if (checkDigit(*year) == false)
	{
		cinYear(year);
	}
	if (searchExistingYear(year))
	{
		cout << "This year exists, please type new year!" << endl << endl;
		system("pause");
		system("CLS");
		cinYear(year);
	}
}

//This function inputs place node data by the user
void cinPlace(string* place)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter where exactly happened this event : ";
	getline(cin, *place);
	if (check(*place) == false)
	{
		cinPlace(place);
	}
}

//This function inputs latitude node data by the user
void cinLatitude(string* latitude)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "\x1b[1;31m" << "     !!! USE ONLY DIGITS, POINT OR MINUS !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter the latitude of this place : ";
	getline(cin, *latitude);
	if (check(*latitude) == false)
	{
		cinLatitude(latitude);
	}
	if (checkDigit(*latitude) == false)
	{
		cinLatitude(latitude);
	}
}

//This function inputs longitude node data by the user
void cinLongitude(string* longitude)
{
	printTitleAddStory();
	cout << "\x1b[1;31m" << "  !!! DO NOT USE A COMMA, COLON OR SEMICOLON !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "\x1b[1;31m" << "     !!! USE ONLY DIGITS, POINT OR MINUS !!!  " << "\x1b[1;37m" << endl << endl;
	cout << "Enter the longitude of this place : ";
	getline(cin, *longitude);
	if (check(*longitude) == false)
	{
		cinLongitude(longitude);
	}
	if (checkDigit(*longitude) == false)
	{
		cinLongitude(longitude);
	}
}

//This function inputs description node data by the user
void cinDescription(string* description)
{
	printTitleAddStory();
	cout << "Enter what's happened in this place : ";
	getline(cin, *description);
}

//Inputs linked list in Data.csv
void inputDataInFile()
{
	NODE* data = new NODE;
	string title, year, place, latitude, longitude, description;
	bool truth = true, question;
	int greyCode, choice = 1;
	string sign;
	ofstream file("Data.csv", ios_base::app);
	while (truth)
	{
		switch (choice)
		{
		case 1:
			cinTitle(&title);
			cinYear(&year);
			greyCode = decToGrayCode(stoi(year));
			cinPlace(&place);
			cinLatitude(&latitude);
			cinLongitude(&longitude);
			cinDescription(&description);
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
						cout << endl << "Which data do you want to change?  [title/year/place/latitude/longitude/description] " << endl;
						getline(cin, sign);
						cout << endl;
						system("CLS");
						if (sign == "title" || sign == "Title")
						{
							cinTitle(&title);
							deleteTitle(data, title);
						}
						else if (sign == "year" || sign == "Year")
						{
							cinYear(&year);
							greyCode = decToGrayCode(stoi(year));
							deleteYear(data, year);
						}
						else if (sign == "place" || sign == "Place")
						{
							cinPlace(&place);
							deletePlace(data, place);
						}
						else if (sign == "latitude" || sign == "Latitude")
						{
							cinLatitude(&latitude);
							deleteLatitude(data, latitude);
						}
						else if (sign == "longitude" || sign == "Longitude")
						{
							cinLongitude(&longitude);
							deleteLongitude(data, longitude);
						}
						else if (sign == "description" || sign == "Description")
						{
							cinDescription(&description);
							deleteDescription(data, description);
						}
						printTitleAddStory();
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

			file << title << "," << year << "," << greyCode << "," << place << "," << latitude << "," << longitude << ",\"" << description << "\"" << endl;

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

//Searches for title data in the linked list
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

//Searches for year data in the linked list
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

//Searches for grey code data in the linked list
bool searchGreyCode(NODE* head, int find)
{
	NODE* temp = head;
	while (temp != NULL)
	{
		if (temp->greyCode == find)
		{
			cout << endl << "Title : " << temp->title << endl;
			cout << "Year : " << temp->year << endl;
			cout << "\x1b[1;33m" << "Grey code of the year : " << temp->greyCode << "\x1b[1;37m" << endl;
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

//Searches for place data in the linked list
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

//This function searches user inputted data in Data.csv
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
	printTitleSearchStory();
	cout << "By which data do you want to search? [title / year / place]" << endl;
	getline(cin, sign);
	if (sign == "title" || sign == "Title")
	{
		system("CLS");
		printTitleSearchStory();
		cout << "Enter what you want to search : ";
		getline(cin, enter);
		searchTitle(data, enter);
	}
	else if (sign == "year" || sign == "Year")
	{
		system("CLS");
		printTitleSearchStory();
		cout << "Enter what you want to search : ";
		getline(cin, enter);
		searchYear(data, enter);
	}
	else if (sign == "place" || sign == "Place")
	{
		system("CLS");
		printTitleSearchStory();
		cout << "Enter what you want to search : ";
		getline(cin, enter);
		searchPlace(data, enter);
	}
}

//Sorts linked list nodes by year
void sortListByYear(NODE** head)
{
	NODE* temp = *head;
	string tempNode;
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

//Sorts linked list nodes by grey code
void sortListByGreyCode(NODE** head)
{
	NODE* temp = *head;
	int tempNode;
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
			if (tempHead->greyCode >= tempHead->next->greyCode)
			{
				tempNode = tempHead->greyCode;
				tempHead->greyCode = tempHead->next->greyCode;
				tempHead->next->greyCode = tempNode;
				swapped = 1;
			}
			tempHead = tempHead->next;
		}
		tempNext = tempHead;

	} while (swapped);
}

//Prints sorted data by year
void printSortDataByYear(NODE** head, NODE** find)
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

//Prints sorted data by grey code
void printSortDataGreyCode(NODE** head, NODE** find)
{
	NODE** temp = &(*head)->next;
	int findStr = 0;
	while (*find)
	{
		findStr = (*find)->greyCode;
		searchGreyCode(*temp, findStr);
		find = &(*find)->next;
	}
}

//Converts all data from Data.csv file into a linked list and prints it
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
		cout << "Do you want to sort data? [Y/N]" << endl;
		getline(cin, sign);
		if (sign == "Y" || sign == "Yes" || sign == "y" || sign == "yes")
		{
			cout << "By what do you want to sort? [year/greyCode]" << endl;
			getline(cin, sign);
			system("CLS");
			printTitleSeeStory();
			if (sign == "year" || sign == "Year")
			{
				sortListByYear(&data);
				printSortDataByYear(&temp, &data);
			}
			else if (sign == "greyCode" || sign == "grey code")
			{
				sortListByGreyCode(&data);
				printSortDataGreyCode(&temp, &data);
			}
		}

	}
}

//This function prints the menu and implements movement in the menu
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