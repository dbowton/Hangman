#include "View.h"

void View::Print(string text)
{
	cout << text;
}

void View::PrintLine(string text)
{
	Print(text);
	cout << endl;
}

void View::PrintBoard(int lives)
{
	cout << "   ______ " << endl;
	cout << "   |    | " << endl;

	if (lives < 6)
		cout << "   |    O " << endl;
	else
		cout << "   |        " << endl;

	if (lives >= 5)
		cout << "   |       " << endl;

	if (lives == 4)
		cout << "   |    | " << endl;

	if (lives == 3)
		cout << "   |   /| " << endl;

	if (lives <= 2)
		cout << "   |   /|\\ " << endl;

	if (lives >= 2)
		cout << "   |" << endl;

	if (lives == 1)
		cout << "   |   /   " << endl;

	if (lives <= 0)
		cout << "   |   / \\   " << endl;

	cout << " __|_______" << endl << endl;
}

void View::PrintGuessed(string guessedLetters)
{
	cout << "Guessed: ";

	for (auto iter = guessedLetters.begin(); iter != guessedLetters.end(); iter++)
		cout << *iter << " ";

	cout << endl;
}

void View::PrintWorking(string workingWord)
{
	for (auto iter = workingWord.begin(); iter != workingWord.end(); iter++)
		cout << *iter << " ";

	cout << endl;
}

char View::GetUserChar(string prompt)
{
	string userInput;

	while(true)
	{
		userInput = GetUserInput(prompt);

		if (userInput.size() == 1)
			break;

		PrintLine("Invalid Input ( " + userInput + " )");
	}

	return userInput[0];
}

string View::GetUserInput(string prompt)
{
	cout << prompt;

	string userInput;
	cin >> userInput;

	return ToLower(userInput);
}

bool View::GetUserBooleanOption(string prompt, list<string> trueConditions, list<string> falseConditions)
{
	while (true)
	{
		string userInput = GetUserInput(prompt);

		for (auto iter = trueConditions.begin(); iter != trueConditions.end(); iter++)
			if (ToLower(*iter) == ToLower(userInput)) return true;

		for (auto iter = falseConditions.begin(); iter != falseConditions.end(); iter++)
			if (ToLower(*iter) == ToLower(userInput)) return false;

		PrintLine("Unknown Input ( " + userInput + " )");
	}
}

string View::ToLower(string word)
{
	string workingWord = word;

	std::for_each(workingWord.begin(), workingWord.end(), [](char& c)
		{
			c = ::tolower(c);
		});

	return workingWord;
}

string View::GetWord(string filepath)
{
	list<string> words;
	string chosenWord;

	ifstream input(filepath);

	while (!input.eof())
	{
		string word;
		input >> word;

		words.push_back(word);
	}

	srand(time(NULL));
	int chosen = rand() % words.size();

	for (auto iter = words.begin(); iter != words.end() && chosen >= 0; iter++, chosen--)
		chosenWord = *iter;

	return chosenWord;
}