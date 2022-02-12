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

void addNode(NODE* head, string nodeDataTitle, string nodeDataYear, int nodeDataGreyCode, string nodeDataPlace, string nodeDataLatitude, string nodeDataLongitude, string nodeDataDescription);

void addUsers(FORM* head, string newUsername, string newPassword);

bool checkPasswordForSpecialCharecter(char password[], int n);

bool checkPassword(string str);

void signUp();

bool checkProfile();

bool searchUsers(FORM* head, string findUser, string findPassword);

void signIn(bool* successfullySignIn);

int decToGrayCode(int number);

void deleteTtitle(NODE* head, string nodeDataTitle);

void deleteYear(NODE* head, string nodeDataYear);

void deletePlace(NODE* head, string nodeDataPlace);

void deleteLatitude(NODE* head, string nodeDataLatitude);

void deleteLongitude(NODE* head, string nodeDataLongitude);

void deleteDescription(NODE* head, string nodeDataDescription);

void printList(NODE* head);

bool check(string& data);

bool checkDigit(string& data);

bool searchExistingYear(string* find);

void cinTitle(string* title);

void cinYear(string* year);

void cinPlace(string* place);

void cinLatitude(string* latitude);

void cinLongitude(string* longitude);

void cinDescription(string* description);

void inputDataInFile();

bool searchTitle(NODE* head, string find);

bool searchYear(NODE* head, string find);

bool searchPlace(NODE* head, string find);

void SearchData();

void sortList(NODE** head);

void printSortData(NODE** head, NODE** find);

void readDataFromFile();

bool loopmovement(int choice);