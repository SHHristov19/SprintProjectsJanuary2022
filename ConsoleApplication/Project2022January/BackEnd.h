#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include "FrontEnd.h"
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

struct NODE;

struct FORM;

//Inserts new node in linked list
void addNode(NODE* head, string nodeDataTitle, string nodeDataYear, int nodeDataGreyCode, string nodeDataPlace, string nodeDataLatitude, string nodeDataLongitude, string nodeDataDescription);

//Adds new node in linked list
void addUsers(FORM* head, string newUsername, string newPassword);

//This function checks if the password contains the followin special characters
bool checkPasswordForSpecialCharacter(char password[], int n);

//This function converts the password from type string to type char and checks with checkPasswordForSpecialCharacter()
bool checkPassword(string str);

//This function signs the user up and adds data to UsersData.txt
void signUp();

//This function checks if the user has a profile
bool checkProfile();

//This function checks if the username and password match with the linked list
bool searchUsers(FORM* head, string findUser, string findPassword);

//This function checks if the username and password are contained in UsersData.txt
void signIn(bool* successfullySignIn);

//This function converts the year from type int to gray code
int decToGrayCode(int number);

//This function deletes title node data from linked list
void deleteTitle(NODE* head, string nodeDataTitle);

//This function deletes year node data from linked list
void deleteYear(NODE* head, string nodeDataYear);

//This function deletes place node data from linked list
void deletePlace(NODE* head, string nodeDataPlace);

//This function deletes latitude node data from linked list
void deleteLatitude(NODE* head, string nodeDataLatitude);

//This function deletes longitude node data from linked list
void deleteLongitude(NODE* head, string nodeDataLongitude);

//This function deletes description node data from linked list
void deleteDescription(NODE* head, string nodeDataDescription);

//This function prints the entier linked list
void printList(NODE* head);

//Checks if data contains comma,colon or semicolon
bool check(string& data);

//Checks if year contains characters other than digits
bool checkDigit(string& data);

//Checks if year node data exists in Data.csv file
bool searchExistingYear(string* find);

//This function inputs title node data by the user
void cinTitle(string* title);

//This function inputs year node data by the user
void cinYear(string* year);

//This function inputs place node data by the user
void cinPlace(string* place);

//This function inputs latitude node data by the user
void cinLatitude(string* latitude);

//This function inputs longitude node data by the user
void cinLongitude(string* longitude);

//This function inputs description node data by the user
void cinDescription(string* description);

//Inputs linked list in Data.csv
void inputDataInFile();

//Searches for title data in the linked list
bool searchTitle(NODE* head, string find);

//Searches for year data in the linked list
bool searchYear(NODE* head, string find);

//Searches for place data in the linked list
bool searchPlace(NODE* head, string find);

//This function searches user inputted data in Data.csv
void SearchData(); 

//Sorts linked list nodes
void sortList(NODE** head);

//Prints sorted data
void printSortData(NODE** head, NODE** find);

//Converts all data from Data.csv file into a linked list and prints it
void readDataFromFile();

//This function prints the menu and implements movement in the menu
bool loopmovement(int choice);
