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

EWordStatus FBullCowGame::checkGuessValidity(FString) const {
	return EWordStatus::OK;
}
// receives a VALID guess,increments turn,a nd returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// increment the turn number
	myCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	
	// loop through all letters in the guess
	int32 hiddenWordLength = myHiddenWord.length();
	for (int32 i = 0; i < hiddenWordLength; i++) {
		// compare letters against the hidden word
		for (int32 j = 0; j < hiddenWordLength; j++) {
			// if they match
			if (Guess[j] == myHiddenWord[i]) {
				// if they are in the same place
				if (i == j) {
					// increment bulls
					BullCowCount.Bulls++;
				}
				else {
					// else
						// increment cows
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
