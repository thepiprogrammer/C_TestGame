#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon;}

bool FBullCowGame::isIsogram(FString Word) const {
	// treat 0 or 1 letter words as isogram
	if (Word.length() <= 1) {
		return true;
	}
	TMap<char, bool> LetterSeen; // setup map
	for (auto Letter : Word) { // loop through all letters in the word
		Letter = tolower(Letter);
		if (LetterSeen.count(Letter)>0) { // if the letter is in the map
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planet";

	myMaxTries = MAX_TRIES;
	myCurrentTry = 1;
	myHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString Guess) const {
	if (!isIsogram(Guess)) // if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram; // TODO write function Not_Isogrsm
	}
	else if (false) // if the guess isnt all lowercase
	{
		return EGuessStatus::Not_Lowercase; // TODO write function Not_Lowercase
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
	FBullCowCount BullCowCount; // setup a return variable
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
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	} else {
		bGameIsWon = false;
	}
	return BullCowCount;
}
