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
FText getValidGuess();
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
	for (int32 i = 0; i < maxTries; i++) { // TODO change for to while
		FText Guess = getValidGuess(); // TODO make loop checking validity

		// submit valid guess to game and receive count
		FBullCowCount BullCowCount =  BCGame.SubmitValidGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;

		// std::cout << "Your guess was: " + Guess << std::endl;
	}
	// TODO summarize game
}

// loop continually until user gives a vaild guess
FText getValidGuess() {
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get guess input
		int32 currentTry = BCGame.getCurrentTry();
		std::cout << "Try " << currentTry << ". Enter your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.checkGuessValidity(Guess);

		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lowercase word.\n";
			break;
		default:
			// assume guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
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
