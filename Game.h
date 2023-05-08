#pragma once
#include "View.h"

#include <string>

using namespace std;

class Game
{
private:
	View view;

	string chosenWord;
	string workingWord;
	string guessedLetters;
	
	string filepath = "words.txt";

	int lives = 6;

public:
	int Play(bool showAnswer = false);

private:
	bool CheckWin();
	bool CheckWord(char guessedLetter);
};
