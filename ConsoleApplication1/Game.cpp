#include "ConsoleApplication1.h"
#include <string>
#include <iostream>

using int32 = int;

Game::Game() {
	Reset();
}
void Game::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	bGameIsWon = false;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	//std::cout << MyHiddenWord;
	return;
}

int32 Game::GetMaxTries() const
{
	return MyMaxTries;
}

int32 Game::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 Game::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}


bool Game::isGameWon() const
{
	return bGameIsWon;
}

FBullCowCount Game::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();
	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < WordLength; j++) {
			if (Guess[i] == MyHiddenWord[j]) {
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
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

EGuessStatus Game::CheckguessValidity(FString Guess) const
{
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}