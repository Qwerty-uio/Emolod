#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;






int main() {
	srand(time(NULL));

	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string numbers="1234567890";
	string specialSymbols = "@$#_";
	string password = "";

	for (int i = 0; i < 16; i++)
	{
		password += letters[rand() % (letters.length() - 1)];
	}
	int countNumbers = 2 + rand() % 7;
	for (int i = 0; i < countNumbers; i++)
	{
		password[rand() % (password.length() - 1)]=numbers[rand() % (numbers.length() - 1)];
	}
	password[rand() % (password.length() - 1)] = specialSymbols[rand() % (specialSymbols.length() - 1)];

	ofstream save;
	save.open("passwords.txt");
	save << password;
	save.close();



	return 0;
}

