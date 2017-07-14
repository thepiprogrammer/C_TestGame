/** 
This is console executable, which uses BullCow class.
This acts as the viwo in a MVC pattern, and is responsible for all user interaction. 
For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//using namespace std;

using FText = std::string;
using int32 = int;

void printIntro();
void PlayGame();
FText getGuess();
bool askToPlayAgain();

FBullCowGame BCGame; // instantiate a game --> here as global instance

//entrypoint for app
int main() {
	do {
		printIntro();
		PlayGame();
	} while (askToPlayAgain());
	return 0; // exit
}

void printIntro() {
	//constant expression

	// introduce the game
	std::cout << "Can you now guess a " << BCGame.getHiddenWordLength() << " letter word I have?\n";
	return;
}

void PlayGame()
{
	int32 maxTries = BCGame.getMaxTries();

	// get input also loop
	for (int32 i = 0; i < maxTries; i++) {
		FText Guess = getGuess(); // TODO make loop checking validity

		// submit valid guess to game and receive count
		FBullCowCount BullCowCount =  BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		// std::cout << "Your guess was: " + Guess << std::endl;
	}

	// TODO summarize game
}

FText getGuess() {
	//get input

	int32 currentTry = BCGame.getCurrentTry();

	FText str = "";
	std::cout << "Try " << currentTry << ". Enter your guess: ";
	getline(std::cin, str);
	return str;
}

bool askToPlayAgain() {
	std::cout << "Do you want to play again? ";
	FText response = "";
	getline(std::cin, response);

	if (response[0] == 'y' || response[0] == 'Y') {
		return true;
	} else {
		return false;
	}
}
