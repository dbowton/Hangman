#include "Game.h"
#include "View.h"

int main()
{
	list<string> acceptable{ "y", "yes", "yea", "yeah", "again", "play", "sure"};
	list<string> unacceptable{ "n", "no", "quit", "end", "stop", "nah", "na"};

	do 
	{
		Game* game = new Game();
		game->Play();
		delete game;

	} while (View().GetUserBooleanOption("Play Again? ", acceptable, unacceptable));
}
