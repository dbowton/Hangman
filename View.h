#pragma once
#include <iostream>
#include <fstream>

#include <string>
#include <list>
#include <algorithm>

using namespace std;

class View
{
public:
	void Clear() { system("cls"); }

	void Print(string text);
	void PrintLine(string text = "");

	void PrintWorking(string workingWord);
	void PrintGuessed(string guessedLetters);
	void PrintBoard(int lives);

	string GetWord(string filepath);

	char GetUserChar(string prompt = "");
	string GetUserInput(string prompt = "");
	bool GetUserBooleanOption(string prompt, list<string> trueConditions, list<string> falseConditions);

	string ToLower(string word);
};
