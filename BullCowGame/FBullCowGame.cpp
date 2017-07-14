#include "FBullCowGame.h"

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planet";

	myMaxTries = MAX_TRIES;
	myCurrentTry = 1;
	myHiddenWord = HIDDEN_WORD;
	return;
}

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::getMaxTries() const { return myMaxTries;}
int32 FBullCowGame::getCurrentTry() const {	return myCurrentTry;}
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length();}

bool FBullCowGame::isGameWon() const {
	return false;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString Guess) const {
	if (false) // if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isnt all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	} 
	else if (getHiddenWordLength() != Guess.length()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}
// receives a VALID guess,increments turn,a nd returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	myCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	int32 WordLength = myHiddenWord.length(); // assuming same length as guess

	// loop through all letters in the hidden word
	for (int32 i = 0; i < WordLength; i++) {
		// compare letters against the guess
		for (int32 j = 0; j < WordLength; j++) {
			// if they match
			if (Guess[j] == myHiddenWord[i]) { // if they are in the same place
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
