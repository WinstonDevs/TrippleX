// TrippleX.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 2/28/2022
// Winston To
// @brief A simple number puzzle game that ramps up in difficulity. Contains 10 Levels.

#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    // Print welcome message to terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure sever room..\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

// Game Loop
bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The code multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    // Process inputs
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
    return false;
}

int main()
{
    srand(time(NULL)); //new seed to randomize game
    int LevelDifficulty = 1;
    int const MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty) { //loops the game until all levels are completed
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete) {
            ++LevelDifficulty; // increase level difficulty
        }
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***" << std::endl;
    return 0;
}
