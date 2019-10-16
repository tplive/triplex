#include <iostream>
#include <ctime>

void PrintIntroduction(int Diff)
{
    std::cout << "\n";
    std::cout << " _______   _       _     __   __\n";
    std::cout << "|__   __| (_)     | |    \\ \\ / /\n";
    std::cout << "   | |_ __ _ _ __ | | ___ \\ V / \n";
    std::cout << "   | | '__| | '_ \\| |/ _ \\ > <  \n";
    std::cout << "   | | |  | | |_) | |  __// . \\ \n";
    std::cout << "   |_|_|  |_| .__/|_|\\___/_/ \\_\\ \n";
    std::cout << "            | | \n";
    std::cout << "            |_| \n";
    std::cout << "\n";

    std::cout << "You are a secret agent breaking into a " << Diff;
    std::cout << " server room...\nYou must do the right thing here...\n\n";

}

bool PlayGame(int LevelDifficulty) 
{

    PrintIntroduction(LevelDifficulty);

    // declarations
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    // calculations
    const int SumOfNums = CodeA + CodeB + CodeC;
    const int ProdOfNums = CodeA * CodeB * CodeC;
    
    // Display logic
    std::cout << "+ The code consists of three numbers\n";
    std::cout << "+ The numbers add up to: " << SumOfNums << "\n";
    std::cout << "+ The numbers multiply to: " << ProdOfNums << "\n";
    

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    if (SumOfNums == GuessSum && ProdOfNums == GuessProduct) 
    {
        std::cout << "+++ You guessed correctly! Moving on to the next level...\n";
        return true;
    } 
    else 
    {
        std::cout << "--- Wrong code so you have to try this level again...\n\n";
        return false;
    }

    return true;
}



int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    
    while (LevelDifficulty <= MaxDifficulty) // Loop until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "+++ Congratulations, you won the game!";
    return 0;
}

