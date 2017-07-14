#pragma once
#include <string>

// never use "using namespace" in header file

using FString = std::string;
using int32 = int;

// all integers initialized to zero
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public: 
	FBullCowGame(); //constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;

	bool isGameWon() const;
	EGuessStatus checkGuessValidity(FString) const; // TODO more richer return value.

	void Reset(); // TODO make a more rich return value.
	FBullCowCount SubmitGuess(FString);

	// SomeNewType SubmitValidGuess

// ^^^ ignore bottom, focus above ^^^
private:
	// initialization @ constructor
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
};
