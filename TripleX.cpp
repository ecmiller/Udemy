#include <iostream>

void PrintIntroduction(int Difficulty)
{
    // Explain the game scenario to the player
    std::cout << "\nA briefcase with a tier-" << Difficulty << " combination lock sits across from you. \n";
    std::cout << "Guess the three numbers of the combination to open it.\n";
}

void PrintHint(int CodeSum, int CodeProduct)
{
    std::cout << "\nHere are a couple of hints to get you started: \n";

    std::cout << "- The sum of the three numbers is " << CodeSum << ".\n";
    std::cout << "- The product of the three numbers is " << CodeProduct << ".\n";
}

void RandomizeCodes(int Codes[], int NumberOfCodes, int Difficulty)
{
    for(int i = 0; i < NumberOfCodes; i++)
    {
        std::srand(std::time(NULL) + i);
        Codes[i] = (int) rand() % Difficulty + Difficulty; 
    }
}

bool PlayGame(int Difficulty)
{
    int Codes[] = {1, 1, 1};
    RandomizeCodes(Codes, 3, Difficulty);
    
    int CodeA = Codes[0];
    int CodeB = Codes[1];
    int CodeC = Codes[2];

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //Explain the game scenario to the player
    PrintIntroduction(Difficulty);

    // Give the player a hint
    PrintHint(CodeSum, CodeProduct);

    int GuessA, GuessB, GuessC;

    // Take the player's guess(es)
    std::cout << "\nTry to guess the combination by entering three integers, separated by a space. \n";
    std:: cout << "(Example: 3 4 5) \n \n";

    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "\nYou guessed: " << GuessA << " " << GuessB << " " << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Evaluate the player's guess
    if((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
    {
        std::cout << "Your guess was correct.\n";
        return true;
    }

    else
    {
        std::cout << "\nIncorrect. A different briefcase, of equal difficulty, is presnted. \nTry again. \n\n";
        return false;
    }
}

bool PlayAgain()
{
    char PlayerChoice;

    std::cout << "Would you like to play again? [Y/N] \n";
    std::cin >> PlayerChoice;
    
    if(PlayerChoice == 'y' || PlayerChoice == 'Y')
    {
        return true;
    }

    else 
    {
        return false;
    }
}

int main()
{
    //bool bLevelComplete = true;
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    
    while(LevelDifficulty <= MaxDifficulty) // Loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any erros
        std::cin.ignore(); // Discards the buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty;

            if(LevelDifficulty == MaxDifficulty)
            {
                std::cout << "\nThis is as tough as it gets.\n";
            }
        }
    }

    std::cout << "\nYou completed the game. Congratulations! \nThank you for playing! \n\n";

    return 0;
}
