// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ConsoleApplication1.h"

using FText = std::string;
using int32 = int;
Game BCGame;

FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " Enter your guess" << std::endl;
		getline(std::cin, Guess);

		Status = BCGame.CheckguessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PrintGameSummary() {
	if (BCGame.isGameWon()) {
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else {
		std::cout << "Better luck next time\n";
	}
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	do {
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
	} while (!BCGame.isGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries());
	PrintGameSummary();
	return;
}

void PrintIntro() {
	std::cout << "\n\nWelcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word?\n";
	FText response = "";
	std::getline(std::cin, response);
	return (response[0] == 'y') || (response[0] == 'Y');
}

int main()
{
	PrintIntro();
	do {
		PlayGame();
		AskToPlayAgain();
	} while (AskToPlayAgain());
	return 0;
}