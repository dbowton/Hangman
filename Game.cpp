#include "Game.h"

int Game::Play(bool showAnswer)
{
	view = View();

	view.Clear();
	chosenWord = view.GetWord(filepath);

	workingWord.resize(chosenWord.size(), '_');

	while (true)
	{
		if (CheckWin())
		{
			view.PrintLine("Winner");
			return 1;
		}

		if (lives <= 0)
		{
			view.PrintLine("Loser - Word Was: " + chosenWord);
			return -1;
		}

		view.Clear();

		if (showAnswer)
			view.PrintLine("answer: " + chosenWord);

		view.PrintBoard(lives);
		view.PrintWorking(workingWord);
		view.PrintGuessed(guessedLetters);

		if (!CheckWord(view.GetUserChar())) lives--;

		view.Clear();

		if (showAnswer)
			view.PrintLine("answer: " + chosenWord);

		view.PrintBoard(lives);
		view.PrintWorking(workingWord);
		view.PrintGuessed(guessedLetters);
	}
}

bool Game::CheckWin()
{
	for (int i = 0; i < chosenWord.size(); i++)
		if (workingWord[i] != chosenWord[i]) 
			return false;

	return true;
}

bool Game::CheckWord(char guessedLetter)
{
	for (auto iter = guessedLetters.begin(); iter != guessedLetters.end(); iter++)
		if (*iter == guessedLetter) 
			return true;

	bool containsLetter = false;

	for (int i = 0; i < chosenWord.size(); i++)
		if (chosenWord[i] == guessedLetter)
		{
			workingWord[i] = guessedLetter;
			containsLetter = true;
		}

	if (!containsLetter)
		guessedLetters.push_back(guessedLetter);

	return containsLetter;
}
