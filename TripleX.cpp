#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) 
{
    //Print welcome messages to the terminal
    std::cout << "\n##########################################################################\n";
    std::cout << "\nYou are a bomb defusal expert that has come across a bridge of coded bombs\non the way to your next location.\n";
    std::cout << "You have to carefully pick your way across the bridge supports, decoding\neach bomb as you go so that your company can cross the bridge safely.\n";
    std::cout << "\n##########################################################################\n";
    std::cout << "\nEnter the correct code to defuse this level " << Difficulty << " bomb...\n\n";
    std::cout <<  "       _______\n";
    std::cout <<  "      /  /  / ''..\n";
    std::cout <<  "     |~||~||~|     '.\n";
    std::cout <<  "     | || || |      : (~)T(~)\n";
    std::cout <<  "     | || || |      '. /   \\ \n";
    std::cout <<  "     =========        |  ._ | \n";
    std::cout <<  "     | || || |         \\ | / \n";
    std::cout <<  "     | || || |         /^^^\\ \n";
    std::cout <<  "     |_||_||_|\n";
    std::cout << "\n##########################################################################\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //declare variables and assigned numbers
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print sum and product to the terminal
    std::cout << std::endl;
    std::cout << " >> There are 3 numbers in the code\n";
    std::cout << " >> The codes add up to: " << CodeSum;
    std::cout << "\n >> The codes multiply to give: " << CodeProduct << std::endl;
    std::cout << "Please enter your numbers in this format: x x x";
    std::cout << "\n##########################################################################\n";
  
    //store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if players guess is correct
    if (GuessSum == CodeSum &&  GuessProduct == CodeProduct) 
    {
        std::cout << "##########################################################################\n";
        std::cout << "The bomb is defused! Well done. Time to move onto the next one...\n";
        std::cout << "          ▄▄        \n";
        std::cout << "         █  █        \n";
        std::cout << "         █  █        \n";
        std::cout << "        █   █        \n";
        std::cout << "       █    █        \n";
        std::cout << "███████▄▄█     ██████▄  \n";
        std::cout << "▓▓▓▓▓▓█              █ \n";
        std::cout << "▓▓▓▓▓▓█              █ \n";
        std::cout << "▓▓▓▓▓▓█              █ \n";
        std::cout << "▓▓▓▓▓▓█              █ \n";
        std::cout << "▓▓▓▓▓▓█              █ \n";
        std::cout << "▓▓▓▓▓█████         █  \n";
        std::cout << "██████▀    ▀▀██████▀    \n";
        std::cout << "##########################################################################\n";
        return true;
    }
    else 
    {
        std::cout << "##########################################################################\n";
        // std::cout << "BOOM! The bomb blew up in your hands! Game Over.\n";
        // std::cout << "     _.-^^---....,,--       \n";
        // std::cout << " _--                  --_  \n";
        // std::cout << "<                        >)\n";
        // std::cout << "|                         | \n";
        // std::cout << " \\._                   _./  \n";
        // std::cout << "    ```--. . , ; .--'''       \n";
        // std::cout << "          | |   |             \n";
        // std::cout << "       .-=||  | |=-.   \n";
        // std::cout << "       `-=#$%&%$#=-'   \n";
        // std::cout << "          | ;  :|     \n";
        // std::cout << "_____.,-#%&$@%#&#~,._____\n";
        std::cout << "\nCareful - That was the wrong code! Another one of those and the whole\n bridge could go up!"\n;
        std::cout << "\n##########################################################################\n";
        return false;
    }

}

int main()
{
    srand(time(NULL)); //creates new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << " >> Well done! You defused every bomb. The bridge is safe to cross!";
    return 0;
}